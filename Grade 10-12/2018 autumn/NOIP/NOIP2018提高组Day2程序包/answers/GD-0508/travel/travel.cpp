#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<ctime>
#include<cstdlib> 
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=5005;
int vis[N];
int n,m,tot,ans[N];
int head[N*3],next[N*3],go[N*3],bz[N],fa[N];
int f[N][N];
int a[N][N];
inline void add(int x,int y)
{
	go[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
inline void dfs(int x)
{
	
	if (!vis[x])ans[++ans[0]]=x;
	if (ans[0]==n)return;
//	printf("%d\n",ans[0]);
	vis[x]=1;
	fo(i,1,n)
	{
		if (i==x)continue;
		if (f[x][i]&&!vis[i])dfs(i);
	}
}
inline void dfs1(int x)
{
	vis[x]=1;ans[++ans[0]]=x;
	if (ans[0]==n)return;
	a[x][0]=a[fa[x]][0];
	fo(i,1,a[fa[x]][0])a[x][i]=a[fa[x]][i];
	for(int i=head[x];i;i=next[i])
	{
		int v=go[i];
		if (!vis[v]&&!bz[v])a[x][++a[x][0]]=v,bz[v]=1;
	}
	int mn=n+1,id=-1;
	fo(i,1,a[x][0])
	if (a[x][i]!=0)
	{
		if (mn>a[x][i])mn=a[x][i],id=i;
	}
	a[x][id]=0;
	dfs1(mn);
}
inline void dfs2(int x,int last)
{
	vis[x]=1;fa[x]=last;
	fo(i,1,n)
	{
		if (i==x)continue;
		if (f[x][i]&&!vis[i])dfs2(i,x);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]=f[y][x]=1;
		add(x,y),add(y,x);
	}
	if (m==n)
	{
		dfs2(1,0);
		fo(i,1,n)vis[i]=0;
		dfs1(1);
		fo(i,1,ans[0])printf("%d ",ans[i]);
		printf("\n");
		return 0;
	}
	dfs(1);
	//printf("%d\n",ans[0]);
	fo(i,1,ans[0])printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
