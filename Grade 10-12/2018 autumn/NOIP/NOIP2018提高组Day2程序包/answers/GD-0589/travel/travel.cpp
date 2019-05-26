#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int getint()
{
	register int r=0,f=1;
	register char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-f:f,c=getchar();
	while (isdigit(c))
		r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*f;
}
const int N=5e3+10,M=5e3+10,INF=0x7fffffff;
int n,m;
int g[N][N],a[N];
bool vis[N],ring[N];
int dfn[N],low[N],idx;
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++idx;
	for (int v=1;v<=n;v++)
		if (g[u][v])
		{
			if (!dfn[v])
			{
				tarjan(v,u),low[u]=min(low[u],low[v]);
				if (low[v]<=dfn[u])
					ring[u]=1;
			}
			else
				if (v!=fa)
					low[u]=min(low[u],dfn[v]),ring[u]=1;
		}
}
int tmp,top;
void dfs(int u)
{
	a[++top]=u;
	if (top==n)
	{
		for (int i=1;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",u);
		fclose(stdin);
		fclose(stdout);
		exit(0);
	}
	int x=INF,y=INF,z=0,tt=0;
	if (ring[u])
	{
		for (int v=n;v>=1;v--)
			if (g[u][v]&&!vis[v]&&ring[v])
				x=v,tt++;
		for (int v=n;v>=1;v--)
			if (g[u][v]&&!vis[v]&&ring[v])
			{
				y=v;
				break;
			}
		for (int v=n;v>=1;v--)
			if (g[u][v]&&!vis[v]&&!ring[v])
			{
				z=v;
				break;
			}
		if (tt==2)
			tmp=y;
		if (tmp>z&&x<z)
		{
			for (int v=1;v<=n;v++)
				if ((g[u][v]&&!vis[v]&&!ring[v])||v==x)
					vis[v]=1,dfs(v);
		}
		if (tmp>z&&x>z)
		{
			for (int v=1;v<=n;v++)
				if (g[u][v]&&!vis[v]&&!ring[v])
					vis[v]=1,dfs(v);
			int fuck=tmp;
			if (tmp<x)
				tmp=INF;
			if (fuck!=INF||x!=INF)
				vis[min(fuck,x)]=1,dfs(min(fuck,x));
		}
		if (tmp<z&&x>z)
		{
			for (int v=1;v<=n;v++)
				if (g[u][v]&&!vis[v]&&!ring[v])
					vis[v]=1,dfs(v);
			int fuck=tmp;
			tmp=INF,vis[fuck]=1,dfs(fuck);
		}
		if (tmp<z&&x<z)
		{
			for (int v=1;v<=n;v++)
				if ((g[u][v]&&!vis[v]&&!ring[v])||v==x)
					vis[v]=1,dfs(v);
		}
	}
	else
	{
		for (int v=1;v<=n;v++)
			if (g[u][v]&&!vis[v])
				vis[v]=1,dfs(v);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=getint(),m=getint();
	int u,v;
	for (int i=1;i<=m;i++)
		u=getint(),v=getint(),g[u][v]=g[v][u]=1;
	tarjan(1,0);
	vis[1]=1,dfs(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
