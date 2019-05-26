#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=100100;
const long long oo=1e15;
typedef long long LL;

struct edge
{
	int obj;
	edge *Next;
} e[maxn];
edge *head[maxn];
int cur=-1;

int fa[maxn];
bool vis[maxn];
int val[maxn];

LL f[maxn];
LL g[maxn];

LL rf[maxn];
LL rg[maxn];

char s[10];
int n,m;

void Add(int x,int y)
{
	cur++;
	e[cur].obj=y;
	e[cur].Next=head[x];
	head[x]=e+cur;
}

void Dfs(int node)
{
	for (edge *p=head[node]; p; p=p->Next)
	{
		int son=p->obj;
		if (son==fa[node]) continue;
		fa[son]=node;
		Dfs(son);
	}
}

void Work(int node)
{
	vis[node]=1;
	f[node]=val[node];
	g[node]=0;
	for (edge *p=head[node]; p; p=p->Next)
	{
		int son=p->obj;
		if ( son==fa[node]) continue;
		if (!vis[son])Work(son);
		f[node]+=min(f[son],g[son]);
		g[node]+=f[son];
	}
}

void Solve1()
{
	for (int i=1; i<=m; i++)
	{
		int u,a,v,b;
		scanf("%d%d%d%d",&u,&a,&v,&b);
		fa[u]=0;
		Dfs(u);
		
		for (int j=1; j<=n; j++) vis[j]=0;
		Work(v);
		if (b==0) f[v]=oo;
		else g[v]=oo;
		v=fa[v];
		while (v!=fa[u]) Work(v),v=fa[v];
		
		LL ans;
		if (a==0) ans=g[u];
		else ans=f[u];
		if (ans>=oo) ans=-1;
		printf("%lld\n",ans);
	}
}

void Solve2()
{
	Dfs(1);
	Work(1);
	
	for (int i=1; i<=m; i++)
	{
		int u,a,v,b;
		scanf("%d%d%d%d",&u,&a,&v,&b);
		
		int x=fa[v],y=v;
		while (x)
		{
			f[x]-=min(f[y],g[y]);
			g[x]-=f[y];
			
			y=x;
			x=fa[y];
		}
		
		LL temp;
		if (b==0) temp=f[v],f[v]=oo;
		else temp=g[v],g[v]=oo;
		
		x=fa[v],y=v;
		while (x)
		{
			f[x]+=min(f[y],g[y]);
			g[x]+=f[y];
			
			y=x;
			x=fa[y];
		}
		
		printf("%lld\n",f[1]);
		
		x=fa[v],y=v;
		while (x)
		{
			f[x]-=min(f[y],g[y]);
			g[x]-=f[y];
			
			y=x;
			x=fa[y];
		}
		
		if (b==0) f[v]=temp;
		else g[v]=temp;
		
		x=fa[v],y=v;
		while (x)
		{
			f[x]+=min(f[y],g[y]);
			g[x]+=f[y];
			
			y=x;
			x=fa[y];
		}
	}
}

void Re(int node)
{
	if (node==1) rf[node]=rg[node]=0;
	else
	{
		rg[node]=rf[ fa[node] ]+f[ fa[node] ]-min(f[node],g[node]);
	rf[node]=min(rg[node],rg[ fa[node] ]+g[ fa[node] ]-f[node]);
	}
	
	for (edge *p=head[node]; p; p=p->Next)
	{
		int son=p->obj;
		if (son==fa[node]) continue;
		Re(son);
	}
}

void Solve3()
{
	Dfs(1);
	Work(1);
	Re(1);
	for (int i=1; i<=m; i++)
	{
		int u,a,v,b;
		scanf("%d%d%d%d",&u,&a,&v,&b);
		
		if (u!=fa[v]) swap(u,v);
		if (a==0 && b==0) printf("-1\n");
		else{
			int vu=rf[u];
			if (a==0) vu=rg[u];
			int vv=f[v];
			if (b==0) vv=g[v];
			printf("%lld\n",vu+vv);
		}
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=1; i<=n; i++) scanf("%d",&val[i]);
	for (int i=1; i<n; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	
	if ( n<=8000 && m<=8000 ) Solve1();
	else
		if ( s[0]=='B' ) Solve2();
		else Solve3();
	
	return 0;
}



























