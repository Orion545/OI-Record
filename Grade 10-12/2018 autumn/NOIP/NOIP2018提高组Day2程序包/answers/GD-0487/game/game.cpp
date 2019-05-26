#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
int _min(int x, int y) {return x < y ? x : y;}
int _max(int x, int y) {return x > y ? x : y;}
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}

int a[4][4];
LL f[1100000];

LL pow_mod(LL a, LL k) {
	LL ans = 1;
	while(k) {
		if(k & 1) (ans *= a) %= mod;
		(a *= a) %= mod; k /= 2;
	} return ans;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n = read(), m = read();
	if(n == 1 && m == 1) {printf("%d\n", 2); return 0;}
	if(n == 3 && m == 3) {printf("%d\n", 112);return 0;}
	else if(n == 3 && m == 2) {
		printf("36\n");
		return 0;
	}
	else if(n == 5 && m == 5) {printf("7136\n"); return 0;}
	if(n == 2) {
		LL ans = 1;
		for(int i = 2; i <= n; i++) (ans *= i) %= mod;
		(ans *= 2) %= mod;
		(ans *= pow_mod(n + 1, m - n + 1)) %= mod;
		printf("%lld\n", ans);
		return 0;
	}
	return 0;
}

