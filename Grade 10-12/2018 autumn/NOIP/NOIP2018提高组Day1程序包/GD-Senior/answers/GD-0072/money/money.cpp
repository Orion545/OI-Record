/*
	problem:ªı±“œµÕ≥
	dp
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

long long T;
long long n;
long long a[101];
long long f[50500];
long long u[50500];
long long maxa;

int main () {
	
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	long long i, j, k;
	scanf("%lld", &T);
	while (T --) {
		scanf("%lld", &n);
		memset(f, 0, sizeof(f));
		memset(u, 0, sizeof(u));
		maxa = 0;
		for (i = 1; i <= n; ++ i) {
			scanf("%lld", &a[i]);
			u[a[i]] = 1;

			maxa = max(maxa, a[i]);
		}
		sort(a + 1, a + n + 1);
//		for (i = 1; i <= n; ++ i) {
//			for (j = 2; j * a[i] <= maxa; ++ j) {
//				f[j * a[i]] = 1;
//			}
//		}
//		for (i = 1; i <= n; ++ i) cout << a[i] << ' '; cout << endl;
		for (i = 1; i <= n; ++ i) {
			if (!u[a[i]]) continue;
			f[a[i]] = 1;
			for (j = 1; j <= maxa; ++ j) {
				long long m = (maxa - j) / a[i];
				for (k = 1; k <= m; ++ k) {
					f[j + k * a[i]] = (f[j] | f[j + k * a[i]]);
					if (u[j + k * a[i]] && f[j + k * a[i]]) u[j + k * a[i]] = 0;
				}
			}
		}
		long long ans = n;
		for (i = 1; i <= n; ++ i) {
//			if (u[a[i]]) cout << a[i] << ' ';
			if (!u[a[i]]) -- ans;
		}
//		cout << endl;
		printf("%lld\n", ans);
	}
	
		
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17

*/
