#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
bool vis[8000],gg[8000];
int f[6000],s[6000];
struct node{
	int v,nxt;
}e[10010];
bool fh(int u,int fa)
{
	vis[u]=true;
	for (int i=f[u];i;i=e[i].nxt)
	 if (e[i].v!=fa&&s[u]+1>s[e[i].v])
		{
			if (vis[e[i].v]){gg[e[i].v]=true;return false;}
			if (!fh(e[i].v,u)) 
			 {
			 	gg[e[i].v]=true;
			 	if (gg[u]) return true; else return false;
			 }
		}
	return true;
}
int ans[6000],o=0;
void dfs1(int u,int fa)
{
	ans[++o]=u;
	for (int i=f[u];i;i=e[i].nxt)
	 if (fa!=e[i].v)
	  dfs1(e[i].v,u);
}
void dfs(int u,int fa);
void dfs2(int u,int fa,int k)
{
	if (vis[u]) return;
	vis[u]=true;
	ans[++o]=u;
	int l=0,r=0;
	for (int i=f[u];i;i=e[i].nxt)
	 if (fa!=e[i].v)
	  {
	  	if (l==0) l=e[i].v;else r=e[i].v;
	  }
	if (r!=0&&gg[l])
	 dfs(l,u),swap(l,r);
	if (l>k) return;
	dfs2(l,u,k);
}
bool fff=true;
void dfs(int u,int fa)
{
	if (vis[u]) return;
	vis[u]=true;
	ans[++o]=u;
	if (gg[u]&&fff)
	 {
	  fff=false;
	  int l=0,r=0;
	  for (int i=f[u];i;i=e[i].nxt)
		 if (fa!=e[i].v)
	 	 {
	  		if (l==0) l=e[i].v;else r=e[i].v;
	 	 }
	 	dfs2(l,u,r);
	 }
	for (int i=f[u];i;i=e[i].nxt)
	 if (fa!=e[i].v)
	  dfs(e[i].v,u);
}
struct nod1{
	int u,v;
}t[10010];
int cmp(nod1 a,nod1 b)
{
	if (a.u==b.u) return a.v>b.v;
	 else return a.u>b.u;
}
int en;
int add(int u,int v)
{
	en++;
	e[en].v=v;
	e[en].nxt=f[u];
	f[u]=en;
}
int n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
		scanf("%d%d",&t[i].u,&t[i].v);
	sort(t+1,t+m+1,cmp);
	for (int i=1;i<=m;++i)
		add(t[i].u,t[i].v),
		add(t[i].v,t[i].u);
	if (m==n-1)
	 {
	 	dfs1(1,0);
	 	for (int i=1;i<=n;++i)
	 	 printf("%d ",ans[i]);	 
	 	return 0;
	 } else
	 {
		fh(1,0);
		memset(vis,false,sizeof(vis));
		dfs(1,0);
		for (int i=1;i<=n;++i)
		 printf("%d ",ans[i]);
	 }
	 return 0;
}
