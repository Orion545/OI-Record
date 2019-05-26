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
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
}
int read() {
	int b = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if (c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) b = b * 10 + c - '0';
	return b * k;
}
int n, m, ans, a[10][1000005];
bool pd(int x, int y, int xx, int yy, bool p) {
	if (x > n || xx > n || y > m || yy > m) return 1;
	if (a[x][y] > a[xx][yy]) return 1;
	if (a[x][y] < a[xx][yy]) return 0;
	bool tot = 1;
	tot &= pd(x + 1, y, xx, yy + 1, 1);
	tot &= pd(x + 1, y, xx + 1, yy, p);
	tot &= pd(x, y + 1, xx, yy + 1, p);
	if (p) tot &= pd(x, y + 1, xx + 1, yy, p);
	return tot;
}
void Dfs(int k, int z) {
	int x = (k - 1) / m + 1, y = k - m * (x - 1);
	if (x > n || y > m) return;
	a[x][y] = z;
	if (x == n && y == m) {
		//printf("-");
		if (pd(1, 1, 1, 1, 0)) {
			ans++;
			//fo(i, 1, n) {
				//fo(j, 1, m) printf("%d", a[i][j]);
				//printf("\n");
			//}
			//printf("\n");
		}	
		return;
	}
	Dfs(k + 1, 0);
	Dfs(k + 1, 1);
}
int main() {
	init();
	n = read(), m = read();
	Dfs(1, 0);
	Dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}
