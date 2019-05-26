#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int md=1e9+7;
int n,m,k,ans,f[310],g[310],x[310][310],y[310][310];
int tot,a[11][11],b[100010][11],c[11];
int cmp(int x,int y){
	for (int i=1;i<=k;++i)
		if (b[x][i]>b[y][i]) return 0;
		else if (b[x][i]<b[y][i]) return 1;
	return 1;
}
void check(){
	for (int i=1;i<tot;++i)
		if (!cmp(i,i+1)) return;
	++ans;
}
void dfs2(int pos,int x,int y){
	c[pos]=a[x][y];
	if (pos==k){
		++tot;
		for (int i=1;i<=k;++i) b[tot][i]=c[i];
		return;
	}
	if (y<m) dfs2(pos+1,x,y+1);
	if (x<n) dfs2(pos+1,x+1,y);
}
void dfs1(int x,int y){
	if (y>m) ++x,y=1;
	if (x>n) {tot=0,dfs2(1,1,1);check();return;}
	a[x][y]=0,dfs1(x,y+1),a[x][y]=1,dfs1(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m),k=1<<n;
	if (n*m<=16){k=n+m-1;
	dfs1(1,1);
	printf("%d\n",ans);return 0;
	}--m;
	for (int i=0;i<k;f[++i]=1)
		for (int j=0,flg=1;j<k;x[i+1][++j]=flg,flg=1)
			for (int l=1;l<n;flg&=((i&(1<<l-1))!=0)<=((j&(1<<l++))!=0));
	while (m){
		if (m&1){
			memset(g,0,sizeof(g));
			for (int i=1;i<=k;++i)
				for (int j=1;j<=k;g[i]=(g[i]+1ll*f[j]*x[j++][i])%md);
			for (int i=1;i<=k;f[i]=g[i++]);
		}
		memset(y,0,sizeof(y)),m>>=1;
		for (int i=1;i<=k;++i)
			for (int j=1;j<=k;++j)
				for (int l=1;l<=k;y[i][j]=(y[i][j]+1ll*x[i][l]*x[l++][j])%md);
		for (int i=1;i<=k;++i)
			for (int j=1;j<=k;x[i][j]=y[i][j++]);
	}
	for (int i=1;i<=k;ans=(ans+f[i++])%md);
	printf("%d\n",ans);
	return 0;
}
