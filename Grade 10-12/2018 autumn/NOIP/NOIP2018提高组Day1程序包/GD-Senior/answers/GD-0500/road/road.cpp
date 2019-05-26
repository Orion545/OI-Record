#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define LL long long
#define F(i, x, y) for (long long i = x; i <= y; i++)
#define D(i, x, y) for (long long i = x; i >= y; i--)

using namespace std;

const long long N = (2e5 + 5);

long long n, m, ans;
long long a[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%lld", &n); a[n + 1] = 0;
	F(i, 1, n) scanf("%lld", &a[i]);
	F(i, 2, n + 1)
		if (a[i] < a[i - 1]) ans += a[i - 1] - a[i];
	printf("%lld\n", ans);
	return 0;
}
