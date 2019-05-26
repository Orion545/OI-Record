#include <cstdio>
#include <string.h>
#include <algorithm>
#define R register
#define In inline
#define re(i, x, y) for (R int i = x; i <= y; ++ i)
#define de(i, x, y) for (R int i = x; i >= y; -- i)
using namespace std;

int T, n, a[100], f[25005], ans, Max, jj;

In void find(int x, int sum) {
	re(q, x+1, n) for (int w = 0; sum+a[q]*w<=Max; ++ w) {
		if (f[sum+a[q]*w]<=jj) f[sum+a[q]*w]++; find(q, sum+a[q]*w);
	}
	return;
}

int main() {
	freopen("money.in", "r", stdin); freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
	    scanf("%d", &n); Max = 0;
	    re(i, 1, n) { scanf("%d", &a[i]); Max = max(Max, a[i]); }
	    ans = n; 
	    memset(f, 0, sizeof(f));
		jj = 1; re(i, 1, n-1) jj *= 2; jj--;
	    re(i, 1, n) for (int j = 0; a[i]*j<=Max; ++ j) find(i, a[i]*j);
		re(i, 1, n) f[a[i]] -= jj;
	    re(i, 1, n) if (f[a[i]]) ans--;
	    printf("%d\n", ans);
	}
	return 0;
}
