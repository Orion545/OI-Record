#include<cstdio>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 100005;

int n, m, x, y, z;
int fi[N], nt[N * 2], to[N * 2], v[N * 2], tot;
int S, sum, ans, mi;

void link(int x, int y, int z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
}

int bz[N], f[N], d[N];

int calc(int x) {
	int l = 1, g = 0;
	fd(i, d[0], 1) if(i != x) {
		if(i < l) break;
		if(d[i] >= mi) g ++; else {
			while(l < i && (d[l] + d[i] < mi || l == x)) l ++;
			if(l >= i) break;
			g ++; l ++;
		}
	}
	return g;
}

void dg(int x) {
	bz[x] = 1;
	for(int i = fi[x]; i; i = nt[i]) if(!bz[to[i]])
		dg(to[i]);
	d[0] = 0;
	for(int i = fi[x]; i; i = nt[i]) if(!bz[to[i]])
		d[++ d[0]] = f[to[i]] + v[i];
	sort(d + 1, d + d[0] + 1);
	int g = calc(0); sum += g;
	f[x] = 0;
	for(int u = 1, v = d[0]; u <= v; ) {
		int mm = u + v >> 1;
		if(calc(mm) == g) f[x] = d[mm], u = mm + 1; else v = mm - 1;
	}
	bz[x] = 0;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	fo(i, 1, n - 1) {
		scanf("%d %d %d", &x, &y, &z);
		link(x, y, z); link(y, x, z);
		S += z;
	}
	for(int l = 1, r = S / m; l <= r; ) {
		mi = l + r >> 1;
		sum = 0; dg(1);
		if(sum >= m) ans = mi, l = mi + 1; else r = mi - 1; 
	}
	printf("%d", ans);
	return 0;
}
