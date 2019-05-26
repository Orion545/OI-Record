#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define LL long long
#define db double
#define ms(i, j) memset(i, j, sizeof i)
#define FN2 "track"
using namespace std;

namespace flyinthesky {
	
	const int MAXN = 50000 + 5;
	
	struct edge {int v, l, nxt; } ed[MAXN * 2];
	
	int n, m, en, hd[MAXN];
	int zjst, zjed, dis[MAXN], ans; // m = 1
	
	void ins(int u, int v, int l) {
		ed[++en] = (edge){v, l, hd[u]}, hd[u] = en;
	}
	void dfs1(int u, int fa) {
		for (int i = hd[u]; i > 0; i = ed[i].nxt) {
			edge &e = ed[i];
			if (e.v != fa) {
				dis[e.v] = dis[u] + e.l, dfs1(e.v, u);
			}
		}
	}
	int dfs2(int u, int fa) {
		int fl = 0;
		if (u == zjed) return true;
		for (int i = hd[u]; i > 0; i = ed[i].nxt) {
			edge &e = ed[i];
			if (e.v != fa) {
				int gg = dfs2(e.v, u);
				if (gg) fl = 1, ans += e.l; 
			}
		}
		return fl;
	}
	
	void clean() {
		ms(hd, -1), en = 0;
	}
	int solve() {
		scanf("%d%d", &n, &m);
		clean();
		for (int a, b, l, i = 1; i < n; ++i) {
			scanf("%d%d%d", &a, &b, &l);
			ins(a, b, l), ins(b, a, l);
		}
		if (m == 1) {
			
			ms(dis, 0);
			dfs1(1, 0);
			zjst = 1;
			for (int i = 2; i <= n; ++i) if (dis[i] > dis[zjst]) zjst = i;
			
			ms(dis, 0);
			dfs1(zjst, 0);
			zjed = 1;
			for (int i = 2; i <= n; ++i) if (dis[i] > dis[zjed]) zjed = i;
			
			ans = 0;
			dfs2(zjst, 0);
			
			printf("%d\n", ans);
		}
		return 0;
	}
}
int main() {
	freopen(FN2".in", "r", stdin), freopen(FN2".out", "w", stdout);
	flyinthesky::solve();
	fclose(stdin), fclose(stdout);
	return 0;
}
