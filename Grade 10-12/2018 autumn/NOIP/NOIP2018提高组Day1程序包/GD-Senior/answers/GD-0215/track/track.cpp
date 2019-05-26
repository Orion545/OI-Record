#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=50005;

int read()
{
	int ret=0; char ch=getchar();
	while (!(ch>='0' && ch<='9')) ch=getchar();
	while (ch>='0' && ch<='9') ret=(ret<<3)+(ret<<1)+(ch-'0'),ch=getchar();
	return ret;
}

struct edges{
	int next,to,w;
} ed[maxn<<2];
int head[maxn],ip;
void add(int u,int v,int w)
{
	ed[++ip].next=head[u];
	ed[ip].to=v;
	ed[ip].w=w;
	head[u]=ip;
}

bool shilian;
int n,m,ans,lim,mx,mn;
int tp[maxn],tid[maxn],rak[maxn],dep[maxn],siz[maxn],son[maxn],fa[maxn],tim;
int sum[maxn];

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
			sum[v]=sum[u]+ed[i].w;
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
int lca(int x,int y)
{
	int fx=tp[x],fy=tp[y];
	while (fx!=fy)
	{
		if (dep[fx]>=dep[fy]) 
			x=fa[fx];
		else y=fa[fy];
		fx=tp[x],fy=tp[y];
	}
	if (tid[x]<tid[y]) return x;
	else return y;
}

void do_solve1()
{
	ans=0; 
	for (int i=1; i<n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			int rt=lca(i,j);
			ans=max(ans,sum[i]+sum[j]-sum[rt]*2);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	n=read(); m=read(); 
	int x,y,z;
	mx=-1e9; mn=1e9;
	for (int i=1; i<n; i++)
	{
		x=read(); y=read(); z=read();
		lim+=z;
		mx=max(mx,z); mn=min(mn,z);
		if (y!=x+1) shilian=false;
		add(x,y,z); add(y,x,z);
	}
	
	memset(son,-1,sizeof(son));
	dfs1(1,1,0);
	dfs2(1,1);
	
	if (m==1) 
	{
		do_solve1();
		return 0;
	}
	if (m==n-1)
	{
		printf("%d\n",mn);
		return 0;
	}

	printf("%d\n",mx);
	
	return 0;
}
