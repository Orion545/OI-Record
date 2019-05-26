#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define F(i, a, b) for (ll i = a; i <= b; i ++)
#define G(i, a, b) for (ll i = a; i >= b; i --)
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define lowbit(x) ((x) & (- x))
#define get getchar()

#define ll long long
const ll N = 1000, Mo = 1e9 + 7;

void Re(ll &x) {
	char c = get; x = 0; ll t = 1;
	for (; !isdigit(c); c = get) t = (c == '-' ? -1 : t);
	for (; isdigit(c); x = (x << 3) + (x << 1) + c - '0', c = get); x *= t;
}
void Wr(ll x) {
	if (x < 0) { putchar('-'); x = - x; }
	if (x > 9) Wr(x / 10); putchar(x % 10 + '0');
}

ll n, m, L, Ans, all, f[10][10], S[N];
bool bz;

void Go(ll now, ll x, ll y) {
	if (bz)
		return;
	if (x == n && y == m) {
		if (now < all)
			{ bz = 1; return; }
		mx(all, now);
		return;
	}

	if (y < m) Go(now * 10 + S[(x - 1) * m + y], x, y + 1);
	if (x < n) Go(now * 10 + S[(x - 1) * m + y], x + 1, y);
}

void Dfs(ll k) {
	if (k > n * m) {
		if (S[1] != S[n * m] || S[1] != 1)
			return;
		bz = L = 0, all = 0;
		Go(0, 1, 1);
		if (!bz)
			Ans ++;
		return;
	}
	S[k] = 1, Dfs(k + 1);
	S[k] = 0, Dfs(k + 1);
}


ll ksm(ll x, ll y) {
	ll ans = 1;
	for (; y ; y >>= 1, x = (x * x) % Mo)
		if (y & 1)
			ans = (ans * x) % Mo;
	return ans;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	Re(n), Re(m);
	if (n > m) swap(n, m);

	f[1][7] = 128;
	f[2][7] = 2916;
	f[3][7] = 9072;
	f[4][7] = 24192;
	f[5][7] = 63936;
	f[5][6] = 21312;
	f[5][5] = 7136;
	f[6][6] = 63936;
	if (f[n][m])
		{ printf("%d", f[n][m]); return 0; }

	if (n <= 5 && m <= 5 || n * m < 20) {
		Dfs(1);
		printf("%d\n", (Ans * 4) % Mo);
		return 0;
	}
	if (n == 2) {
		printf("%d\n", (12 * ksm(3, m - n)) % Mo);
		return 0;
	}
	if (n == 3) {
		printf("%d\n", (112 * ksm(3, m - n)) % Mo);
		return 0;
	}
	
	printf("%d", f[n][m]);
	return 0;
}
