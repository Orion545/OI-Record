#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long
#define fo(i, x, y) for(int i = x; i <= y; i++)
#define fd(i, x, y) for(int i = x; i >= y; i--)
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
void init() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
}
int read() {
	int b = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if (c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) b = b * 10 + c - '0';
	return b * k;
}
const int N = 3e4 + 5;
int T, n, a[N], mi, b[N], s[N], bz[N], ans, q[N];
int dist[N], d[N], p[N], head, tail, now, nex;
void spfa(int st) {
	fo(i, 0, mi - 1) dist[i] = 1 << 30, d[i] = p[i] = 0;
	head = tail = 0;
	d[++tail] = st;
	p[st] = 1, dist[st] = b[st];
	while (++head <= tail) {
		now = d[head];
		fo(i, 0, mi - 1) {
			if (b[i] == b[mi]) continue;
			nex = (now + i) % mi;
			if (dist[now] + b[i] < dist[nex]) {
				dist[nex] = dist[now] + b[i];
				if (!p[nex]) {
					p[nex] = 1;
					d[++tail] = nex;
				}
			}
		}
		p[now] = 0;
	}
}
void Dfs(int x, int cnt) {
	if (cnt >= ans) return;
	if (x == n) {
		mi = 1 << 30;
		fo(i, 1, n) if (bz[i]) mi = min(mi, a[i]);
		if (mi == 1 << 30) return;
		fo(i, 0, mi) b[i] = 1 << 30;
		fo(i, 1, n) if (bz[i]) b[a[i] % mi] = min(b[a[i] % mi], a[i]);
		spfa(0);
		fo(i, 0, mi - 1) if (s[i] != dist[i]) return;
		ans = min(ans, cnt);
		return;
	}
	if (q[x + 1]) {
		bz[x + 1] = 1;
		Dfs(x + 1, cnt + 1);
	}
	bz[x + 1] = 0;
	Dfs(x + 1, cnt);
}
void work() {
	mem(a, 0);
	mem(s, 0);
	mem(b, 127);
	n = read();
	mi = 1 << 30;
	fo(i, 1, n) a[i] = read(), mi = min(mi, a[i]);
	fo(i, 1, n) b[a[i] % mi] = min(b[a[i] % mi], a[i]);
	fo(i, 1, n) if (b[a[i] % mi] == a[i]) q[i] = 1;
	spfa(0);
	fo(i, 0, mi - 1) s[i] = dist[i];
	ans = 1 << 30;
	Dfs(0, 0);
	printf("%d\n", ans);
}
int main() {
	init();
	for(T = read(); T; T--) {
		work();
	}
	return 0;
}
