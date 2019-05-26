#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

const int maxn = 100005;
struct Edges
{
	int next, to;
} e[maxn << 1];
int head[maxn], tot;
int fa[maxn], dep[maxn];
int w[maxn];
int n, m;
char opt[5];
int cnt;
bool vis[maxn];
struct cmp
{
	bool operator () (const int &a, const int &b) const
	{
		return dep[a] < dep[b];
	}
};

void dfs(int u, int f)
{
	dep[u] = dep[f] + 1; fa[u] = f;
	for(int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == f) continue;
		dfs(v, u);
	}
}
void dfs2(int u, int f, int dis)
{
	if(!vis[u])
	{
		vis[u] = true;
		cnt++;
	}
	if(dis == 1) return;
	for(int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if(v == f) continue;
		dfs2(v, u, dis + 1);
	}
}
void solve(int a, int x, int b, int y)
{
	cnt = 0;
	memset(vis, false, sizeof vis);
	int ans = 0;
	if(x == 1)
	{
		dfs2(a, 0, 0);
		ans += w[a];
	}
	if(y == 1)
	{
		dfs2(b, 0, 0);
		ans += w[b];
	}
	std::priority_queue<int, std::vector<int>, cmp> q;
	for(int i = 1; i <= n; i++) q.push(i);
	
	while(!q.empty())
	{
		int u;
		while(!q.empty() && vis[u = q.top()]) q.pop();
		if(q.empty()) break;
		if(u == a && x == 0)
		{
			q.pop();
			continue;
		}
		if(u == b && y == 0)
		{
			q.pop();
			continue;
		}
		if(!((fa[u] == a && x == 0) || (fa[u] == b && y == 0)) && fa[u]) u = fa[u];
		ans += w[u];
		dfs2(u, 0, 0);
	}
	if(cnt == n) printf("%d\n", ans);
	else printf("-1\n");
}
void baoli()
{
	dfs(1, 0);
	while(m--)
	{
		int a, x, b, y; scanf("%d%d%d%d", &a, &x, &b, &y);
		solve(a, x, b, y);
	}
}
void link(int u, int v)
{
	e[++tot] = (Edges){head[u], v};
	head[u] = tot;
}
int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	scanf("%d%d%s", &n, &m, opt);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		link(u, v); link(v, u);
	}
	baoli();
	return 0;
}
