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
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
}
int read() {
	int b = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if (c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) b = b * 10 + c - '0';
	return b * k;
}
const int N = 1e4 + 5;
const int M = 5e3 + 5;
struct node {
	int x, y;
}c[N];
int n, m, x, y, a[M][M], b[M][M];
int s[N], p[N], ans[N];
int bz;
void Dfs(int x, int fa) {
	if (p[x]) return;
	p[x] = 1, s[++s[0]] = x;
	if (!bz && ans[1] && s[s[0]] > ans[s[0]]) {bz = -1; return;}
	if (!bz && ans[1] && s[s[0]] < ans[s[0]]) bz = 1;
	fo(i, 1, b[x][0]) {
		int nex = b[x][i];
		if (!a[x][nex]) continue;
		if (nex == fa) continue;
		Dfs(nex, x);
		if (bz == -1) return;
	}
}
void work() {
	if (s[0] < n) return;
	fo(i, 1, n) ans[i] = s[i];
}
bool cmp(const node &a, const node &b) {return a.x > b.x || (a.x == b.x && a.y > b.y);}
int main() {
	init();
	n = read(), m = read();
	//n = m = 5000;
	fo(i, 1, m) {
		x = read(), y = read();
		//x = i % n + 1, y = (i + 1) % n + 1;
		a[x][y] = a[y][x] = 1;
		c[i].x = x, c[i].y = y;
	}
	sort(c + 1, c + m + 1, cmp);
	fo(i, 1, n) {
		fo(j, 1, n) {
			if (a[i][j]) b[i][++b[i][0]] = j;
		}
	}
	if (m == n - 1) {
		Dfs(1, 0);
		fo(i, 1, n) printf("%d ", s[i]);
		return 0;
	}
	fo(i, 1, m) {
		x = c[i].x, y = c[i].y;
		a[x][y] = a[y][x] = 0;
		fo(j, 0, n) p[j] = s[j] = 0;
		bz = 0;
		Dfs(1, 0);
		if (!ans[1] || bz) work();
		a[x][y] = a[y][x] = 1;
	}
	fo(i, 1, n) printf("%d ", ans[i]);
	return 0;
}
