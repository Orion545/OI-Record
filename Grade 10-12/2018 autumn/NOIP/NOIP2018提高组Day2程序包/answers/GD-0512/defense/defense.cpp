# include <bits/stdc++.h>
using namespace std;
# define Rep(i, s, t) for (int i = (s), _ = (t); i <= _; i ++)
# define LL long long
const int N = 5000;
const LL INF = 1e10;
int n, m, p[N], tot, hd[N];
struct E {
	int v, nx;
} mp[N];
LL f[N][2];
int rd() {
	int x = 0; char c;
	do { c = getchar(); } while (! isdigit(c));
	do { x = x*10+c-'0', c = getchar(); } while (isdigit(c));
	return x;
}
void DP(int x, int fa, int y, int b) {
	f[x][0] = 0, f[x][1] = p[x];
	if (x == y)
		f[x][b ^ 1] = INF;
	for (int k = hd[x]; k; k = mp[k].nx) {
		int v = mp[k].v;
		if (v != fa) {
			DP(v, x, y, b);
			f[x][0] += f[v][1];
			f[x][1] += min(f[v][0], f[v][1]);
		}
	}
}
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	n = rd(), m = rd(), rd();
	Rep (i, 1, n)
		p[i] = rd();
	Rep (i, 1, n-1) {
		int x = rd(), y = rd();
		mp[++ tot] = (E) { y, hd[x] }, hd[x] = tot;
		mp[++ tot] = (E) { x, hd[y] }, hd[y] = tot;
	}
	Rep (i, 1, m) {
		int x = rd(), a = rd(), y = rd(), b = rd();
		DP(x, 0, y, b);
		printf("%d\n", f[x][a] < INF ? f[x][a] : -1);
	}
	return 0;
}
