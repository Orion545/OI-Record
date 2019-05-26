#include <cstdio>
#include <cstring>
#define PROGRAM "defense"

inline int read() {
	int x = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c>='0' && c<='9') {
		x = (x<<3) + (x<<1) + (c^'0');
		c = getchar();
	}
	return x;
}

const int N = 2000 + 10;
int n, m, a, x, b, y;
int p[N], f[N], g[N];
struct edge {
	int to, next;
} e[N];
int ee, h[N];
inline void addEdge(int x, int y) {
	e[++ee] = (edge) { y, h[x] };
	h[x] = ee;
}

bool vis[N], flag;
int dfs(int now) {
	vis[now] = true;
	// 0 is allowed
	if (!((now==a && x==1) || (now==b && y==1)))
		f[now] = 0;
	// 1 is allowed
	if (!((now==a && x==0) || (now==b && y==0)))
		g[now] = p[now];
	for (int i=h[now]; i; i=e[i].next)
		if (!vis[e[i].to]) {
			dfs(e[i].to);
			// 0 is allowed
			if (f[now]>=0 &&
				!((now==a && x==1) || (now==b && y==1))) {
				if (g[e[i].to]>=0)
					f[now] += g[e[i].to];
				else f[now] = -1;
			}
			// 1 is allowed
			if (g[now]>=0 && 
				!((now==a && x==0) || (now==b && y==0))) {
				if (f[e[i].to]>=0 && g[e[i].to]>=0)
					g[now] += f[e[i].to]<g[e[i].to]?f[e[i].to]:g[e[i].to];
				else if (f[e[i].to]>=0 || g[e[i].to]>=0)
					g[now] += f[e[i].to] + g[e[i].to] + 1;
				else g[now] = -1;
			}
		}
	vis[now] = false;
}

int main() {
	freopen(PROGRAM".in", "r", stdin);
	freopen(PROGRAM".out", "w", stdout);

	n = read(); m = read(); read();
	for (int i=1; i<=n; ++i) p[i] = read();
	for (int i=1; i<n; ++i) {
		int a=read(), b=read();
		addEdge(a, b);
		addEdge(b, a);
	}
	while (m--) {
		a = read(); x = read();
		b = read(); y = read();
		memset(f, -1, sizeof(f));
		memset(g, -1, sizeof(g));
		dfs(1);
		if (f[1] == -1 && g[1] == -1) puts("-1");
		else if (f[1] == -1 || g[1] == -1) printf("%d\n", f[1]+g[1]+1);
		else printf("%d\n", f[1]<g[1]?f[1]:g[1]);
	}
}
