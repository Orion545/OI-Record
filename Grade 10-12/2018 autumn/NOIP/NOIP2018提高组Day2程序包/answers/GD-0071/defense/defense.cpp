#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x;i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

char tp[10];
int n, m, x, y, u1, v1, u2, v2;

const int N = 3e5 + 5;

int fi[N], nt[N * 2], to[N * 2], tot;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

int bz[N];
ll p[N], f[N][2], ans;

void dg(int x) {
	bz[x] = 1;
	f[x][1] = p[x];
	f[x][0] = 0;
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i]; if(bz[y]) continue;
		dg(y);
		f[x][1] += min(f[y][0], f[y][1]);
		f[x][0] += f[y][1];
	}
	if(x == u1) f[x][!v1] = 1e18;
	if(x == u2) f[x][!v2] = 1e18;
	bz[x] = 0;
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", tp + 1);
	fo(i, 1, n) scanf("%lld", &p[i]);
	fo(i, 1, n- 1) {
		scanf("%d %d", &x, &y);
		link(x, y); link(y, x);
	}
	fo(i, 1, m) {
		scanf("%d %d %d %d", &u1, &v1, &u2, &v2);
		dg(1);
		ans = min(f[1][0], f[1][1]);
		printf("%lld\n", ans >= 1e18 ? -1 : ans);
	}
}
