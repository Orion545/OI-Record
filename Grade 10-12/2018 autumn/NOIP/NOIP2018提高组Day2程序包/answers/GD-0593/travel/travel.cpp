#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ri rd<int>
#define rep(i,a,b) for (int i = (a), _ = (b); i <= _; ++i)
#define per(i,a,b) for (int i = (a), _ = (b); i >= _; --i)
#define For(i,a,b) for (int i = (a), _ = (b); i < _; ++i)
const int maxN = 5007;

template<class T> T rd() {
	T x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

struct edge {
	int y, id;
	inline bool operator < (const edge& v) const {
		return y < v.y;
	}
};
vector<edge> adj[maxN];

int n, m, lim;
int ans[maxN], q[maxN], tt;
bool vis[maxN];

void dfs(int x) {
	q[++tt] = x;
	vis[x] = true;
	for (vector<edge>::iterator it = adj[x].begin(); it != adj[x].end(); ++it)
	if (it->id != lim && !vis[it->y])
		dfs(it->y);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	n = ri(), m = ri();
	rep (i, 1, m) {
		int x = ri(), y = ri();
		adj[x].push_back((edge){y, i});
		adj[y].push_back((edge){x, i});
	}
	rep (i, 1, n) sort(adj[i].begin(), adj[i].end());

	bool hv = 0;
	rep (i, 1, n) {
		lim = i;
		tt = 0;
		memset(vis, false, sizeof vis);
		dfs(1);
		if (tt == n) {
			if (!hv) { 
				rep (i, 1, n) ans[i] = q[i];
				hv = true;
			}
			else {
				bool fl = false;
				rep (i, 1, n) {
					if (q[i] > ans[i]) break;
					else if (q[i] < ans[i]) { fl = true; break; }
				}
				if (fl) rep (i, 1, n) ans[i] = q[i];
			}
		}
	}
	rep (i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);

	return 0;
}
