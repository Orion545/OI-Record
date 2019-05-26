#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid (l+r>>1)
using namespace std;
const int mxn=200010;
int k,a[mxn],b[mxn],ans;
int cnt(int n,int x){
	for (int i=1;i<x;++i) b[i]=a[i];
	for (int i=x+1;i<=n;++i) b[i-1]=a[i];
	for (int i=(n-=x!=n+1),cur=1;i;--i){
		for (;cur<i&&b[cur]+b[i]<k;++cur);
		if (cur++>=i) return n-i;
	}
}
int solve(int n){
	if (n<2) {ans=0;return n?a[1]:0;}
	sort(a+1,a+n+1),ans=cnt(n,n+1),a[0]=0;int l=1,r=n;
	while (l<=r)
		if (cnt(n,mid)<ans) r=mid-1;
		else l=mid+1;
	return a[r];
}
int M,n,m,x,y,z,head[mxn],f[mxn],g[mxn];
struct ed{int to,nxt,val;}edge[mxn<<1];
void addedge(int u,int v,int w){
	edge[++M]=(ed){v,head[u],w},head[u]=M;
	edge[++M]=(ed){u,head[v],w},head[v]=M;
}
void dfs(int u,int fa){
	int v,tot=0;f[u]=0;
	for (int i=head[u];i;i=edge[i].nxt)
		if ((v=edge[i].to)!=fa)	dfs(v,u),f[u]+=f[v];
	for (int i=head[u];i;i=edge[i].nxt)
		if ((v=edge[i].to)!=fa)
			if (g[v]+edge[i].val>=k) ++f[u];
			else a[++tot]=g[v]+edge[i].val;
	g[u]=solve(tot),f[u]+=ans;
}
int check(int x){k=x,dfs(1,1);return f[1]>=m;}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);int l=1,r=0;
	for (int i=1;i<n;++i)
		scanf("%d%d%d",&x,&y,&z),addedge(x,y,z),r+=z;
	while (l<=r)
		if (check(mid)) l=mid+1;
		else r=mid-1;
	printf("%d\n",r);
	return 0;
}
