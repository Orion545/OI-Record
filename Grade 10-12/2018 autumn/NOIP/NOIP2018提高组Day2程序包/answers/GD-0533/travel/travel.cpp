#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
int n, m, apt, ans[5005];
int clk, dfn[5005], low[5005];
bool g[5005][5005];
bool vis[5005];
bool blk[5005];
bool inS[5005];
int loth[5005];
int roth[5005];
stack<int> S;
bool inblk;
int bsz;

bool Tarjan (int u, int fa) {
	low[u] = dfn[u] = ++clk;
	S.push(u); inS[u] = true;
	for (int v = 1; v <= n; v++) {
		if (!g[u][v]) continue;
		if (v == fa) continue;
		if (!dfn[v]) {
			if (Tarjan(v, u)) return true;
			low[u] = min(low[u], low[v]);
		} else if (inS[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		if (S.top() == u) {
			inS[u] = false;
			S.pop();
			return false;
		} else {
			bool flg = false;
			int cu = -1;
			do {
				cu = S.top();
				S.pop();
				if (!flg) {
					roth[cu] = u;
					loth[u] = cu;
					loth[cu] = S.top();
					roth[S.top()] = cu;
					flg = true;
				} else if (cu != u) {
					roth[S.top()] = cu;
					loth[cu] = S.top();
				}
				bsz++;
				blk[cu] = true;
				inS[cu] = false;
			} while (cu != u);
			return true;
		}
	}
	return false;
}

void Dfs (int u) ;

void ClOpt (int rt) {
	int dep = 0;
	inblk = true;
	vis[rt] = true;
	ans[apt++] = rt;
	priority_queue<int> todo;
	for (int i = 1; i <= n; i++)
		if (g[rt][i]) { todo.push(-i); }
	todo.push(-loth[rt]);
	todo.push(-roth[rt]);
	while (!todo.empty()) {
		int v = -todo.top();
		todo.pop();
		if (vis[v]) continue;
		if (!blk[v]) {
			if (dep == 0) { 
				Dfs(v);
			} else if (dep == 1) {
				Dfs(v);
				dep = 2;
			} else if (dep == 2) {
				Dfs(v);
			} else if (dep == 3) {
				todo.push(v);
			} else if (dep == 4) {
				Dfs(v);
			}
		} else {
			if (dep == 0) {
				blk[v] = false;
				Dfs(v);
				dep = 1;
				if (--bsz == 0) dep = 4;
			} else if (dep == 1) {
				blk[v] = false;
				Dfs(v);
				if (--bsz == 0) dep = 4;
			} else if (dep == 2) {
				blk[v] = false;
				Dfs(v);
				dep = 3;
				if (--bsz == 0) dep = 4;
			} else if (dep == 3) {
				blk[v] = false;
				Dfs(v);
				if (--bsz == 0) dep = 4;
			}
			if (!vis[loth[v]]) todo.push(-loth[v]);
			if (!vis[roth[v]]) todo.push(-roth[v]);
		}
	}
}

void Dfs (int u) {
	vis[u] = true;
	ans[apt++] = u;
	for (int v = 1; v <= n; v++) {
		if (!g[u][v]) continue;
		if (vis[v]) continue;
		if (!inblk && blk[v]) {
			ClOpt(v);
			continue;
		} else if (inblk && blk[v]) continue;
		Dfs(v);
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int x, y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		g[x][y] = g[y][x] = true;
	}
	
	Tarjan(1, -1);
//	for (int i = 1; i <= n; i++) printf("{%d %d}", loth[i], roth[i]);
	memset(vis, 0, sizeof(vis));
	if (!blk[1]) Dfs(1);
	else ClOpt(1);
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	
	return 0;
}
