#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define N 5010
#define inf 10000
int read()
{
	int x = 0; char ch = getchar();
	for(;ch<'0'||ch>'9';ch = getchar());
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}
int x,y,n,m;
short adj[N][N],cnt[N],dep[N],fa[N];
bool vis[N],incir[N];
void add(int x,int y)
{
	adj[x][++cnt[x]] = y;
	adj[y][++cnt[y]] = x;
}
bool bo;
int dd;
void dfs(int u,int d)
{
	//cout<<u<<endl;
	if(u>d)
	{
		bo = true;
		return;
	}
	vis[u] = true;
	printf("%d ",u);
	sort(adj[u]+1,adj[u]+cnt[u]+1);
	for(int i=1,v;i<=cnt[u];i++)
		if(!vis[adj[u][i]])
		{
			v = adj[u][i];
			if(incir[u])
			{
				if(incir[v] && !bo) dfs(v,dd);
				else dfs(v,inf);
			}
			else dfs(v,inf);
		}
}
void find(int u,int pre)
{
	dep[u] = dep[pre] + 1; fa[u] = pre;
	for(int i=1,v;i<=cnt[u];i++)
	{
		v = adj[u][i];
		if(v == pre) continue;
		if(dep[u] < dep[v])
		{
			x = u; y = v;
			dd = v;
			for(int t=v;t!=fa[u];t=fa[t])
			{
				if(fa[t] == u) dd = max(dd,t);
				incir[t] = true;
			}
			continue;
		}
		else if(!dep[v]) find(v,u);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read(); m = read();
	for(int i=1;i<=m;i++) add(read(),read());
	if(m == n) find(1,0);
	dfs(1,inf);
	return 0;
}
