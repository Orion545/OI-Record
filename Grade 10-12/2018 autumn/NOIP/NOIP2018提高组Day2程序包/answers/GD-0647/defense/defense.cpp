#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k, a, b, x, y, u, v, z;
int vis[2005], head[2005], w[2005], cm[2005], mp[2005][2005];

long long f[2005], g[2005], minn[2005];

char ch;

struct edge {
	int u, v, n;
}e[4005];

inline void read(int &k) {
	int f=1;
	char c=getchar();
	k = 0;
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		k = k * 10 + (c ^ 48);
		c = getchar();
	}
	k *= f;
}

inline void addedge(int u, int v) {
	e[++z].u = u, e[z].v = v, e[z].n = head[u], head[u] = z;
}

inline int dfs(int u) {
	int k=0;
	f[u] = (long long)w[u], g[u] = 0;
	for(int i=head[u]; i; i=e[i].n) {
		int v=e[i].v;
		if(!vis[v]) {
			vis[v] = 1;
			k = dfs(v);
			if(k == 0) f[u] += minn[v], g[u] += f[v];
			if(k == 1) f[u] += g[v], g[u] = f[u];
			if(k == 2) f[u] += f[v], g[u] += f[v];
		}
	}
	minn[u] = min(f[u], g[u]);
	if(k == 0 || k == 2) return cm[u];
	if(k == 1) return 2;
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	read(n), read(m);
	while(ch < 'A' || ch > 'C') ch = getchar();
	read(k);
	for(int i=1; i<=n; i++) read(w[i]);
	for(int i=1; i<n; i++) {
		read(u), read(v);
		mp[u][v] = mp[v][u] = 1;
		addedge(u, v), addedge(v, u);
	}
	while(m--) {
		memset(vis, 0, sizeof(vis));
		memset(f, 127, sizeof(f));
		memset(g, 127, sizeof(g));
		memset(minn, 127, sizeof(minn));
		read(a), read(x), read(b), read(y);
		cm[a] = x + 1, cm[b] = y + 1;
		if(mp[a][b] && (x | y) == 0) printf("-1\n");
		else {
			vis[1] = 1;
			int res=dfs(1);
			if(res == 0) {
				if(cm[1] == 2) printf("%lld\n", f[1]);
				if(cm[1] == 1) printf("%lld\n", g[1]);
				if(cm[1] == 0) printf("%lld\n", minn[1]);
			}
			if(res == 1) {
				if(cm[1] == 2) printf("-1\n");
				else printf("%lld\n", g[1]);
			}
			if(res == 2) {
				if(cm[1] == 1) printf("-1\n");
				else printf("%lld\n", f[1]);
			}
		}
		cm[a] = cm[b] = 0;
	}
	return 0;
}
