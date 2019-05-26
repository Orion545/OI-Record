#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define edge(i, u) for (int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define N 5005
#define pb push_back
#define ll long long
#define mod 1000000007
#define inf 1000000007
int n, m, opt, p[N], dp[N][2], a, x, b, y, in[N], head[N];
char ch;
int tot;
struct edge{
	int nxt, v;
}e[N << 1];
inline void addedge (int u, int v)
{
	e[++tot] = (edge) {head[u], v};
	head[u] = tot;
}
inline void dfs (int u, int fa)
{
	if (u != a && u != b)
		dp[u][0] = 0, dp[u][1] = p[u];
	edge (i, u)
	{
		if (v == fa) continue;
		dfs(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += std::min(dp[v][0], dp[v][1]);
	}
}
int main ()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d %d", &n, &m);
	ch = getchar();
	while (ch != 'A' && ch != 'B' && ch != 'C') ch = getchar();
	scanf("%d", &opt);
	fo (i, 1, n)
		scanf("%d", &p[i]);
	fo (i, 2, n)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		++in[u]; ++in[v];
		addedge(u, v);
		addedge(v, u);
	}
	fo (i, 1, m)
	{
		scanf("%d %d %d %d", &a, &x, &b, &y);
		if (x) dp[a][1] = p[a], dp[a][0] = inf;
		else dp[a][0] = 0, dp[a][1] = inf;
		
		if (y) dp[b][1] = p[b], dp[b][0] = inf;
		else dp[b][0] = 0, dp[b][1] = inf;
		dfs(1, 0);
		int ans = std::min(dp[1][0], dp[1][1]);
		if (ans < inf)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}
