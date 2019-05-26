#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 1e3 + 5;
struct Edge {
	int v, nex;
	Edge() {}
	Edge(int _v, int _nex) : v(_v), nex(_nex) {}
} E[maxn << 1];
int head[maxn], tote;

void addEdge(int u, int v) { E[++tote] = Edge(v, head[u]), head[u] = tote; }

int n, m, g[maxn][maxn];

int ans[maxn], tmp[maxn], tot_tmp;
bool vis[maxn];
pair<int, int> e[maxn];

void dfs(int u, pair<int, int> e) {
	tmp[++tot_tmp] = u, vis[u] = true;
	for (int i = head[u]; ~i; i = E[i].nex) {
		int v = E[i].v;
		if (vis[v]) continue;
		int tu = min(u, v), tv = max(u, v);
		int eu = min(e.first, e.second), ev = max(e.first, e.second);
		if (eu == tu && ev == tv) continue;
		dfs(v, e);
	}
}
int main() {
	memset(head, -1, sizeof(head));
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
		e[i] = make_pair(u, v);
	}
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--) if (g[i][j]) addEdge(i, j);
	if (m == n - 1) {
		dfs(1, make_pair(0, 0));
		for (int i = 1; i <= n; i++) printf("%d ", tmp[i]);
	} else {
		ans[1] = 99999999;
		for (int i = 1; i <= m; i++) {
			tot_tmp = 0;
			for (int j = 1; j <= n; j++) vis[j] = false;
			dfs(1, e[i]);
			bool fl = false;
			if (tot_tmp < n) continue;
			for (int j = 1; j <= n; j++) if (tmp[j] != ans[j]) {
				fl = (tmp[j] < ans[j]);
				break;
			}
			if (fl) for (int j = 1; j <= tot_tmp; j++) ans[j] = tmp[j];
		}
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	}
	return 0;
}
