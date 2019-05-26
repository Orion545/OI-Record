#include <algorithm>
#include <cstdio>
using std::min;

const int INF  = 0x1FFFFFFF;
const int MAXN = 100010;

struct EDGE { int v; EDGE *n; } edge[MAXN*2], *head[MAXN];
int n, m, ce, bd[2][2], f[MAXN][2], p[MAXN], ans;
// 0: off, 1: on

void AddEdge(const int u, const int v) {
	edge[ce].v = v;
	edge[ce].n = head[u];
	head[u] = edge + ce;
	ce ++;
}

void dfs(const int u, const int fa) {
	// bool has_son = false;
	f[u][0] = 0;
	f[u][1] = p[u];
	for (EDGE *e=head[u]; e; e=e->n) {
		if (e->v == fa)
			continue;
		dfs(e->v, u);
		// has_son = true;

		f[u][0] += f[e->v][1];
		f[u][1] += min(f[e->v][0], f[e->v][1]);
		// f[u][0] += min(min(f[e->v][0], f[e->v][1]), f[e->v][2]);
		// f[u][1] += min(f[e->v][0], f[e->v][2]);
		// f[u][2] += f[e->v][0];
		for (int i=0; i<2; i++)
			if (f[u][i] > INF)
				f[u][i] = INF;
	}
	// if (!has_son)
	// 	f[u][2] = INF;

	if (u == bd[0][0] || u == bd[1][0]) {
		int x = u == bd[0][0] ? 0 : 1;
		if (bd[x][1])
			f[u][0] = INF;
		else
			f[u][1] = INF;
	}
	// printf("[%d] %d %d\n", u, f[u][0], f[u][1]);
}

int main() {
	freopen("defense.in" , "r", stdin );
	freopen("defense.out", "w", stdout);

	scanf("%d %d %*s", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &p[i]);
	for (int i=1, u, v; i<n; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	while (m --) {
		scanf("%d %d %d %d", &bd[0][0], &bd[0][1], &bd[1][0], &bd[1][1]);

		dfs(1, 1);
		ans = min(f[1][0], f[1][1]);

		printf("%d\n", ans >= INF ? -1 : ans);
	}

	return 0;
}
