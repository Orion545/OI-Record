#include<cstdio>
#include<cstring>
#include<algorithm>

const int maxn = 50005;
struct Edges
{
	int next, to, weight, used;
} e[maxn << 1];
int head[maxn], tot;
int dp[maxn];
int pre[maxn];

int n, m;
int read()
{
	int ans = 0, s = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){ if(ch == '-') s = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return s * ans;
}
void link(int u, int v, int w)
{
	e[++tot] = (Edges){head[u], v, w, 0};
	head[u] = tot;
}
void dfs(int u, int f)
{
	for(int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == f) continue;
		dfs(v, u);
		dp[u] = std::max(dp[u], e[i].weight + dp[v]);
	}
}
void solve1()
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		memset(dp, 0, sizeof dp);
		dfs(i, 0);
		ans = std::max(ans, dp[i]);
	}
	printf("%d\n", ans);
}
void solve2()
{
	memset(pre, 0, sizeof pre);
	for(int u = 1; u <= n; u++)
	{
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if(v == u + 1)
			{
				pre[i] = pre[i - 1] + e[i].weight;
			}
		}
	}
	printf("%d\n", pre[n / 2]);
}
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i < n; i++)
	{
		int u = read(), v = read(), w = read();
		link(u, v, w); link(v, u, w);
	}
	if(m == 1)
	{
		solve1();
	}
	else
	{
		solve2();
	}
	return 0;
}
