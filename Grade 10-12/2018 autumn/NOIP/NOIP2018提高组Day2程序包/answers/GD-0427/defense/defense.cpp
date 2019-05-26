#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 100010;
const long long oo = 21000000000000LL;

long long f[N][2];

struct ed {
	int nx, v;
} e[(N<<1)];

int tot = 0, he[N];
void ad(int u, int v) {
	e[++tot].nx = he[u], e[tot].v = v, he[u] = tot;
}
int a[N];
void dfs(int x, int fa) {
	if(f[x][0] != oo) f[x][0] = 0;
	if(f[x][1] != oo) f[x][1] = a[x];
	for (int h=he[x]; h!=-1; h=e[h].nx) {
		if(e[h].v == fa) continue;
		dfs(e[h].v, x);
		if(f[x][0] != oo) f[x][0] += f[e[h].v][1];
		if(f[x][1] != oo) f[x][1] += min(f[e[h].v][0], f[e[h].v][1]);
	}
}
char tmp[5];
int main() {
	
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	memset(he, -1, sizeof(he));
	
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", tmp+1);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	
	for (int i=1; i<n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		ad(u, v), ad(v, u);
	}
	
	for (int i=1; i<=m; i++) {
		int a, x, b, y;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		memset(f, 0, sizeof(f));
		f[a][x^1] = oo, f[b][y^1] = oo;	
		dfs(1, 0);
		long long an = min(f[1][0], f[1][1]);
		if(an >= oo) { printf("-1\n"); }
		else printf("%lld\n", an);
	}
	

	return 0;
}
