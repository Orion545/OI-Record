#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 100007, INF = (1 << 30);
int min(int a, int b) { return a < b ? a : b; }

char str[10];
int n, m, a, x, b, y, p[N], f[N][2];
int tot, st[N], to[N << 1], nx[N << 1];
void add(int u, int v) { to[++tot] = v, nx[tot] = st[u], st[u] = tot; }

void dfs(int u, int from)
{
	f[u][0] = 0, f[u][1] = p[u];
	if (u == a) f[u][!x] = INF;
	if (u == b) f[u][!y] = INF;
	for (int i = st[u]; i; i = nx[i])
		if (to[i] != from)
		{
			dfs(to[i], u);
			f[u][0] += f[to[i]][1], f[u][1] += min(f[to[i]][0], f[to[i]][1]);
		}
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);

	scanf("%d%d%*s", &n, &m, str);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u);
	while (m--)
	{
		scanf("%d%d%d%d", &a, &x, &b, &y);
		memset(f, 0, sizeof(f));
		dfs(1, 0);
		if (min(f[1][0], f[1][1]) >= INF) printf("-1\n");
		else printf("%d\n", min(f[1][0], f[1][1]));
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
