#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const long long MaxN = 8;
const long long MOD = 1E9 + 7;

long long n, m;
long long FULL;
long long ans;
long long a[256][256], b[256][256], f[256][256];
	
void Times(long long a[256][256], long long b[256][256], long long c[256][256])
{
	long long tmp[256][256];
	memset(tmp, 0, sizeof(tmp));
	
	for (long long i = 0; i < FULL; i++)
		for (long long j = 0; j < FULL; j++)
			for (long long k = 0; k < FULL; k++)
				tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
				
	memcpy(c, tmp, sizeof(tmp));
}

int main()
{
	freopen("game.in", "r", stdin);
//	froepen("game.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	FULL = 1 << n;
	
	for (long long i = 0; i < FULL; i++)
		for (long long j = 0; j < FULL; j++)
			a[(i / 2) & j][i] = a[(i / 2) & j ^ (FULL / 2)][i] = 1;
	
	for (long long i = 0; i < FULL; i++)
	{
		memset(f[i], 0, sizeof(f[i]));
		f[i][1] = 1;
		b[i][i] = 1;
	}
		
	for (long long y = m - 1; y; y >>= 1, Times(a, a, a))
		if (y & 1)
			Times(b, a, b);
	
	Times(b, f, f);
	
	for (long long i = 0; i < FULL; i++)
		ans = (ans + f[i][1]) % MOD;
		
	printf("%lld\n", ans);
	
	return 0;
}
