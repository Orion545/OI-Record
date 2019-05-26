#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#define LL long long
#define db double
#define ms(i, j) memset(i, j, sizeof i)
#define FN2 "travel"
using namespace std;

namespace flyinthesky {
	
	const int MAXN = 5000 + 5;
	
	int n, m, stp[MAXN], cnt, ans[MAXN];
	vector<int > G[MAXN];
	vector<int > bh[MAXN];
	
	void ins(int u, int v, int ith) {G[u].push_back(v), bh[u].push_back(ith);}
	
	void dfs1(int u, int fa) {
		stp[++cnt] = u;
		for (int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			if (v == fa) continue ;
			dfs1(v, u);
		}
	}
	
	int nno, vis[MAXN];
	void dfs2(int u, int fa) {
		vis[u] = 1, stp[++cnt] = u;
		for (int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			if (v == fa) continue ;
			if (vis[v]) continue ;
			if (bh[u][i] == nno) continue ;
			dfs2(v, u);
		}
	}
	
	void clean() {
	}
	int solve() {
		clean();
		scanf("%d%d", &n, &m);
		for (int u, v, i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			ins(u, v, i), ins(v, u, i);
		}
		for (int i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end());
		if (m == n - 1) {
			cnt = 0;
			dfs1(1, 0);
			for (int i = 1; i <= n; ++i) printf("%d ", stp[i]);
		} else {
			for (int i = 1; i <= n; ++i) ans[i] = n + 1;
			for (int i = 1; i <= m; ++i) {
				cnt = 0, nno = i;
				for (int j = 0; j <= n; ++j) vis[j] = 0;
				dfs2(1, 0);
				if (cnt != n) continue ;
				for (int j = 1; j <= n; ++j) if (stp[j] < ans[j]) {
					for (int k = 1; k <= n; ++k) ans[k] = stp[k];
					break;
				}  else if (stp[j] > ans[j]) break ;
			}
			for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
		}
		return 0; 
	}
}
int main() {
	freopen(FN2".in", "r", stdin), freopen(FN2".out", "w", stdout);
	flyinthesky::solve();
	fclose(stdin), fclose(stdout);
}
