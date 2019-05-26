#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
template<class T> inline void read(T&x)
{
	char c = getchar(); T p = 1, n = 0;
	while(c < '0' || c > '9'){if(c == '-') p = -1; c = getchar();}
	while(c >= '0' && c <= '9'){n = n * 10 + c - '0'; c = getchar();}
	x = p * n;
}
template<class T, class U> inline void read(T&x, U&y){read(x), read(y);}
template<class T, class U, class V> inline void read(T&x, U&y, V&z){read(x), read(y), read(z);}
const int maxn = 5000 + 1000;
struct Edge{int u, v;}e[maxn];
int E[maxn][maxn], cnt[maxn];
int h[maxn], ec = 1;
inline void add_edge(int u, int v){E[u][cnt[u]++] = v;}
int mm[maxn][maxn];
int ans[maxn], ac = 1, n;
int tmp[maxn], tc = 1;
void dfs(int u = 1, int f = 0)
{
	ans[ac++] = u;
	for(int i = 0; i < cnt[u]; ++i) if(E[u][i] != f)
		dfs(E[u][i], u);
}
bool vis[maxn];
void dfs2(int b, int u = 1, int f = 0)
{
	tmp[tc++] = u;
	vis[u] = true;
	for(int i = 0; i < cnt[u]; ++i) if(E[u][i] != f && !vis[E[u][i]] && !((u == e[b].u && E[u][i] == e[b].v) || (u == e[b].v && E[u][i] == e[b].u)))
		dfs2(b, E[u][i], u);
}
bool cmp(int *a, int *b)
{
	for(int i = 1; i <= n; ++i) 
	{
	if(a[i] > b[i]) return false;
	else if(a[i] < b[i])return true;
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int m; read(n, m);
	// int u, v; while(m--) read(u, v), mm[u][v] = mm[v][u] = 1;
	// dfs();
	// for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
	int u, v; for(int i = 0; i < m; ++i) read(u, v), add_edge(u, v), add_edge(v, u), e[i].u = u, e[i].v = v;
	for(int i = 1; i <= n; ++i) sort(E[i], E[i] + cnt[i]);
	if(m == n - 1) dfs();
	else
	{
		for(int i = 1; i <= n; ++i) ans[i] = n + 1;
		for(int i = 0; i < n; ++i)
		{
			tc = 1;
			memset(vis, 0, sizeof vis);
			dfs2(i);
			if(tc == n + 1 && cmp(tmp, ans))
				memcpy(ans, tmp, sizeof tmp);
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}
