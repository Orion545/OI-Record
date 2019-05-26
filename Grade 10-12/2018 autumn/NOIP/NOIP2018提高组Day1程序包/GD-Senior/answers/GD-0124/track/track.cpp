#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL long long

using namespace std;

int read() {
	int t = 0; char ch = getchar();
	while ('0' > ch || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') 
		t = (t << 3) + (t << 1) + ch - '0',
		ch = getchar();
	return t;
}


const int maxn = 5e4 + 5;

int head[maxn], tote;
struct Edge {
	int v, nex; LL w;
	Edge() {}
	Edge(int _v, LL _w, int _nex) : v(_v), w(_w), nex(_nex) {}
} E[maxn << 1];

void addEdge(int u, int v, int w) {
	E[++tote] = Edge(v, w, head[u]), head[u] = tote;
	E[++tote] = Edge(u, w, head[v]), head[v] = tote;
}
int n, m, fa[maxn][20], dis[maxn][20], dep[maxn];

void dfs(int u, int fat, LL w) {
	fa[u][0] = fat, dis[u][0] = w;
	for (int i = 1; i <= 18; i++) {
		if (!fa[u][i - 1]) break;
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
		dis[u][i] = dis[u][i - 1] + dis[fa[u][i - 1]][i - 1];
	}
	for (int i = head[u]; ~i; i = E[i].nex) {
		int v = E[i].v;
		if (v == fat) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u, E[i].w);
	}
}

LL lca(int u, int v) {
	LL ret = 0; 
	if (dep[u] < dep[v]) swap(u, v);
	int sub = dep[u] - dep[v];
	for (int i = 18; i >= 0; i--) {
		if (!fa[u][i]) continue;
		if (sub & (1 << i)) ret += dis[u][i], u = fa[u][i];
	}
	if (u == v) return ret;
	for (int i = 18; i >= 0; i--) {
		if (fa[u][i] == fa[v][i]) continue;
		ret += dis[u][i] + dis[v][i], u = fa[u][i], v = fa[v][i];
	}
	return ret + dis[u][0] + dis[v][0];
}

int main() {
	memset(head, -1, sizeof(head));
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	LL l = 0, r = 0, ans = 0;
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(); LL w = read();
		addEdge(u, v, w), r += w;
	}
	dep[1] = 1;
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = max(ans, lca(i, j));
	printf("%lld\n", ans);
	return 0;
}
