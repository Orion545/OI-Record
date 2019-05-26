#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define edge(i, u) for (int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define N 50005
#define inf 1000000007
int n, m, head[N], tot, a[N];
struct edge{
	int nxt, v, w;
}e[N << 1];
inline void addedge (int u, int v, int w)
{
	e[++tot] = (edge) {head[u], v, w};
	head[u] = tot;
}
namespace solvem1
{
	int dis[N];
	void dfs (int u, int fa)
	{
		edge(i, u)
		{
			if (v == fa) continue;
			dis[v] = dis[u] + e[i].w;
			dfs(v, u);
		}
	}
	void work ()
	{
		memset(dis, 0x3f, sizeof dis);
		dis[1] = 0;
		dfs(1, 0);
		int now = 1;
		fo (i, 2, n)
			if (dis[now] < dis[i]) now = i;
		memset(dis, 0x3f, sizeof dis);
		dis[now] = 0;
		dfs(now, 0);
		int ans = 0;
		fo (i, 1, n)
			if (dis[i] > ans) ans = dis[i];
		printf("%d\n", ans);
	}
}
namespace solvea1
{
	bool check (int x)
	{
		int ret = m;
		int l = 1, r = n - 1;
		while (ret && a[r] >= x) {--ret; --r;}
		while (ret && l < r)
		{
			while (l < r && a[l] + a[r] < x) ++l;
			if (l < r)
			{
				++l; --r;
				--ret;
			}
		}
		return (ret == 0);
	}
	void work ()
	{
		std::sort(a + 1, a + n);
		int l = 1, r = 20000;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (check(mid)) l = mid;
				else r = mid - 1;
		}
		printf("%d\n", l);
	}
}
namespace solvelm
{
	int calc (int x)
	{
		int ret = 0, now = 0; 
		fo (i, 1, n)
		{
			now = now + a[i];
			if (now >= x)
			{
				++ret;
				now = 0;
			}
		}
		return ret;
	}
	void work ()
	{
		int l = 1, r = 500000005;
		--n;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (calc(mid) < m)
				r = mid - 1;
			else
				l = mid;
		}
		printf("%d\n", l);
	}
}
int f[N], mid, c1, c2, m1, m2;
struct node{
	int d, u;
	friend bool operator < (node x, node y)
	{
		return x.d < y.d;
	}
}t1[N], t2[N];
inline void dfs1 (int u, int fa, int dis)
{
	t2[++c2].d = dis;
	edge (i, u)
	{
		if (v == fa) continue;
		dfs1(v, u, dis + e[i].w);
	}
}
inline void dfs (int u, int fa)
{
	edge (i, u)
	{
		if (v == fa) continue;
		dfs(v, u);
	}
	c1 = 0;
	edge (I, u)
	{
		if (v == fa) continue;
		c2 = 0;
		dfs1(v, u, e[I].w);
		std::sort(t1 + 1, t1 + c1 + 1);
		std::sort(t2 + 1, t2 + c2 + 1);
		int l = 1, r = c2;
		m1 = f[t1[1].u]; m2 = f[t2[1].u];
		while (r && t2[r].d >= mid) 
		{
			f[u] = std::max(f[u], f[t2[r].u] + 1);
			m2 = std::max(m2, f[t2[r].u]);
			--r;
		}
		while (l <= c1 && r)
		{
			while (t1[l].d + t2[r].d < mid)
			{
				++l;
				m1 = std::max(m1, f[t1[l].u]);
			}
			f[u] = std::max(f[u], m1 + m2 + 1);
			--r;
			m2 = std::max(m2, f[t2[r].u]);
		}
		fo (i, 1, c2)//merge
			t1[c1 + i] = t2[i];
	}
}
inline void work ()
{
	int l = 1, r = 500000005;
	while (l < r)
	{
		mid = l + r >> 1;
		dfs(1, 0);
		if (f[1] < m)
			r = mid - 1;
		else
			l = mid;
	}
	printf("%d\n", l);
}
int main ()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	bool fl1 = 1, fl2 = 1;
	fo (i, 2, n)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
		a[i - 1] = w;
		if (u != 1) fl1 = 0;
		if (v != u + 1) fl2 = 0;
	}
	if (m == 1)
	{
		solvem1::work();
	}
	else
	if (fl1)
	{
		solvea1::work();
	}
	else
	if (fl2)
	{
		solvelm::work();
	}
	else
	if (m == n - 1)
	{
		int ans = inf;
		fo (i, 1, n - 1)
			ans = std::min(ans, a[i]);
		printf("%d\n", ans);
	}
	else
	{
		work();
	}
	return 0;
}
