#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
int p[MAXN];
int dp[MAXN][MAXN][2];

int f(int l, int r, int r_, bool l_) {
	memset(dp, -1, sizeof(dp));
	dp[l][l][1] = p[l];
	dp[l][l][0] = l_ ? p[l] : 0;
	for (int ir = l + 1; ir <= r; ir++) {
		dp[l][r][0] = dp[l][r - 1][1];
		dp[l][r][1] = min(dp[l][r - 1][0], dp[l][r - 1][1]) + p[r];
	}
	return dp[l][r][r_];
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int n, m;
	char[5] type;
	scanf("%d%d%s", &n, &m, type);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n - 1; i++)
		scanf("%d%d");
	for (int i = 0; i < m, i++) {
		int a, x, b, y;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		int ans;
		//if (x == 1 && y == 1)
		//	ans = min(f(1, a, 1), f(1, a, 0)) + min(f(a + 1, b, 1), f(a + 1, b, 0)) + min(f(b + 1, n, 0), f(b + 1, n, 1));
		if (y == 0)
			ans = f(1, l, 0, 1) + min(f(r + 1, n, 0, 0), f(r + 1, n, 1, 0));
		if (y == 1)
			ans = min(f(1, l, 0, 1), f(1, l, 1, 1)) + min(f(r, n, 0, 1), f(r, n, 1, 1));
		printf("%d\n", ans);
	}
	return 0;
}
