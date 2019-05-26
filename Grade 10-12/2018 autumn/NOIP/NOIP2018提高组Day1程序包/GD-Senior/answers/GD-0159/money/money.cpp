#ifdef LOCAL
#include <cstdio>
namespace dbg{
using std::printf;
}
#endif

/*
NOIP2017D1T1 says that, ans = a*b-a-b (gcd(a,b)=1)
*/

#include <cstdio>
using std::freopen;
using std::scanf;
using std::printf;

#include <algorithm>
using std::sort;
using std::max;
using std::min;

#include <cstring>
using std::memset;

unsigned a[105], b[105], n;
int vis[2500005];
unsigned dp[2500005];
unsigned i, j, k, m;

int _main()
{
	scanf("%u", &n);
	for(i = 0 ; i < n ; i++)
		scanf("%u", &a[i]);
	sort(a, a+n);
	memset(vis, 0, sizeof(vis));
	for(i = 0 ; i < n ; i++)
		if(!vis[i])
			for(j = i+1 ; j < n ; j++)
				if(a[j] % a[i] == 0) vis[j] = 1;
	for(i = 0, j = 0 ; i < n ; i++)
		if(!vis[i]) b[j++] = a[i];
	#ifdef LOCAL
	for(i = 0 ; i < j ; i++) printf("%u ", b[i]);
	printf("\n");
	#endif
	unsigned macant = b[0] * b[1] - b[1] - b[0];
	macant = macant < b[1] ? b[1] : macant;
	unsigned lb = 0;
	for(lb = 0 ; lb < j ; lb++)
		if(b[lb] > macant) break;
	
	
	memset(vis, 0, sizeof(vis));
	
	/*memset(dp, 0, sizeof(dp));
	for(i = 0 ; i < lb ; i++)
		dp[b[i]] = 1;
		
	unsigned sum = 0;
	for(i = 0 ; i < lb ; i++) sum += lb;
		
	for(i = 0 ; i < lb ; i++)
	{
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		for(j = b[i] + 1 ; j <= sum ; j++)
			if(dp[j - b[i]])
			{
				vis[j] = 1;
				if(vis[j - b[i]])
				{
					if(dp[j]) dp[j] = min(dp[j], dp[j - b[i]]);
					else dp[j] = dp[j-b[i]];
				}
				else
				{
					if(dp[j]) dp[j] = min(dp[j], dp[j - b[i]] + 1);
					else dp[j] = dp[j-b[i]] + 1;
				}
			}
	}
	
	unsigned ans = 0;
	for(i = 0 ; i <= sum; i++)
		ans = max(dp[i], ans);
		
	printf("%u\n", ans);
	*/
	
	for(i = 0 ; i < lb ; i++)
		for(j = i + 1 ; j < lb ; j++)
			for(k = j + 1 ; k < lb ; k++)
			{
				for(m = 1 ; m*b[i] < b[k] ; m++)
					if((b[k] - m*b[i]) % b[j] == 0)
					{
						#ifdef LOCAL_DISABLED
						printf("DBG: hit %u with m=%u b[i]=%u b[j]=%u.\n", b[k], m, b[i], b[j]);
						#endif
						vis[k] = 1;
					}
			}
	unsigned ans = 0;
	#ifdef LOCAL
	printf("DBG: ");
	for(i = 0 ; i < lb ; i++) printf("%d ", vis[i]);
	printf("\n");
	#endif
	for(i = 0 ; i < lb ; i++)
		if(vis[i] == 0) ans++;
	printf("%u\n", ans);
	
	return 0;
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	unsigned T;
	scanf("%u", &T);
	while(T--) _main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

