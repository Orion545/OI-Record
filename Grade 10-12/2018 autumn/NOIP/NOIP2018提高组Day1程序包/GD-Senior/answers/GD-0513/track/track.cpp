#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=50005;
int pp,lsy,yys,p,n,m,w[N],mn,last[N],cnt,du[N],root,ans,son[N][3],hjy[N][3];
int f[N][3],g[N][3];
struct data{int to,next,w;}e[N*2];
bool flag;
bool cmp(int a,int b){
	return a>b;
}

void add(int x,int y,int w){
	e[++cnt].to=y; e[cnt].next=last[x]; last[x]=cnt; e[cnt].w=w;
	e[++cnt].to=x; e[cnt].next=last[y]; last[y]=cnt; e[cnt].w=w;
}

bool dfs(int x,int fa,int y){
	int o=0;
	for (int i=last[x];i;i=e[i].next)
	if (e[i].to!=fa) dfs(e[i].to,x,y),son[x][++o]=e[i].to,hjy[x][o]=e[i].w;
	if (o==1){
		if (f[son[x][1]][1]>f[son[x][1]][2]) p=1;
								else p=2;
		if (g[son[x][1]][1]>g[son[x][1]][2]) p=1;
		if (g[son[x][1]][1]<g[son[x][1]][2]) p=2;
		g[x][2]=g[son[x][1]][p];
		f[x][2]=f[son[x][1]][p]+hjy[x][1];
		if (f[x][2]>=y){
			f[x][2]=0;
			g[x][2]++;
		}
	}
	if (o==2){
		for (int i=1;i<=2;i++)
		 for (int j=1;j<=2;j++)
		 if (g[son[x][1]][i]+g[son[x][2]][j]>=g[x][1]){
		 	g[x][1]=g[son[x][1]][i]+g[son[x][2]][j];
		 	int lsy=f[son[x][1]][i]+f[son[x][2]][j]+hjy[x][2]+hjy[x][1];
		 	if (lsy>y) g[x][1]++;
		 }
		for (int i=1;i<=2;i++)
		 for (int j=1;j<=2;j++)
		 {
		 	lsy=f[son[x][1]][i]+hjy[x][1];
		 	yys=f[son[x][2]][i]+hjy[x][2];
		 	pp=0;
		 	if (lsy>=y) pp++,lsy=0;
		 	if (yys>=y) pp++,yys=0;
		 	if (g[son[x][1]][i]+g[son[x][2]][j]+pp>=g[x][2]){
		 		f[x][2]=max(f[x][2],yys);
		 		f[x][2]=max(lsy,f[x][2]);
		 		g[x][2]=g[son[x][1]][i]+g[son[x][2]][j]+pp;
		 	}
		 }
	}
	int haha;
	if (!fa) haha=max(g[x][1],g[x][2]);
	if (haha<m&&!fa) return 0;
	return 1;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d%d",&u,&v,&w[i]);
		du[u]++,du[v]++;
		if (u!=1) flag=1;
		add(u,v,w[i]);
	}
	for (int i=1;i<=n;i++) if (du[i]<=2) root=i;
	if (!flag){
		sort(w+1,w+n,cmp);
		for (int i=1;i<=m;i++){
			if (m+i<=n) w[m-i+1]+=w[m+i];
		}
		mn=123456789;
		for (int i=1;i<=m;i++) mn=min(mn,w[i]);
		printf("%d\n",mn);
		return 0;
	}
	int l=0,r=123456789;
	while (l<=r){
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		int mid=(l+r)>>1;
		if (dfs(root,0,mid)) ans=mid,l=mid+1;
					else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
