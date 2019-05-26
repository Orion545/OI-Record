#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100005;

struct data{
	int x,y;
} a[maxn<<2];

struct edges{
	int next,to;
} ed[maxn<<2];
int head[maxn],ip;
void add(int u,int v)
{
	ed[++ip].next=head[u];
	ed[ip].to=v;
	head[u]=ip;
}

int n,m;
char typ[5];
long long cst[maxn];

int dep[maxn],tid[maxn],rak[maxn],fa[maxn],son[maxn],siz[maxn],tim,tp[maxn];
bool vis[maxn];

void dfs1(int u,int father,int d)
{
	dep[u]=d;
	fa[u]=father;
	siz[u]=1;
	int v;
	for (int i=head[u]; i; i=ed[i].next)
	{
		v=ed[i].to;
		if (v!=father)
		{
			dfs1(v,u,d+1);
			siz[u]+=siz[v];
			if (son[u]==-1 || siz[v]>siz[son[u]])
				son[u]=v;
		}
	}
}
void dfs2(int u,int t)
{
	tp[u]=t;
	tid[u]=++tim;
	rak[tid[u]]=u;
	if (son[u]==-1) return;
	dfs2(son[u],t);
	int v;
	for (int i=head[u]; i; i=ed[i].next)
	{
		v=ed[i].to;
		if (v!=fa[u] && v!=son[u])
			dfs2(v,v);
	}
}

long long solve()
{
	for (int i=1; i<n; i++)
	{
		int x=a[i].x,y=a[i].y;
		if (!vis[x] && !vis[y])
		{
			if (cst[x]<cst[y])
			{
				vis[x]=true;
			}
			else vis[y]=true;
		}
	}
	long long ret=0;
	for (int i=1; i<=n; i++)
		if (vis[i]) ret+=cst[i];
	return ret;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",typ);
	for (int i=1; i<=n; i++)
		scanf("%lld",&cst[i]);
	int x,y;
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		a[i].x=x,a[i].y=y;
		add(x,y); 
		add(y,x);
	}
	
	memset(son,-1,sizeof(son));
	dfs1(1,1,0);
	dfs2(1,1);
	
	int cx,cy;
	while (m--)
	{
		scanf("%d%d%d%d",&x,&cx,&y,&cy);
		if (cx==0 && cy==0)
		{
			if (fa[x]==y || fa[y]==x) 
			{
				printf("-1\n");
				continue;
			}
		}
		int v;
		if (cx==0)
		{
			for (int i=head[x]; i; i=ed[i].next)
			{
				v=ed[i].to;
				vis[v]=true;
			}
		}
		else vis[x]=true;
		if (cy==0)
		{
			for (int i=head[y]; i; i=ed[i].next)
			{
				v=ed[i].to;
				vis[v]=true;
			}
		}
		else vis[y]=true;
		
		printf("%d\n",solve());
		
		memset(vis,false,sizeof(vis));
	}
		
	return 0;
}
