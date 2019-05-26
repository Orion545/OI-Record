#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
#define ri rd<int>
#define rep(i,a,b) for (int i = (a), _ = (b); i <= _; ++i)
#define per(i,a,b) for (int i = (a), _ = (b); i >= _; --i)
#define For(i,a,b) for (int i = (a), _ = (b); i < _; ++i)
const int maxN = 50007;
const int inf = 1e9 + 7;

template<class T> T rd() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

struct Vec {
	int g[maxN], te;
	struct edge {int y, d, nxt;} e[maxN << 1];
	Vec() { te = 0; memset(g, 0, sizeof g); }

	inline void push(int x, int y, int d) {
		e[++te] = (edge){y, d, g[x]}; g[x] = te;
	}

	inline void link(int x, int y, int d) {
		push(x, y, d);
		push(y, x, d);
	}

	inline edge& operator [] (int x) { return e[x]; }
}e;

int n, m, lim, cnt;
int q[maxN], tt = 0;
bool use[maxN];
int lis[maxN], tl;

int dfs(int x, int fa) {
	int bg = tt + 1;
	for (int p = e.g[x]; p; p = e[p].nxt) if (e[p].y != fa) {
		q[++tt] = e[p].d + dfs(e[p].y, x);
	}
	int ed = tt;
	tt = bg - 1;
	int res = 0;
	sort(q+bg, q+ed+1);
	for (; bg <= ed && q[ed] >= lim; --ed) ++cnt;

	rep (i, bg, ed) use[i] = false;
	tl = 0;
	for (int i = bg, j = ed, num = 0; i <= ed; ++i) {
		for (; bg <= j && q[j] + q[i] >= lim; --j) ++num;
		if (i > j) {
			if (num - (ed - i) >= 2) {
				lis[++tl] = i;
				use[i] = true;
				num -= 2;
				++cnt;
			}
		}
	}
	for (int i = bg, j = tl; j >= 1 && i <= ed; ++i) 
	if (!use[i] && q[i] + q[lis[j]] >= lim) {
	//	assert(i <= lis[j]);
		use[i] = true;
		--j;
	}
	per (i, ed, bg) if (!use[i]) return q[i];
	return 0;
}

bool chk() {
	cnt = 0, tt = 0;
	dfs(1, 0);
	return cnt >= m;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);

	n = ri();
	m = ri();

	int V = 0;

	For (i, 1, n) {
		int x = ri(), y = ri(), z = ri();
		e.link(x, y, z);
		V += z;
	}

	int l = 1, r = V / m;
	while (l < r) {
		lim = (l + r) / 2 + 1;
		if (chk()) {
			l = lim;
		}
		else {
			r = lim - 1;
		}
	}
	printf("%d\n", l);

	return 0;
}

