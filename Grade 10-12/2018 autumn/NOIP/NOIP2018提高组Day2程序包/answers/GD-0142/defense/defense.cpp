#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#define LL long long
#define fo(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct edge
{
	int v,p;
	edge(int _v=0,int _p=0)
	{
		v=_v;
		p=_p;
	}
}e[200010];
int n,m,head[100010],top,f[100010];
LL d[100010][2],a[100010][2];
string str;
void addedge(int u,int v)
{
	e[++top]=edge(v,head[u]);
	head[u]=top;
	e[++top]=edge(u,head[v]);
	head[v]=top;
}
inline bool update(int u)
{
	LL o0=d[u][0],o1=d[u][1];
	d[u][1]=a[u][1];
	d[u][0]=a[u][0];
	for(int i=head[u];i;i=e[i].p)
	{
		int v=e[i].v;
		if(v==f[u])continue;
		d[u][0]+=d[v][1];
		d[u][1]+=min(d[v][0],d[v][1]);
	}	
	return o0==d[u][0]&&o1==d[u][1];
}
void dfs(int u,int fa)
{
	f[u]=fa;
	for(int i=head[u];i;i=e[i].p)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
	}
	update(u);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>str;	
	for(int i=1;i<=n;i++)
	{
		a[i][1]=read();
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		addedge(u,v);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int ta=read(),x=read(),tb=read(),y=read();
		LL oa=a[ta][x^1],ob=a[tb][y^1];
		a[ta][x^1]=1e18;
		for(int i=ta;i;i=f[i])
		{
			if(update(i))break;
		}
		a[tb][y^1]=1e18;
		for(int i=tb;i;i=f[i])
		{
			if(update(i))break;
		}
		printf("%lld\n",min(d[1][0],d[1][1])>1e9?-1:min(d[1][0],d[1][1]));
		a[ta][x^1]=oa;
		for(int i=ta;i;i=f[i])
		{
			if(update(i))break;
		}
		a[tb][y^1]=ob;
		for(int i=tb;i;i=f[i])
		{
			if(update(i))break;
		}
	}
	return 0;
}
