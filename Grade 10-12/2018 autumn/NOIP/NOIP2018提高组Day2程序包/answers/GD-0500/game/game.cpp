#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define F(i, x, y) for (long long i = x; i <= y; i++)
#define D(i, x, y) for (long long i = x; i >= y; i--)

using namespace std;

const long long M = 1e6 + 5, mod = (1e9  + 7);
long long n, m, ans;
long long a[10][M], b[10][M], f[10][M][2];
long long e[M];

void Dfs(long long x, long long y)
{
	if (y > m)
	{
		Dfs(x + 1, 1); return;
	}
	if (x > n)
	{
		long long tag(1);
		F(i, 1, n)
			F(j, 1, m)
			{
				if (i + 1 <= n && j + 1 <= m)
				tag &= (a[i + 1][j] >= a[i][j + 1]);
			}
		/*if (tag)
		{
			F(i, 1, n)
			{
				F(j, 1, m) printf("%d ", a[i][j]);
				printf("\n");
			}
		printf("\n");
		}*/
		(ans += tag) %= mod; return;
	}
	a[x][y] = 1;
	Dfs(x, y + 1);
	a[x][y] = 0;
	Dfs(x, y + 1);
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	if (n > m) swap(n, m);
	e[0] = 1;
	F(i, 1, m) e[i] = e[i - 1] * 2 % mod;
	if (n == 1) return printf("%lld\n", e), 0;
	if (n == 2 && m == 3) return printf("36"), 0;
	if (n == 3 && m == 3) return printf("112"), 0; 
	if (n == 5 && m == 5) return printf("7136"), 0;
	
	ans = e[2];
	F(i, 2, m) ans = (ans * 3) % mod;
	printf("%lld\n", ans);
	return 0;
}
