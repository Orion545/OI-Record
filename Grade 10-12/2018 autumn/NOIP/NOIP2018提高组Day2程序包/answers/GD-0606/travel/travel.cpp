#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int N=5100;
const int oo=2147400000;
const int mod=1e9+7;
#define pr(p) printf("%d ",p)
inline void sc (int &x)
{
	x=0; static int p; p=1; static char c; c=getchar();
	while (!isdigit(c)) { if (c=='-') p=-1;  c=getchar(); }
	while ( isdigit(c)) { x=(x<<3)+(x<<1)+(c-48);  c=getchar(); }
	x*=p;
}
int e[N][N];
int dfn[N],tim=0,sta[N],col[N]; bool fg=0;
void find (int u,int fa)
{
	if (fg) return ;
	dfn[u]=++tim,sta[++sta[0]]=u;
	for (int i=1; i<=e[u][0]; i++)
	{
		if (fg) return ;
		int v=e[u][i];
		if (v==fa) continue;
		if (dfn[v])
		{
			int x;
			while ((x=sta[sta[0]]))
			{
				col[x]=1;
				--sta[0];
				if (x==v) break;
			}
			fg=1;
			return ;
		}
		find (v,u);
	}
}
int ans[N]; bool vis[N];
int rt=0,fir,sec=oo;
void dfs (int u,int fa)
{
	if (rt&&col[u]&&u!=rt&&u> sec) { sec=oo; return ; }
	ans[++ans[0]]=u,vis[u]=1;
	if (col[u]&&!rt)
	{
		rt=u;
		for (int i=1; i<=e[u][0]; i++)
		{
			int v=e[u][i];
			if (v==fa||!col[v]) continue;
			if (!fir) fir=1;
			else { sec=v; break; }
		}
	}
	for (int i=1; i<=e[u][0]; i++)
	{
		int v=e[u][i];
		if (v==fa||vis[v]) continue;
		dfs (v,u);
	}
}
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int n,m; sc(n),sc(m);
	for (int i=1; i<=m; i++)
	{
		int u,v; sc(u),sc(v);
		e[u][++e[u][0]]=v,e[v][++e[v][0]]=u;
	}
	for (int i=1; i<=n; i++)
		sort (e[i]+1,e[i]+e[i][0]+1);
	find (1,0);
	dfs (1,0);
	for (int i=1; i<=n; i++)
		pr(ans[i]);
	return 0;
}
