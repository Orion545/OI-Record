#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;
#define ri rd<int>
#define rep(i,a,b) for (int i = (a), _ = (b); i <= _; ++i)
#define per(i,a,b) for (int i = (a), _ = (b); i >= _; --i)
#define For(i,a,b) for (int i = (a), _ = (b); i < _; ++i)
const int maxN = 1e5 + 7;
typedef long long LL;
const LL inf = 1LL << 60;

template<class T> T rd() {
	T x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

int n, m;
LL vir[maxN][2];
int pid[maxN];
int tag[maxN][2];

namespace Seg {
	struct Node {
		LL a[2][2];
		Node() { rep (i, 0, 1) rep (j, 0, 1) a[i][j] = inf; }
		Node operator + (const Node &v) const {
			Node res;
			rep (a, 0, 1) rep (b, 0, 1)
			rep (c, 0, 1) rep (d, 0, 1)
			if ((b == 0 && c == 1) || b == 1)
				res.a[a][d] = min(res.a[a][d], this->a[a][b] + v.a[c][d]);
			return res;
		}
	}a[maxN << 2];
	#define lc (x << 1)
	#define rc (x << 1 | 1)

	void pushup(int x) {
		a[x] = a[lc] + a[rc];
	}

	void upd(int x, int l, int r, int to) {
		if (l == r) {
			int u = l;
			a[x].a[0][0] = tag[u][0] ? vir[pid[u]][0] : inf;
			a[x].a[1][1] = tag[u][1] ? vir[pid[u]][1] : inf;
			return;
		}
		int mid = (l + r) >> 1;
		if (to <= mid) upd(lc, l, mid, to);
		else upd(rc, mid+1, r, to);
		pushup(x);
	}

	Node eval(int x, int l, int r, int tl, int tr) {
		if (tl <= l && r <= tr) return a[x];
		int mid = (l + r) >> 1;
		if (tr <= mid) return eval(lc, l, mid, tl, tr);
		if (mid < tl) return eval(rc, mid+1, r, tl, tr);
		return eval(lc, l, mid, tl, mid) + eval(rc, mid+1, r, mid+1, tr);
	}

	inline void upd(int x) { upd(1, 1, n, x); }

	inline void put(int x, int u) { tag[x][u] = 1; upd(1, 1, n, x); }

	inline void ers(int x, int u) { tag[x][u] = 0; upd(1, 1, n, x); }

	inline LL eval(int l, int r, int u) {
		Node ans = eval(1, 1, n, l, r);
		return min(ans.a[u][0], ans.a[u][1]);
	}
}

namespace T {
	struct Vec {
		int g[maxN], te;
		struct edge {int y, nxt;} e[maxN << 1];
		inline void push(int x, int y) { e[++te] = (edge){y, g[x]}; g[x] = te; }
		inline void link(int x, int y) { push(x, y), push(y, x); }
		inline edge& operator [] (int x) { return e[x]; }
	}e;
#define fore(e,u,v) for (int p = e.g[u], v = e[p].y; p; v = e[p = e[p].nxt].y)

	void link(int x, int y) { e.link(x, y); }

	int dep[maxN], pre[maxN], sz[maxN], son[maxN];
	int top[maxN], tid[maxN], bot[maxN], tdfn;

	inline void upd(int x) { Seg::upd(tid[x]); }
	
	inline void put(int x, int u) { Seg::put(tid[x], u); }

	inline void ers(int x, int u) { Seg::ers(tid[x], u); }

	inline LL eval(int x, int u) { Seg::eval(tid[x], tid[bot[x]], u); }

	void dfs1(int x) {
		sz[x] = 1;
		fore (e, x, y) if (y != pre[x]) {
			dep[y] = dep[x] + 1;
			pre[y] = x;
			dfs1(y);
			sz[x] += sz[y];
			if (sz[y] > sz[son[x]]) son[x] = y;
		}
	}

	void dfs2(int x) {
		pid[tid[x] = ++tdfn] = x;
		if (son[x]) {
			top[son[x]] = top[x];
			dfs2(son[x]);
			bot[x] = bot[son[x]];
		}
		else bot[x] = x;
		fore (e, x, y) if (y != pre[x] && y != son[x]) {
			top[y] = y;
			dfs2(y);
			vir[x][1] += min(eval(y, 0), eval(y, 1));
			vir[x][0] += eval(y, 1);
		}
		put(x, 0);
		put(x, 1);
	}

	int LCA(int x, int y) {
		while (top[x] != top[y]) 
			dep[x] > dep[y] ? x = pre[top[x]] : y = pre[top[y]];
		return dep[x] < dep[y] ? x : y;
	}

	void build() {
		dep[1] = 1, pre[1] = 0;
		dfs1(1);
		top[1] = 1, tdfn = 0;
		dfs2(1);
	}

	void gao(int x, int u, int kd) {
		u = !u;
		for (int o = top[x]; pre[o]; o = top[pre[o]]) {
			vir[pre[o]][1] -= min(eval(o, 0), eval(o, 1));
			vir[pre[o]][0] -= eval(o, 1);
			upd(pre[o]);
		}
		if (kd == false) ers(x, u);
		else put(x, u);
		for (int o = top[x]; pre[o]; o = top[pre[o]]) {
			vir[pre[o]][1] += min(eval(o, 0), eval(o, 1));
			vir[pre[o]][0] += eval(o, 1);
			upd(pre[o]);
		}
	}
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);

	n = ri(), m = ri();
	scanf("%*s");
	rep (i, 1, n) vir[i][1] = ri(), tag[i][0] = tag[i][1] = 1;
	For (i, 1, n) {
		int x = ri(), y = ri();
		T::link(x, y);
	}
	T::build();
	rep (i, 1, m) {
		int x = ri(), u = ri();
		int y = ri(), v = ri();
		if (!u && !v && (T::pre[x] == y || T::pre[y] == x)) {
			puts("-1");
			continue;
		}
		if (T::dep[x] < T::dep[y]) swap(x, y), swap(u, v);
		T::gao(x, u, false);
		T::gao(y, v, false);
		printf("%lld\n", min(T::eval(1, 1), T::eval(1, 0)));
		T::gao(x, u, true);
		T::gao(y, v, true);
	}

	return 0;
}
