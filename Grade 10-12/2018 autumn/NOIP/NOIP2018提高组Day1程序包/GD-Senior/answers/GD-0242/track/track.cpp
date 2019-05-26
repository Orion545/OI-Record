#include <cstdio>
#define PROGRAM "track"
const int INF = 0x3fffffff;

inline int min(int a, int b) { return a<b?a:b; }
inline int max(int a, int b) { return a>b?a:b; }
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

const int N = 50000 + 10;
int i, j, tmpa, tmpb, tmpw;
int n, m, ans, imax, a[N], f[N], g[N];
bool vis[N];

struct Edge {
	int to, w, next;
} e[N];
int ee, h[N];
void addEdge(int a, int b, int w) {
	++ee;
	e[ee].to = b;
	e[ee].w = w;
	e[ee].next = h[a];
	h[a] = ee;
}

// for m = 1
void dfs(int x) {
	int max1=0, max2=0;
	vis[x] = true;
	for (int i=h[x]; i; i=e[i].next)
		if (!vis[e[i].to]) {
			dfs(e[i].to);
			int tmp = f[e[i].to]+e[i].w;
			if (tmp > f[x]) f[x] = tmp;
			if (tmp > max1) { max2 = max1; max1 = tmp; }
			else if (tmp > max2) max2 = tmp;
		}
	g[x] = max1 + max2;
}

// for b = a+1
bool check(int x) {
	int sum=0, res=0;
	for (int i=1; i<=n; ++i) {
		sum += f[i];
		if (sum >= x) {
			sum = 0;
			++res;
		} 
	}
	return res >= m;
}

int main() {
	freopen(PROGRAM".in", "r", stdin);
	freopen(PROGRAM".out", "w", stdout);

	n = read(); m = read();
	if (m == 1) {
		for (i=1; i<n; ++i) {
			tmpa = read();
			tmpb = read();
			tmpw = read();
			addEdge(tmpa, tmpb, tmpw);
			addEdge(tmpb, tmpa, tmpw);
		}
		dfs(1);
		printf("%d\n", g[1]);
	} else {
		int l=0, r=INF, mid;
		for (i=1; i<n; ++i) {
			tmpa = read();
			tmpb = read();
			tmpw = read();
			f[tmpa] = tmpw;
		}
		while (l<r) {
			mid = (l+r) >> 1;
			if (check(mid)) l = mid + 1;
			else r = mid;
		}
		printf("%d", l-1);
	}
}
