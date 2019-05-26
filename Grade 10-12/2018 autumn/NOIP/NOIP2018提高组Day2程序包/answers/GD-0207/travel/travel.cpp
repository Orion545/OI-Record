#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mxn 10010
using namespace std;
int n,m,k,flg,head[mxn],ans[mxn],a[mxn],fa[mxn],w[5010][5010];
struct e{int x,y;}edg[mxn<<1];
int cmp(const e &x,const e &y){return x.y>y.y;}
struct ed{int to,nxt;}edge[mxn<<1];
void addedge(int u,int v){edge[++m]=(ed){v,head[u]};head[u]=m;}
void solve_tree(int u,int f){
	ans[++*ans]=u;int v;
	for (int i=head[u];i;i=edge[i].nxt)
		if ((v=edge[i].to)!=f&&!w[u][v]) solve_tree(v,u);
}
void dfs(int u,int f){
	fa[u]=f;int v;
	for (int i=head[u];i&&!flg;i=edge[i].nxt)
		if ((v=edge[i].to)!=f)
			if (fa[v]) fa[v]=flg=u;
			else dfs(v,u);
}
int cmq(){
	for (int i=1;i<=n;++i)
		if (a[i]>ans[i]) return 1;
		else if (a[i]<ans[i]) return 0;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;++i)
		scanf("%d%d",&edg[i].x,&edg[i].y),
		edg[k+i].x=edg[i].y,edg[k+i].y=edg[i].x;
	sort(edg+1,edg+2*k+1,cmp);
	for (int i=1;i<=k<<1;++i) addedge(edg[i].x,edg[i].y);
	if (k<n){
		solve_tree(1,1);
		for (int i=1;i<=n;++i) printf("%d ",ans[i]);
		puts("");return 0;
	}
	else{
		dfs(1,1);
		w[flg][fa[flg]]=w[fa[flg]][flg]=1,*ans=0,solve_tree(1,1),w[flg][fa[flg]]=w[fa[flg]][flg]=0;
		for (int i=1;i<=n;++i) a[i]=ans[i];
		for (int i=fa[flg];i!=flg;i=fa[i]){
			w[i][fa[i]]=w[fa[i]][i]=1,*ans=0,solve_tree(1,1),w[i][fa[i]]=w[fa[i]][i]=0;
			if (cmq()) for (int i=1;i<=n;++i) a[i]=ans[i];
		}
		for (int i=1;i<=n;++i) printf("%d ",a[i]);
		puts("");return 0;
	}
}
