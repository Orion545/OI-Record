#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 100;
const int MaxA = 25000;

int T;
int n, ans;
int d[MaxN + 5];
bool f[MaxA + 5];

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	scanf("%d", &T);
	
	for (; T--;)
	{
		scanf("%d", &n);
		ans = 0;
		
		for (int i = 1; i <= n; i++)
			scanf("%d", &d[i]);
			
		sort(d + 1, d + n + 1);
		memset(f, false, sizeof(f));
		f[0] = true;
		
		for (int i = 1; i <= n; i++)
			if (!f[d[i]])
			{
				ans++;
				
				for (int j = 0; j <= MaxA - d[i]; j++)
					f[j + d[i]] |= f[j];
			}
			
		printf("%d\n", ans);
	}
	
	return 0;
}
