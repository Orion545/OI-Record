#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cctype>
#include<cmath>
using namespace std;
bool vis[5005]={};
//int dfn[5005]={};
//int low[5005]={};
//bool col[5005]={};
int Ett[5005][5005]={};
int n, m;
//int dfstot = 0;
//int stk[5005]={};
//int q[5005]={};
//void tarjan(int x, int fa) {
//	dfn[x] = low[x] = ++dfstot;
//	stk[++stk[0]] = x;
//	for (int v, i = 1; i <= Ett[x][0]; ++i) {
//		v = Ett[x][i];
//		if (v == fa) continue;
//		if (!dfn[v]) {
//			tarjan(v, x);
//			low[x] = min(low[x], low[v]);
//		} else if (dfn[v] < low[x]) {
//			low[x] = dfn[v];
//		}
//	}
//	if (dfn[x] == low[x]) {
//		while (stk[0] != x) {
//			if (stk[0] != x) q[++q[0]] = stk[stk[0]], col[q[q[0]]] = 1;
//			--stk[0];
//		}
//	}
//}
//int mx[5005]={};
//void pred(int x) {	
//	mx[x] = x;
//	for (int i = 1; i <= Ett[x][0]; ++i) {
//		if (col[Ett[x][i]]) continue;
//		pred(Ett[x][i]);
//		mx[x] = max(mx[x], mx[Ett[x][i]]);
//	}
//}
//void ring(int x, int fa, int highmark) {
//	for (int i = 1; i <= Ett[x][0]; ++i) {
//		if (col[Ett[x][i]] && Ett[x][i] != fa && Ett[x][i] != q[1]) {
//			mx[Ett[x][i]] = max(mx[Ett[x][i]], highmark);
//			ring(Ett[x][i], x, max(highmark, Ett[x][i]));
//		}
//	}
//}
void dfs(int x) {
	printf("%d ", x);
	vis[x] = 1;
	for (int i = 1; i <= Ett[x][0]; ++i) {
		if (vis[Ett[x][i]]) continue;
		dfs(Ett[x][i]);
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int u, v, i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		Ett[u][++Ett[u][0]] = v;
		Ett[v][++Ett[v][0]] = u;
	}
	for (int i = 1; i <= n; ++i) {
		sort(Ett[i]+1, Ett[i]+1+Ett[i][0]);
	}
//	if (m == n) {
//		tarjan(1, 0);
//		for (int i = 1; i <= q[0]; ++i) {
//			pred(q[i]);
//		}
//		ring(q[1], 0, q[1]);
//		for (int i = 1; i <= q[0]; ++i) {
//			if (mx[q[i]])
//		}
//	}
	dfs(1);
	return 0;
}
