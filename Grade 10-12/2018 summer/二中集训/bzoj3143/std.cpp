#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int maxn=510,maxm=300010;
const double eps=1e-10;
using namespace std;
typedef	double ld;
int pre[maxm],now[maxn],son[maxm],tot,deg[maxn],n,m,st[maxm],ed[maxm];ld a[maxn][maxn],f[maxn],g[maxm],ans;
void add(int x,int y){pre[++tot]=now[x],now[x]=tot,son[tot]=y,deg[x]++;}
 
void gauss(){
	for (int i=1;i<=n;i++){
		int id=i;ld maxs=-1.0;
		for (int j=i;j<=n;j++) if (fabs(a[j][i])+eps>maxs) id=j,maxs=fabs(a[j][i]);
		if (id!=i) for (int j=1;j<=n+1;j++) swap(a[i][j],a[id][j]);
		ld t=a[i][i];if (fabs(t)<eps) for (;;);
		for (int j=1;j<=n+1;j++) a[i][j]/=t; 
		for (int j=1;j<=n;j++)
			if (j!=i){
				ld t=a[j][i];
				for (int k=1;k<=n+1;k++)
					a[j][k]-=t*a[i][k];
			}
	}
	for (int i=1;i<=n;i++) f[i]=a[i][n+1],cout<<i<<' '<<f[i]<<'\n';
}
 
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x),st[i]=x,ed[i]=y;
	n--,a[1][n+1]=-1.0;
	for (int x=1;x<=n;x++){
		a[x][x]=-1.0;
		for (int y=now[x];y;y=pre[y])
			if (son[y]!=n+1)
				a[x][son[y]]=1.0/deg[son[y]];
	}
	gauss();
	for (int i=1;i<=m;i++) g[i]=f[st[i]]/deg[st[i]]+f[ed[i]]/deg[ed[i]];
	sort(g+1,g+1+m);
	for (int i=1;i<=m;i++) ans+=g[i]*(m-i+1);
	printf("%.3lf\n",(double)ans);
	return 0;
}

