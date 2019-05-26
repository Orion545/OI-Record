#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#define repu(i, x, y) for (int i = x; i <= y; ++i)
#define goedge(u) for (int ei = head[u]; ei != -1; ei = edge[ei].nxt)
using namespace std;
const int MAXN = 5011;
set<int> es[MAXN];
void addEdge(int u, int v)
{
	es[u].insert(v);
	es[v].insert(u);
}
void delEdge(int u, int v)
{
	es[u].erase(v);
	es[v].erase(u);
}
int n, m;
int tmp[MAXN], ans[MAXN], path[MAXN], acnt, pcnt, tcnt;
bool vis[MAXN];
void dfs(int u, int fa)
{
	tmp[++tcnt] = u;
	for (set<int>::iterator it = es[u].begin(); it != es[u].end(); it++)
	{
		int v = *it;
		if (v != fa) dfs(v, u);
	}
}
int dfs2(int u, int fa)
{
	path[++pcnt] = u;
	vis[u] = true;
	for (set<int>::iterator it = es[u].begin(); it != es[u].end(); it++)
	{
		int v = *it;
		if (v != fa)
		{
			if (vis[v])
			{
				repu(i, 1, pcnt)
				{
					if (path[i] == v) return i;
				}
			}
			else
			{
				int res = dfs2(v, u);
				if (res != -1) return res;
			}
		}
	}
	--pcnt;
	return -1;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m); int u, v;
	int rt = 5555;
	repu(i, 1, m)
	{
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		rt = min(rt, min(u, v));
	}
	if (m == n)
	{
		int s = dfs2(rt, 0);
		repu(i, 1, n) ans[i] = 0x7fffffff;
		repu(i, s, pcnt - 1)
		{
			delEdge(path[i], path[i + 1]);
			memset(tmp, 0, sizeof tmp);
			tcnt = 0;
			dfs(rt, 0);
			bool ok = false;
			repu(j, 1, n)
			{
				if (tmp[j] < ans[j]) { ok = true; break; }
				else if (tmp[j] > ans[j]) break;
			}
			if (ok)
			{
				repu(j, 1, n) ans[j] = tmp[j];
			}
			addEdge(path[i], path[i + 1]);
		}
		repu(i, 1, n) printf("%d ", ans[i]);
	}
	else
	{
		dfs(rt, 0);
		repu(i, 1, n) printf("%d ", tmp[i]);
	}
	return 0;
}
