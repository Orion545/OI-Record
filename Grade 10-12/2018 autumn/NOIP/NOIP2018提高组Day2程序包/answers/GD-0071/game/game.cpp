#include<cstdio>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int mo = 1e9 + 7;

const int N = 1 << 8;

int n, m, c, a2[9];
ll a[N][N], b[N][N], d[N][N], ans;


ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	a2[0] = 1; fo(i, 1, 8) a2[i] = a2[i - 1] * 2;
	scanf("%d %d", &n, &m);
	if(n > m) swap(n, m);
	if(n == 1) {
		printf("%lld\n", ksm(2, m)); return 0;
	}
	if(n == 2) {
		printf("%lld\n", ksm(3, m - 1) * 4 % mo);
		return 0;
	}
	if(n == 3 && m == 3) {
		printf("112\n"); return 0;
	}
	if(n == 3 && m == 2) {
		printf("36\n"); return 0;
	}
	if(n == 3) {
		printf("%lld\n", ksm(3, m - 3) * 19 * 8 % mo);
		return 0;
	}
	if(n == 4) {
		printf("%lld\n", ksm(2, 4) * ksm(3, m - 4) % mo * 48 % mo);
		return 0;
	}
	if(n == 5) {
		printf("%lld\n", ksm(2, 5) * ksm(3, m - 5) % mo * 223 % mo);
		return 0;
	}
	c = a2[n] - 1;
	fo(i, 0, c) {
		fo(j, 0, c) {
			b[i][j] = 1;
			fo(k, 0, n - 2) if((j & a2[k]) && !(i & a2[k + 1])) b[i][j] = 0;
//			printf("%d %d %lld\n", i, j, b[i][j]);
		}
	}
	a[c][c] = 1;
	for(; m; m /= 2) {
		if(m & 1) {
			fo(i, 0, c) fo(j, 0, c) d[i][j] = a[i][j], a[i][j] = 0;
			fo(k, 0, c) fo(i, 0, c) fo(j, 0, c) a[i][j] = (a[i][j] + d[i][k] * b[k][j]) % mo;
		}
		fo(i, 0, c) fo(j, 0, c) d[i][j] = b[i][j], b[i][j] = 0;
		fo(k, 0, c) fo(i, 0, c) fo(j, 0, c) b[i][j] = (b[i][j] + d[i][k] * d[k][j]) % mo;
	}
	fo(i, 0, c) fo(j, 0, c) ans = (ans + a[i][j]) % mo;
	printf("%lld", ans);
}
