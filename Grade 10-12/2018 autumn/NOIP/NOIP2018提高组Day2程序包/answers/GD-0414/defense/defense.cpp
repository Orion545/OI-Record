#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define LL long long
#define fo(i, x, y) for(int i = x; i <= y; i++)
#define fd(i, x, y) for(int i = x; i >= y; i--)
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
void init() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
}
int read() {
	int b = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if (c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) b = b * 10 + c - '0';
	return b * k;
}
const int N = 2e5 + 5;
int n, m, op2, x, y, _1, _2, p[N], dep[N], a, b, c, d;
int ans, t, tt, bz[N];
char op;
int tot, to[N], ne[N], la[N];
int f[N][2];
void Link(int u, int v) {to[++tot] = v, ne[tot] = la[u], la[u] = tot;}
void Dfs(int now, int fa) {
	bool bz = 0;
	int _0 = 0, _1 = 0;
	for(int i = la[now]; i; i = ne[i]) {
		int nex = to[i];
		if (nex == fa) continue;
		Dfs(nex, now);
		_0 += f[nex][1];
		_1 += min(f[nex][0], f[nex][1]);
		bz = 1;
	}
	if (!bz) {
		if (now == x) {
			if (a == 0) f[x][0] = 0;
			else f[x][1] = p[x];
			return;
		}
		if (now == y) {
			if (b == 0) f[y][0] = 0;
			else f[y][1] = p[y];
			return;
		}
		f[now][0] = 0;
		f[now][1] = p[now];
		return;
	}
	if (now == x) {
		if (a == 0) f[x][0] = _0; else
		f[x][1] = _1 + p[now];
	} else if (now == y) {
		if (b == 0) f[y][0] = _0; else 
		f[y][1] = _1 + p[now];
	} else {
		f[now][0] = _0;
		f[now][1] = _1 + p[now];
	}
}
void work() {
	for(; m; m--) {
		//printf("%d\n", m);
		x = read(), a = read(), y = read(), b = read();
		fo(i, 1, n) f[i][0] = f[i][1] = 1 << 25;
		f[0][0] = f[0][1] = 0;
		fo(i, 1, n) {
			if (i == x) {
				if (a == 0) f[i][0] = min(f[i][0], f[i - 1][1]); else {
					f[i][1] = min(f[i][1], f[i - 1][0] + p[i]);
					f[i][1] = min(f[i][1], f[i - 1][1] + p[i]);
				}
				continue;
			}
			if (i == y) {
				if (b == 0) f[i][0] = min(f[i][0], f[i - 1][1]); else {
					f[i][1] = min(f[i][1], f[i - 1][0] + p[i]);
					f[i][1] = min(f[i][1], f[i - 1][1] + p[i]);
				}
				continue;
			}
			f[i][0] = min(f[i][0], f[i - 1][1]);
			f[i][1] = min(f[i][1], f[i - 1][0] + p[i]);
			f[i][1] = min(f[i][1], f[i - 1][1] + p[i]);
		}
		if (min(f[n][0], f[n][1]) == (1 << 25)) printf("-1\n"); else
		printf("%d\n", min(f[n][0], f[n][1]));
	}
}
int main() {
	init();
	scanf("%d %d %c%d", &n, &m, &op, &op2);
	//printf("%d %d %c%d", n, m, op, op2);
	fo(i, 1, n) p[i] = read();
	fo(i, 1, n - 1) {
		x = read(), y = read();
		Link(x, y), Link(y, x);
	}
	if (op == 'A') {
		work();
		return 0;
	}
	for(; m; m--) {
		x = read(), a = read(), y = read(), b = read();
		fo(i, 1, n) f[i][0] = f[i][1] = 1 << 27;
		Dfs(1, 0);
		if (min(f[1][0], f[1][1]) >= 1 << 27) printf("-1\n"); else
		printf("%d\n", min(f[1][0], f[1][1]));
	}
	return 0;
}
