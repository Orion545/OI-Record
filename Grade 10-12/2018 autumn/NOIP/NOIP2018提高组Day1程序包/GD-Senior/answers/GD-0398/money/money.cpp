#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 128
using namespace std;
int a[N], f[N], i, j, k, T, n, t, ans;

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		memset(f, 0, sizeof f);
		scanf("%d", &n);
		for (i=1; i<=n; ++i) scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		t = a[n];
		ans = 0;
		for (i=1; i<=n; ++i) {
			if (f[a[i]]) continue;
		//	printf("%d\n", a[i]);
			ans ++;
			for (j=a[i]; j<=t; j+=a[i]) {
				f[j] = 1;
			}
			for (j=a[i]; j<=t; j+=a[i]) {
				for (k=a[1]; j+k<=t; k++) {
					if (f[k]) f[k+j] = 1;
				}
			}
		//	for (j=a[1]; j<=t; ++j) if (f[j]) printf("%d ", j);
		//	printf("\n");
		}
		printf("%d\n", ans);
	}
	return 0;
}
