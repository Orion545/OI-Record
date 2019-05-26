#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LL long long

using namespace std;

LL read() {
	LL t = 0; char ch = getchar();
	while ('0' > ch || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') 
		t = (t << 3) + (t << 1) + ch - '0',
		ch = getchar();
	return t;
}

const int maxn = 1e5 + 5;
const LL INF = 1e10; 
struct Edge {
	int v, nex;
	Edge() {}
	Edge(int _v, int _nex) { v = _v, nex = _nex; }
} E[maxn << 1];
int head[maxn], tote;

void addEdge(int u, int v) {
	E[++tote] = Edge(v, head[u]), head[u] = tote;
	E[++tote] = Edge(u, head[v]), head[v] = tote; 
}

LL f[maxn][3], w[maxn];
int a, b, x, y, n;

void dp(int u, int fa) {
	f[u][0] = f[u][1] = f[u][2] = 0;
	if (a == u) {
		if (!x) f[u][1] = INF;
		else f[u][0] = f[u][2] = INF;
	} else if (b == u) {
		if (!y) f[u][1] = INF;
		else f[u][0] = f[u][2] = INF;
	}
	if (head[u] == -1) {
		f[u][0] = 0, f[u][1] = w[u], f[u][2] = INF;
		return ;
	}
	int tmp = 0;
	for (int i = head[u]; ~i; i = E[i].nex) {
		int v = E[i].v;
		if (v == fa) continue;
		dp(v, u);
		f[u][1] += min(f[v][0], min(f[v][1], f[v][2]));
		f[u][0] += f[v][2];
		tmp += min(f[v][1], f[v][2]);
	}
	f[u][1] += w[u];
	f[u][2] = INF;
	for (int i = head[u]; ~i; i = E[i].nex) {
		int v = E[i].v;
		if (v == fa) continue;
		f[u][2] = min(f[u][2], tmp - min(f[v][1], f[v][2]) + f[v][1]);
	}
}

int main() {
	string t; int T;
	memset(head, -1, sizeof(head));
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d", &n, &T), cin >> t;
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
	dp(1, -1);
	while (T--) {
		LL ans = 0;
		a = read(), x = read(), b = read(), y = read();
		if (a < b) swap(a, b), swap(x, y);
		dp(1, -1);
		if (a == 1) {
			if (!x) ans = f[1][2];
			else ans = f[1][1];
		} else ans = min(f[1][1], f[1][2]);
		if (ans >= INF) printf("-1\n");
		else printf("%lld\n", ans);
	}
	return 0;
}
