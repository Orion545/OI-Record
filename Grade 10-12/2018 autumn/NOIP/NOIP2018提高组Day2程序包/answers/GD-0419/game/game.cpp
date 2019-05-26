#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
int n, m;

long long Pow(long long x, long long y)
{
	if (y == 0) return 1;
	long long ans = Pow(x, y >> 1);
	ans = ans * ans % mod;
	if (y & 1) ans = ans * x % mod;
	return ans;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n > m) swap(n, m);
	if (n == 1) printf("%lld\n", Pow(2, m));
	else if (n == 2) printf("%lld\n", 4 * Pow(3, m - 1) % mod);
	else if (n == 3)
	{
		printf("%lld\n", 112 * Pow(3, m - 3));
	}
}
