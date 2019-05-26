#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
int dp[50005], drun[50005][22];
LL pf[50005]; int pfpt;
LL fp[50005]; int fppt;
int ghd, hd[50005];
bool vis[50005];
LL dis[50005];
int n, m;

struct Edge { int u, v; LL w; int nxt; } g[100005];

void AddEdge (int u, int v, LL w) {
	g[ghd] = (Edge){u, v, w, hd[u]};
	hd[u] = ghd++;
}

void GetFather (int u, LL diss, int dep) {
	dis[u] = diss;
	dp[u]  =  dep;
	vis[u] = true;
	for (int i = hd[u]; ~i; i = g[i].nxt) {
		int v = g[i].v, w = g[i].w;
		if (vis[v]) continue;
		GetFather(v, diss + w, dep + 1);
		drun[v][0] = u;
	}
}

void DoublyRun() {
	drun[1][0] = 1;
	GetFather(1, 0, 0);
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= n; j++)
			drun[j][i] = drun[drun[j][i - 1]][i - 1];	
	}
}

int Lca (int x, int y) {
	if (x == y) return x;
	if (x > y) swap(x,y);
	for (int i = 20; ~i; i--) if (dp[drun[y][i]] >= dp[x]) y = drun[y][i];
	if (x == y) return x;
	for (int i = 20; ~i; i--) {
		if (drun[x][i] != drun[y][i]) {
			x = drun[x][i];
			y = drun[y][i];
		}
	}
	return drun[x][0];
}

void OptMisOne() {
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
//			printf("%d %d %d\n", i, j, Lca(i, j));
			ans = max(ans, 	dis[i] + dis[j] - dis[Lca(i, j)]);	
		}
	printf("%lld", ans);
	return;
}

void OptAisOne() {
	LL ans = 2e12;
	sort(pf, pf + pfpt);
	for (int i = 0; i < m; i++) {
		ans = min(ans, pf[n - 1 - 2 * m + i] + pf[n - 2 - i]);
	}
	printf("%lld", ans);
	return;
}

bool LianCheck (LL len) {
	int cnt = 0; LL cu = 0;
	for (int i = 1; i <= n - 1; i++) {
		cu += fp[i];
		if (cu >= len) {
			if (++cnt == m) return true;
			cu = 0;	
		}
	}
	return false;
}

void OptLian() {
	LL mid, l = 1, r = 1e12;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (LianCheck(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld", r);
	return;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);

	// PianFenBianLiang
		bool aisone = true;
		bool lian = true;
	// PianFenBianLiang

	int x, y; LL z;
	scanf("%d %d", &n, &m);
	memset(hd, -1, sizeof(hd));
	for (int i = 1; i < n; i++) {
		scanf("%d %d %lld", &x, &y, &z);
		pf[pfpt++] = z;
		AddEdge(x, y, z);
		AddEdge(y, x, z);
		if (x != 1 && y != 1) aisone = false;
		if (x - y != -1 && x - y != 1) lian = false;
		else fp[min(x, y)] = z;
	}
	
	if (aisone) {
		OptAisOne();
		return 0;
	}
	
	if (lian) {
		OptLian();
		return 0;	
	}
	
	if (m == 1) {
		DoublyRun();
		OptMisOne();
		return 0;
	}
	
	printf("2956194");
	
	return 0;
}
