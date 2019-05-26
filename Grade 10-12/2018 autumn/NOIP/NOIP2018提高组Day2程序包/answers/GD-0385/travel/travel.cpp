#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define edge(i, u) for (int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define N 5005
#define pb push_back
int n, m, u, v, head[N], tot, a[N], cnt, ans[N], fobi;
bool vis[N], p[N], flag;
std::vector<int> E[N];
using namespace std;
struct edge{
	int nxt, u, v;
}e[N << 1];
inline void addedge (int u, int v)
{
//	printf("(%d %d)\n", u, v);
	e[++tot] = (edge) {head[u], u, v};
	head[u] = tot;
}
inline void dfs (int u, int fa)
{
	int sz = E[u].size() - 1;
	a[++cnt] = u;
	fo (i, 0, sz)
	{
		int v = E[u][i];
		if (v == fa) continue;
		dfs(v, u);
	}
}
int dep[N], x, y, f[N];
inline void dfs1 (int u, int fa)
{
	f[u] = fa;
	edge (i, u)
	{
		if (v == fa) continue;
		if (dep[v]) {x = u; y = v; continue;}
		dep[v] = dep[u] + 1;
		dfs1(v, u);
	}
}
inline void lca (int u, int v)
{
	while (u != v)
	{
		if (dep[u] > dep[v]) std::swap(u, v);
		v = f[v];
		p[v] = 1;
	}
}
int fu, fv;
inline void dfs2 (int u, int fa)
{
	a[++cnt] = u;
//	printf("%d ", u);
	edge (i, u)
	{
//		printf("%d ", v);
		if (v == fa || min(e[i].u, e[i].v) == fu && max(e[i].u, e[i].v) == fv) continue;
		dfs2(v, u);
	}
}
int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", &n, &m);
	fo (i, 1, m)
	{
		scanf("%d %d", &u, &v);
		E[u].pb(v);
		E[v].pb(u);
	}
	fo (i, 1, n)
		std::sort(E[i].begin(), E[i].end());
	if (m == n - 1)
	{
		dfs(1, 0);
		cnt = 0;
		fo (i, 1, n)
			printf("%d ", a[i]);
	}
	else
	{
		fo (i, 1, n)
		{
			int sz = E[i].size() - 1;
			if (sz >= 0)
				for (int j = sz; j >= 0; --j)
					addedge(i, E[i][j]);
		}
		dep[1] = 1;
		dfs1(1, 0);
		p[x] = 1; p[y] = 1;
		lca(x, y);
		fo (i, 1, tot)
		{
			if (dep[e[i].v] > dep[e[i].u] && p[e[i].u] && p[e[i].v])
			{
				fu = e[i].u; fv = e[i].v;
				if (fu > fv) swap(fu, fv);
				cnt = 0;
				dfs2(1, 0);
				if (!flag)
				{
					fo (i, 1, n) ans[i] = a[i];
					flag = 1;
				}
				else
				{
					fo (i, 1, n)
						if (a[i] < ans[i])
						{
							fo (i, 1, n) ans[i] = a[i];
							break;
						}
						else
						if (a[i] > ans[i])
							break;
				}
			}
		}
		fo (i, 1, n)
			printf("%d ", ans[i]);
	}
	return 0;
}
