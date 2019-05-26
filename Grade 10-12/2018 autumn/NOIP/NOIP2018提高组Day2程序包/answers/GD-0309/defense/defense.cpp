#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define LL long long
#define db double
#define ms(i, j) memset(i, j, sizeof i)
#define FN2 "defense"
using namespace std;

namespace flyinthesky {
	
	const int MAXN = 100000 + 5;
	const LL ZINF = 10000000001ll;
	
	struct edge {int v, nxt;} ed[MAXN];
	
	int n, m, pi[MAXN], en, hd[MAXN], vis[MAXN][5];
	LL dp[MAXN][5];
	
	void ins(int u, int v) {
		ed[++en] = (edge){v, hd[u]}, hd[u] = en;
	}
	
	void dfs(int u, int fa) {
		int fl = 0, fl2 = 0;
		LL sumd = 0ll;
		dp[u][1] = pi[u], dp[u][0] = 0, dp[u][2] = ZINF;
		for (int i = hd[u]; i > 0; i = ed[i].nxt) {
			edge &e = ed[i];
			if (e.v != fa) {
				fl = 1;
				dfs(e.v, u);
				if (vis[e.v][2]) ++fl2;
				LL tmp2 = ZINF;
				if (!vis[e.v][0]) tmp2 = min(dp[e.v][0], tmp2);
				if (!vis[e.v][1]) tmp2 = min(dp[e.v][1], tmp2);
				if (!vis[e.v][2]) tmp2 = min(dp[e.v][2], tmp2);
				sumd += tmp2;
				LL tmp = ZINF;
				if (!vis[e.v][0]) tmp = min(dp[e.v][0], tmp);
				if (!vis[e.v][1]) tmp = min(dp[e.v][1], tmp);
				if (!vis[e.v][2]) tmp = min(dp[e.v][2], tmp);
				dp[u][1] += tmp;
				dp[u][0] += dp[e.v][2];
			}
		}
	//	cerr << "$$$" << u << " " << sumd << endl;
		for (int i = hd[u]; i > 0; i = ed[i].nxt) {
			edge &e = ed[i];
			if (e.v != fa) {
				LL gg = ZINF;
				if (!vis[e.v][0]) gg = min(dp[e.v][0], gg);
				if (!vis[e.v][1]) gg = min(dp[e.v][1], gg);
				if (!vis[e.v][2]) gg = min(dp[e.v][2], gg);
				if (!vis[e.v][1]) dp[u][2] = min(dp[u][2], dp[e.v][1] + sumd - gg);
			}
		}
		if (fl2) dp[u][0] = ZINF;
		if (!fl) dp[u][2] = ZINF;
	}
	
	void clean() {
		en = 0, ms(hd, -1);
	}
	int solve() {
		char ch[10]; scanf("%d%d%s", &n, &m, ch);
		for (int i = 1; i <= n; ++i) scanf("%d", &pi[i]);
		clean();
		for (int u, v, i = 1; i < n; ++i) scanf("%d%d", &u, &v), ins(u, v), ins(v, u);
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) vis[j][0] = vis[j][1] = vis[j][2] = 0;
			int a, x, b, y; scanf("%d%d%d%d", &a, &x, &b, &y);
			if (x == 0) vis[a][1] = 1; else vis[a][0] = vis[a][2] = 1;
			if (y == 0) vis[b][1] = 1; else vis[b][0] = vis[b][2] = 1;
			int st = 1;
			for (int j = 2; j <= n; ++j) if (!vis[j]) st = j;
			dfs(st, 0);
			LL ans = ZINF;
			if (!vis[st][1]) ans = min(ans, dp[st][1]);
			if (!vis[st][2]) ans = min(ans, dp[st][2]);
			if (ans >= ZINF) printf("-1\n"); else printf("%lld\n", ans);
		}
		return 0;
	}
}
int main() {
	freopen(FN2".in", "r", stdin), freopen(FN2".out", "w", stdout);
	flyinthesky::solve();
	fclose(stdin), fclose(stdout);
}
