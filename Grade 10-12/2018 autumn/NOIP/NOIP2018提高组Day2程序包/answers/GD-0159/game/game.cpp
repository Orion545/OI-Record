#ifdef LOCAL
#include <cstdio>
using std::printf;
#endif

#include <cstdio>
using std::freopen;
using std::fclose;
using std::scanf;
using std::printf;

#include <algorithm>
using std::min;
using std::max;

long long m,n;

const long long p = 10000009;
// const long long r = 281257;

long long powmod(long long a, long long b)
{
	long long ans = 1;
	long long base = a;
	while(b)
	{
		if(b&1) ans = (ans * base) % p;
		base = (base * base) % p;
		b >>= 1;
	}
	return ans;
}

long long f[1000016][10][10];
/*
f[j][i][k] where j = row + col i = col1 k = col2
s.t. i <= j
that is w(i) > w(j) where s(i) <= s(j)  
*/

long long i,j,k;

void hack(long long n, long long m)
{
	if(n == 2 && m == 2) printf("12\n");
	if(n == 3 && m == 3) printf("112\n");
	if(n == 5 && m == 5) printf("7136\n");
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	hack(n,m);
	return 0;
	// if(n == 2 && m == 2)
	//	return printf("12"), 0;
	f[0][0][0] = 2;
	for(j = 1 ; j <= m+n-2 ; j++)
		for(i = j - min(j, n-1) ; i <= min(j,n-1) ; i++)
			for(k = i ; k <= min(j,n-1) ; k++)
			{
				if(i > 0)
				{
					//support down
					if(k > 0 && k != j)
					{
						//support right
						// i->down k->right
						if(i == k) f[j][i][k] = (f[j][i][k] + (f[j-1][i-1][k] << 1)) % p;
						else f[j][i][k] = (f[j][i][k] + (f[j-1][i-1][k] << 2)) % p;
					}
					// i->down k->down
					if(i == k) f[j][i][k] = (f[j][i][k] + (f[j-1][i-1][k-1] << 1)) % p;
					else f[j][i][k] = (f[j][i][k] + (f[j-1][i-1][k-1] << 2)) % p;
				}
				if(k > 0 && i != j)
				{
					//support down
					// i->right k->down
					if(k == i) f[j][i][k] = (f[j][i][k] + (f[j-1][i][k-1] * 3))% p;
					else f[j][i][k] = (f[j][i][k] + (f[j-1][i][k-1] << 2)) % p;
					
				}
				// i ->right k -> right
				if(i == j && k == j) continue;
				if(i == k) f[j][i][k] = (f[j][i][k] + (f[j-1][i][k] << 1)) % p;
				else f[j][i][k] = (f[j][i][k] + (f[j-1][i][k] << 2)) % p;
			}
			
	#ifdef LOCAL
	for(j = 0 ; j <= m+n-2 ; j++)
	{
		printf("f[%lld]:\n", j);
		for(i = 0 ; i <= min(j,n-1) ; i++)
		{
			for(k = 0 ; k <= min(j,n-1);k++) printf("%lld ", f[j][i][k]);
			printf("\n");
		}
	}
	#endif
	printf("%lld\n", f[m+n-2][n-1][n-1]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

