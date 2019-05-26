#include <cstdio>
#include <algorithm>

#define MOD 1000000007ll
#define MAXN 1000000

using namespace std;

long long f[8][MAXN + 5][2], g[8][MAXN + 5][2];
long long ff[8][MAXN + 5];
long long poww[8 * MAXN + 5];

void init()
{
	long long tmp = 1;
	poww[0] = 1;
	for (int i = 1; i <= MAXN * 8; ++ i) {
		tmp = (tmp << 1) % MOD;
		poww[i] = tmp % MOD;
	}
}

int main(void)
{
	freopen("game.in",  "r",  stdin);
	freopen("game.out", "w", stdout);
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	init();
	g[1][1][0] = 1;
	f[1][1][1] = 1;
	for (int i = 2; i <= m; ++ i) {
		f[1][i][0] = (f[1][i - 1][1] + f[1][i - 1][0] + g[1][i - 1][0] + g[1][i - 1][1]) % MOD;
		f[1][i][1] = f[1][i - 1][0] * (poww[min(n, i) - 1] - 1) % MOD;
		g[1][i][1] = f[1][i - 1][0] * (poww[min(n, i) - 1] - 1) % MOD;
		g[1][i][0] = f[1][i - 1][0];
	}
	for (int i = 2; i <= n; ++ i) {
		f[i][m][0] = (f[i - 1][m][1] + f[i - 1][m][0] + g[i - 1][m][0] + g[i - 1][m][1]) % MOD;
		f[i][m][1] = f[i - 1][m][0] * (poww[n - i] - 1) % MOD;
		g[i][m][1] = f[i - 1][m][0] * (poww[n - i] - 1) % MOD;
		g[i][m][0] = f[i - 1][m][0];
	}
	printf("%lld", poww[n * m] - (f[n][m][0] + f[n][m][1] + g[n][m][0] + g[n][m][1]));
	return 0;
}
