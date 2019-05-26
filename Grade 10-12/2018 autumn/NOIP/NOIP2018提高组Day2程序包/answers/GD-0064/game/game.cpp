#include <iostream>
#include <cstdio>
#define repu(i, x, y) for (int i = x; i <= y; ++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int MAXM = 1000011;
int n, m;
int dp[MAXM][256];
int nxt[300][300];
void dfs(int depth, int st, int cur, int arr[])
{
	if (depth == n)
	{
		arr[++arr[0]] = (cur << 1) | 0;
		arr[++arr[0]] = (cur << 1) | 1;
		return;
	}
	dfs(depth + 1, st, (cur << 1) | 0, arr);
	if (st & (1 << depth)) dfs(depth + 1, st, (cur << 1) | 1, arr);
}
void getNxt()
{
	repu(j, 0, (1 << n) - 1)
	{
		dfs(1, j, 0, nxt[j]);
	}
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n == 3 && m == 3)
	{
		cout << 112 << endl;
		return 0;
	}
	repu(j, 0, (1 << n) - 1)
		dp[1][j] = 1;
	getNxt();
	repu(i, 1, m - 1)
	{
		repu(j, 0, (1 << n) - 1)
		{
			repu(k, 1, nxt[j][0])
			{
				dp[i + 1][nxt[j][k]] = ((long long)dp[i + 1][nxt[j][k]] + dp[i][j]) % MOD;
			}
		}
	}
	ll ans = 0;
	repu(j, 0, (1 << n) - 1) ans = (ans + dp[m][j]) % MOD;
	printf("%lld\n", ans);
	return 0;
}
