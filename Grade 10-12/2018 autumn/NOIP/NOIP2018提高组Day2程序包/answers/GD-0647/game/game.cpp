#include <cstdio>

long long n, m, f[4][1000005][2], p=1e9+7;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	if(m == 2) n ^= m ^= n ^= m;
	if(n == 1) {
		long long ans=1;
		while(m--) ans = (ans << 1) % p;
		printf("%lld\n", ans);
	}
	if(n == 2) {
		for(int i=1; i<=n; i++) f[i][1][0] = f[i][1][1] = 2;
		for(int i=2; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				if(j < n) {
					f[j][i][0] = (f[j+1][i-1][0] + f[j+1][i-1][1]) % p;
					f[j][i][1] = f[j+1][i-1][1];
				}
				else {
					f[j][i][0] = (f[j-1][i][0] + f[j-1][i][1]) % p;
					f[j][i][1] = (f[j-1][i][0] + f[j-1][i][1]) % p;
				}
			}
		}
		printf("%lld\n", (f[n][m][1]+f[n][m][0])%p);
	}
	return 0;
}
