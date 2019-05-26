#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50005;

struct NODE {
	int s, d, l;
};

NODE node[MAXN];

bool cmp(NODE a, NODE b) {
	return a.l > b.l;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int s, d, l;
		scanf("%d%d%d", &s, &d, &l);
		NODE now;
		now.s = s; now.d = d; now.l = l;
		node[i] = now;
	}
	sort(node + 1, node + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= 2 * m; i++) {
		ans += node[i].l;
	}
	printf("%d", ans);
	return 0;
}
