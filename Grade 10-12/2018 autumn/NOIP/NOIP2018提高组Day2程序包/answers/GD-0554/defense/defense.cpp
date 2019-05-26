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
const int maxn = 100000 + 10, INF = 0x3f3f3f3f;
struct E{int v, n;} e[maxn << 1];
int h[maxn], ec = 1;
inline void add_edge(int u, int v){e[ec] = (E){v, h[u]}; h[u] = ec++;}
int a, x, b, y;
int dp[maxn][2], p[maxn];
bool flag;
void dfs(int u = 1, int f = 0)
{
	dp[u][0] = 0; dp[u][1] = 0;
	for(int i = h[u], v = e[i].v; i; i = e[i].n, v = e[i].v) if(v != f)
	{
		dfs(v, u);
		if(dp[v][1] != -1 && dp[u][0] != -1) dp[u][0] += dp[v][1];
		else dp[u][0] = -1;
		int tmp = INF;
		if(dp[v][0] != -1)
		{
			tmp = min(dp[v][0], tmp);
		}
		if(dp[v][1] != -1) tmp = min(dp[v][1], tmp);
		if(dp[v][0] == -1 && dp[v][1] == -1) tmp = -1;
		if(tmp != -1) dp[u][1] += tmp;
	}
	if((u == a && x == 0) || (u == b && y == 0)) dp[u][1] = -1;
	if((u == a && x == 1) || (u == b && y == 1)) dp[u][0] = -1;
	if(dp[u][1] != -1) dp[u][1] += p[u];
	if(dp[u][1] == -1 && dp[u][0] == -1) flag = true;
}
int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int n, m; read(n, m);
	char type[5]; scanf("%s", &type);
	for(int i = 1; i <= n; ++i) read(p[i]);
	for(int i = 1, u, v; i < n; ++i) read(u, v), add_edge(u, v), add_edge(v, u);
	while(m--)
	{
		read(a, x), read(b, y);
		flag = false;
		dfs();
		if(flag){puts("-1");}
		else if(dp[1][0] == -1) printf("%d\n", dp[1][1]);
		else if(dp[1][1] == -1) printf("%d\n", dp[1][0]);
		else printf("%d\n", min(dp[1][0], dp[1][1]));
	}
	return 0;
}
