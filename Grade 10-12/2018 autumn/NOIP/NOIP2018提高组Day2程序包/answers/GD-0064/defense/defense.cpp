#include <iostream>
#include <cstdio>
#include <cstring>
#define repu(i, x, y) for (int i = x; i <= y; ++i)
#define goedge(u) for (int ei = head[u]; ei != 0; ei = edge[ei].nxt)
#define inf 0x3f3f3f3f
using namespace std;
const int MAXN = 100011;
struct Edge
{
	int u,v,nxt;
} edge[2 * MAXN];
int head[MAXN], ecnt;
void addEdge(int u, int v)
{
	edge[++ecnt] = (Edge){u,v,head[u]};
	head[u] = ecnt;
}
int w[MAXN];
int dp[MAXN][2]; int rule[MAXN]; //0 ok 1 N 2 Y
void treedp(int u, int fa)
{
	dp[u][1] = w[u];
	dp[u][0] = 0;
	goedge(u)
	{
		
		int v = edge[ei].v;
		if (v != fa)
		{
			treedp(v, u);
			dp[u][0] += dp[v][1];
			dp[u][1] += min(dp[v][0], dp[v][1]);
		}
	}
	if (rule[u] == 1) dp[u][1] = inf;
	else if (rule[u] == 2) dp[u][0] = inf;
}
int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int n, m, rt = 100011; char flag[10]; scanf("%d%d%s", &n, &m, flag);
	repu(i, 1, n) scanf("%d", &w[i]);
	repu(i, 1, n - 1)
	{
		int u,v; scanf("%d%d", &u, &v);
		addEdge(u, v); addEdge(v, u);
		rt = min(rt, min(u, v));
	}
	repu(i, 1, m)
	{
		int a, x, b, y;
		memset(dp, 0x3f, sizeof dp);
		scanf("%d%d%d%d", &a, &x, &b, &y);
		rule[a] = x + 1; rule[b] = y + 1;
		treedp(rt, 0);
		int ans = min(dp[rt][0], dp[rt][1]);
		if (ans >= inf) puts("-1");
		else printf("%d\n", ans);
		rule[a] = 0; rule[b] = 0;
	}
	return 0;
}
