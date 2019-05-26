#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
template<class T> inline void read(T&x)
{
	char c = getchar(); T p = 1, n = 0;
	while(c < '0' || c > '9') {if(c == '-') p = -1; c = getchar();}
	while(c >= '0' && c <= '9'){n = n * 10 + c - '0'; c = getchar();}
	x = p * n;
}
template<class T, class U> inline void read(T&x, U&y){read(x), read(y);}
template<class T, class U, class V> inline void read(T&x, U&y, V&z){read(x), read(y), read(z);}
const int maxn = 1e5;
struct E{int v, n, w;} e[maxn << 1];
int h[maxn], ec = 1;
inline void add_edge(int u, int v, int w){e[ec] = (E){v, h[u], w}; h[u] = ec++;}
int M, dp[maxn], len[maxn], a[maxn], b[maxn];
bool vis[maxn];
void dfs(int u = 1, int f = 0)
{
	int firstmax = 0, secondmax = 0, thirdmax = 0; dp[u] = len[u] = 0;
	for(int i = h[u], v = e[i].v; i; i = e[i].n, v = e[i].v) if(v != f)
	{
		dfs(v, u);
		dp[u] += dp[v];
		int tmp = e[i].w + len[v];
		if(tmp >= M) ++dp[u];
		else
		{
			a[v] = tmp;
		}
	}
	int bc = 0;
	for(int i = h[u], v = e[i].v; i; i = e[i].n, v = e[i].v) if(v != f)
		b[bc++] = a[v];
	sort(b, b + bc);
	for(int i = 0; i < bc; ++i) vis[i] = false;
	int lcur = 0, rcur = bc - 1;
	for(int i = 0; i < bc; ++i)
	if(b[i] + b[rcur] >= M && rcur > i) ++dp[u], vis[i] = vis[rcur] = true, --rcur;
	for(int i = bc - 1; ~i; --i) if(!vis[i]) {
	len[u] = b[i]; break;}
}
int deg[maxn];
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int n, m; read(n, m);
	for(int i = 1, u, v, w; i < n; ++i) read(u, v, w), add_edge(u, v, w), add_edge(v, u, w), ++deg[u], ++deg[v];
	int L = 1, R = 500000000;
	while(L < R)
	{
		M = (L + R) >> 1;
		dfs();
		if(dp[1] < m) R = M;
		else L = M + 1;
	}
	printf("%d\n", L - 1);
//	M = 26282; dfs(); printf("%d\n", dp[1]);
	return 0;
}
