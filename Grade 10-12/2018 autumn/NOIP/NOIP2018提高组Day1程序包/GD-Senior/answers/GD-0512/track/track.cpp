# include <bits/stdc++.h>
using namespace std;
# define Rep(i, s, t) for (int i = (s), _ = (t); i <= _; i ++)
const int N = 100005;
int n, m, tot, hd[N];
struct E {
	int v, d, nx;
} mp[N];
int L, R, M, w[N], num;
int l[N], siz, nx[N], u[N];
# define Fore(x) for (int k = hd[x], v = mp[k].v; k; k = mp[k].nx, v = mp[k].v) if (v != ff)
int Get(int x) {
	return nx[x] == x ? x : nx[x] = Get(nx[x]);
}
void DEQ(int x, int ff) {
	Fore(x) {
		DEQ(v, x);
		if (num >= m)
			return;
	}
	siz = 0;
	Fore(x) {
		w[v] += mp[k].d;
		if (w[v] < M)
			l[++ siz] = w[v];
		else {
			if (++ num >= m)
				return;
		}
	}
	sort(l + 1, l + siz + 1);
	Rep (i, 1, siz + 1)
		nx[i] = i;
	Rep (i, 1, siz)
		u[i] = 0;
	for (int le = 1, ri = siz + 1; le <= siz; le ++) {
		while (ri > 1 && l[le] + l[ri - 1] >= M)
			ri --;
		if (! u[le]) {
			nx[le] = le + 1;
			int gg = Get(ri);
			if (gg != siz + 1) {
				u[le] = u[gg] = 1;
				if (++ num >= m)
					return;
				nx[gg] = gg + 1;
			}
		}
	}
	Rep (i, 1, siz)
		if (! u[i])
			w[x] = l[i];
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", & n, & m);
	Rep (i, 1, n - 1) {
		int x, y, d;
		scanf("%d %d %d", & x, & y, & d);
		mp[++ tot] = (E) { y, d, hd[x] }, hd[x] = tot;
		mp[++ tot] = (E) { x, d, hd[y] }, hd[y] = tot;
	}
	L = 0, R = 50000 * 10000;
	while (L < R) {
		// M = 15;
		M = L + R + 1 >> 1;
		memset(w, 0, sizeof w), num = 0;
		DEQ(1, 0);
		num >= m ? L = M : R = M - 1;
	}
	printf("%d\n", L);
	return 0;
}
