#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
#include <algorithm>
#include <iostream>

#define fo(i, x, y) for (int i = x; i <= y; ++i)
#define fd(i, x, y) for (int i = x; i >= y; --i)

using namespace std;

const int maxn = 1e5 + 5, inf = 1e9;

struct Edge {
	int to;
	Edge *nxt;
} *arc[maxn], pool[maxn << 1];
int n, m, ans, pcnt;
int w[maxn], flag[maxn];
bool cho[maxn];
char type[5];

int getint() {
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

void addedge(int u, int v) {
	pool[pcnt] = (Edge){v, arc[u]};
	arc[u] = &pool[pcnt++];
}

bool check() {
	fo (i, 1, n)
		for (Edge *e = arc[i]; e; e = e->nxt)
			if (!cho[i] && !cho[e->to]) return false;
	return true;
}

void dfs(int k, int sum) {
	if (sum > ans) return;
	if (k > n) {
		if (check()) ans = sum;
		return;
	}
	if (flag[k] != -1) {
		cho[k] = flag[k];
		dfs(k + 1, sum + w[k] * flag[k]);
	}
	else {
		cho[k] = true;
		dfs(k + 1, sum + w[k]);
		cho[k] = false;
		dfs(k + 1, sum);
	}
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	n = getint(); m = getint(); scanf("%s", type);
	fo (i, 1, n) w[i] = getint();
	bool isl = true;
	fo (i, 1, n - 1) {
		int u = getint(), v = getint();
		if (v < u) swap(u, v);
		addedge(u, v);
		addedge(v, u);
		if (v != u + 1) isl = false;
	}
	fo (i, 1, n) flag[i] = -1;
	fo (i, 1, m) {
		int a = getint(), x = getint(), b = getint(), y = getint();
		flag[a] = x; flag[b] = y;
		ans = inf;
		dfs(1, 0);
		if (ans < inf)
			printf("%d\n", ans);
		else
			printf("-1\n");
		flag[a] = flag[b] = -1;
	}
	return 0;
}
