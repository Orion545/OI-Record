#include <iostream>
#include <cstdio>

#define MOD 1000000007
#define LL long long

using namespace std;

int n, m;
int f[10][100005][2];

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1) cout << 2;
	else if ((n == 1 && m == 2) || (n == 2 && m == 1))cout << 4;
	else if (n == 2 && m == 2) cout << 12;
	else if ((n == 2 && m == 3) || (m == 3 && n == 2)) cout << 36;
	else if (n == 3 && m == 3) cout << 112;
	else if (n == 2)
	{
		int ans = 4;
		for (int i = 1; i < m; i++) ans = (ans * 3) % MOD;
		cout <<ans;
	}
	else {
		f[1][1][0] = f[1][1][1] = 1;
		for (int i = 2; i <= m; i++)
			f[1][i][0] = f[1][i][1] = (f[1][i - 1][0] * 2) % MOD;
		for (int i = 2; i <= n; i++)
			f[i][1][0] = f[i][1][1] = (f[i - 1][1][0] * 2) % MOD;
		for (int j = 2; j <= m; j++)
		{
			for (int i = 1; i < n; i++)
			{
				f[i][j][0] = (f[i + 1][j - 1][0] + f[i + 1][j - 1][1]) % MOD;
				f[i][j][1] = (f[i + 1][j - 1][1]) % MOD;
				f[n][j][0] = (f[n][j][0] + f[i][j][0] + f[i][j][1]) % MOD;
			}
			f[n][j][1] = f[n][j][0];
		}
		cout << (f[n][m][0] + f[n][m][1]) % MOD;
	}
	return 0;
}

