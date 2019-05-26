#include <algorithm>
#include <cstdio>
#include <vector>
using std::vector;
using std::sort;

const int MAXN = 5010;

struct EDGE { int v; EDGE *n; } edge[MAXN*2], *head[MAXN];
int n, m, ce, val[MAXN*2], mi=MAXN;
bool vis[MAXN], lp[MAXN];

void AddEdge(const int u, const int v) {
	edge[ce].v = v;
	edge[ce].n = head[u];
	head[u] = edge + ce;
	ce ++;
}

// void update(const int p, const int v) {
// 	int i = p + n, x;
// 	for (val[i]=v, i>>=1; i; i>>=1) {
// 		x = (val[i << 1 | 1] < val[i << 1]) ? (i << 1 | 1) : (i << 1);
// 		val[i] = val[x];
// 	}
// }

void dfs1(const int u) {
	printf("%d ", u);
	vis[u] = true;
	vector<int> child;
	for (EDGE *e=head[u]; e; e=e->n)
		if (!vis[e->v])
			child.push_back(e->v);
	sort(child.begin(), child.end());
	for (vector<int>::const_iterator iter=child.begin(); iter != child.end(); iter ++)
		dfs1(*iter);
}

int find_loop(const int u, const int f) {
	int x;
	vis[u] = true;
	for (EDGE *e=head[u]; e; e=e->n) {
		if (e->v == f)
			continue;
		if (vis[e->v]) {
			lp[u] = true;
			return e->v;
		}
		x = find_loop(e->v, u);
		if (x) {
			lp[u] = true;
			return (x == u) ? 0 : x;
		}
	}
	return 0;
}

void dfs2(const int u) {
	printf("%d ", u);
	vis[u] = true;
	vector<int> child;
	for (EDGE *e=head[u]; e; e=e->n)
		if (!vis[e->v])
			child.push_back(e->v);
	sort(child.begin(), child.end());

	if (!lp[u]) {
		for (vector<int>::const_iterator iter=child.begin(); iter != child.end(); iter ++)
			dfs2(*iter);
	}

	if (mi == MAXN) {
		for (vector<int>::const_iterator iter=child.begin(); iter != child.end(); iter ++) {
			if (!lp[*iter]) continue;
			if (mi == MAXN + 1) mi = *iter;
			if (mi == MAXN) mi ++;
		}
	}

	for (vector<int>::const_iterator iter=child.begin(); iter != child.end(); iter ++) {
		if (lp[*iter] && iter + 1 == child.end() && *iter > mi) {
			// printf("[%d] Break on %d (%d)\n", u, *iter, mi);
			mi = MAXN;
			break;
		}
		if (!vis[*iter])
			dfs2(*iter);
	}

}

int main() {
	freopen("travel.in" , "r", stdin );
	freopen("travel.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=1, u, v; i<=m; i++) {
		scanf("%d %d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	if (m == n - 1) {
		dfs1(1);
		puts("");
	}
	else {
		find_loop(1, 1);
		for (int i=1; i<=n; i++)
			vis[i] = false;
		dfs2(1);
		puts("");
		// for (int i=1; i<=n; i++)
		// 	printf("%d ", lp[i]);
	}

	return 0;
}
