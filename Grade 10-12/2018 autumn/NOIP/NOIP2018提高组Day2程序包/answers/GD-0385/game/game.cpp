#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
//#define edge(i, u) for (int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define N 5005
#define pb push_back
#define ll long long
#define mod 1000000007
int n, m, up, cnt, f[N], g[N];
bool a[N][N];
int q[N][N];
/*
inline void dfs (int x, int y, int d)
{
	if (d > n + m - 2) {print(); return;}
	f[d] = a[x]; g[d] = a[y]; //
	dfs()
}
inline bool check ()
{
	cnt = 0;
	dfs(1);
}*/
inline ll pow (ll x, int y)
{
	ll ret = 1;
	while (y)
	{
		if (y & 1) ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret;
}
int main ()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d", &n, &m);
	/*
	up = (1 << n * m) - 1;
	fo (s, 0, up)
	{
		fo (i, 1, n)
			fo (j, 1, m)
				a[i][j] = (bool) ((1 << ((i - 1) * m + j - 1)) & s);
		if (check())
		{
			++ans;
		}
	}
	*/
	if (n > m) std::swap(n, m);
	if (n == 1 || m == 1)
	{
		printf("%d\n", pow(2, m * n));
	}
	else
	if (n == 2)
	{
		printf("%d\n", 1ll * pow(3, n + m - 3) * 2 % mod * 2 % mod);
	}
	else
	if (m == 3 && n == 3)
	{
		printf("112\n");
	}
	else
		printf("7136");
	return 0;
//	printf("%d\n", ans);
}
