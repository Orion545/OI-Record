#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, u, v, z, k, head[5005], ans[5005], minn[5005], vis[5005];

bool bad[5005][5005], used[5005][5005];

struct edge {
	int u, v;
	bool operator < (const edge &A) const {
		if(u == A.u) return v < A.v;
		return u < A.u;
	}
}e[10005];

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
	e[++z].u = u, e[z].v = v;
}

inline void dfs(int u) {
	ans[++k] = u;
	for(int i=head[u]; e[i].u==u; i++) {
		int v=e[i].v;
		if(bad[u][v]) continue;
		if(!vis[v]) vis[v] = 1, dfs(v);
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	read(n), read(m);
	for(int i=1; i<=m; i++) {
		read(u), read(v);
		addedge(u, v), addedge(v, u);
	}
	sort(e+1, e+1+z);
	for(int i=z; i>0; i--) head[e[i].u] = i;
	if(m == n - 1) {
		vis[1] = 1, dfs(1);
		for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	}
	else {
		for(int i=1; i<=z; i++) {
			k = 0;
			memset(vis, 0, sizeof(vis));
			u = e[i].u, v = e[i].v;
			if(used[u][v]) continue;
			bad[u][v] = bad[v][u] = used[u][v] = used[v][u] = 1;
			vis[1] = 1, dfs(1);
			bad[u][v] = bad[v][u] = 0;
			if(k == n) {
				if(minn[1] == 0) memcpy(minn, ans, sizeof(minn));
				else {
					for(int i=1; i<=n; i++) {
						if(ans[i] < minn[i]) {
							memcpy(minn, ans, sizeof(minn));
							break;
						}
						if(ans[i] > minn[i]) break;
					}
				}
			}
		}
		for(int i=1; i<=n; i++) printf("%d ", minn[i]);
	}
	return 0;
}

