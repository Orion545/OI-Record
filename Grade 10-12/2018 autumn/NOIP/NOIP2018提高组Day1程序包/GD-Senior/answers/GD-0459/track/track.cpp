#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#define fo(i, x, y) for (int i = x; i <= y; ++i)
#define fd(i, x, y) for (int i = x; i >= y; --i)

using namespace std;

const int maxn = 5e4 + 5;

struct Edge {
	int to, val;
	Edge *nxt;
} *arc[maxn], pool[maxn << 1];
int n, m, pcnt, ans, lim;
int d[maxn], a[maxn];

int getint() {
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

void addedge(int u, int v, int w) {
	pool[pcnt] = (Edge){v, w, arc[u]};
	arc[u] = &pool[pcnt++];
}

void dfs(int x, int xfa) {
	for (Edge *e = arc[x]; e; e = e->nxt)
		if (e->to != xfa) {
			dfs(e->to, x);
			ans = max(ans, d[x] + d[e->to] + e->val);
			d[x] = max(d[x], d[e->to] + e->val);
		}
}

void work1() {
	dfs(1, 0);
	printf("%d\n", ans);
}

bool check(int x) {
	int sum = 0, cnt = 0;
	fo (i, 1, n - 1) {
		sum = a[i];
		for (; i + 1 <= n - 1 && sum < x; sum += a[i + 1], i++);
		cnt += sum >= x;
		if (cnt >= m) return true;
	}
	return false;
}

void work2() {
	int l = 0, r = lim + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
			else r = mid;
	}
	printf("%d\n", l);
}

void work3() {
	printf("%d\n", lim);
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	n = getint(); m = getint();
	bool isl = true;
	fo (i, 1, n - 1) {
		int u = getint(), v = getint(), w = getint();
		addedge(u, v, w);
		addedge(v, u, w);
		if (v != u + 1) isl = false;
		a[u] = w;
		lim += w;
	}
	if (m == 1) work1();
		else if (isl) work2();
			else work3();
	return 0;
}
