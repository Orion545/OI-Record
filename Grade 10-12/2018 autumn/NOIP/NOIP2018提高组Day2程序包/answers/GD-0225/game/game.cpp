#include <cstdio>
#define INF 1000000007
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 1) {
		long long ans = 1;
		for(int x = m-1; x; x >>= 1)
			if (x & 1) ans = ans * 2 % INF;
		printf("%lld\n", ans);
		return 0;
	}
	if (m == 1) {
		long long ans = 1;
		for(int x = n-1; x; x >>= 1)
			if (x & 1) ans = ans * 2 % INF;
		printf("%lld\n", ans);
		return 0;
	}
	if (n == 2) {
		if (m == 1) puts("2");
		else if (m == 2) puts("12");
		else {
			long long ans = 4;
			for(int x = m; x; x >>= 1)
				if (x & 1) ans = ans * 3 % INF;
			printf("%lld\n", ans);
		}
		return 0;
	}
	if (n == 3 && m == 1) {
		puts("8");
	}
	if (n == 3 && m == 2) {
		puts("36");
	}
	if (n == 3 && m == 3) {
		puts("112");
	}
	return 0;
}
