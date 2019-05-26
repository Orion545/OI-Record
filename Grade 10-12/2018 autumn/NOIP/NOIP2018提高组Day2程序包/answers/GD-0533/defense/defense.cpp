#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, ghd, ehd, p[100005], hd[100005];
bool lt[100005];
long long ans;
int x, y, a, b;

struct Edge {
	int u, v, nxt;
}g[200005], e[200005];

void AddEdge (int u, int v) {
	g[ghd] = (Edge){u, v, hd[u]};
	hd[u] = ghd++;
}

bool Check() {
	for (int i = 0; i < n - 1; i++) {
		if (!lt[e[i].u] && !lt[e[i].v]) return false;
	}
	return true;
}

void Dfs (int dep, long long sum) {
	if (dep > n) {
		if (!Check()) return;
		else ans = min(ans, sum);
		return;	
	}
	if (dep == a) {
		if (x == 0) {
			lt[dep] = false;
			Dfs(dep + 1, sum);
		} else {
			lt[dep] = true;
			Dfs(dep + 1, sum + p[dep]);
			lt[dep] = false;
		}
		return;	
	}
	if (dep == b) {
		if (y == 0) {
			lt[dep] = false;
			Dfs(dep + 1, sum);
		} else {
			lt[dep] = true;
			Dfs(dep + 1, sum + p[dep]);
			lt[dep] = false;
		}
		return;
	}
	lt[dep] = true;
	Dfs(dep + 1, sum + p[dep]);
	lt[dep] = false;
	Dfs(dep + 1, sum);
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w" , stdout);
	
	char s[100];
	scanf("%d %d %s", &n, &m, &s);	
	memset(hd, -1, sizeof(hd));
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		AddEdge(x, y);
		AddEdge(y, x);
		e[ehd++] = (Edge){x, y, 0};
	}
	
	for (int i = 0; i < m; i++) {
		ans = 2e14;
		memset(lt, 0, sizeof(lt));
		scanf("%d %d %d %d", &a, &x, &b, &y);
		Dfs(1, 0);
		if (ans == 2e14) printf("-1\n");
		else printf("%lld\n", ans);
	}
	
	return 0;
}
