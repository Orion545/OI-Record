#include <cstdio>
#define kN 100000
#define rep(i, x, y) for(int i=x;i<y;++i)
int a[kN];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n;
	scanf("%d", &n);
	rep (i, 0, n) {
		scanf("%d", a+i);
	}
	long long ans = a[0];
	rep (i, 1, n) {
		if (a[i - 1] < a[i]) {
			ans += a[i] - a[i-1];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
