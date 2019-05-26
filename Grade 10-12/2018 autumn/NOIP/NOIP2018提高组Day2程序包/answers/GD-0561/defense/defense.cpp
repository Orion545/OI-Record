#include <cstdio>
#include <cstring>
#include <string>
#define ll long long
#define N 200005
using namespace std;

struct arr
{
	int nxt,to;
}a[N];
int n,m,l,ls[N],g[N];
ll val[N],f[N][2];

void add(int x, int y)
{
	a[++l].nxt = ls[x];
	a[l].to = y;
	ls[x] = l;
}

ll fmin(ll x, ll y){return x<y?x:y;}

void dfs(int x, int fa)
{
	if (g[x] != 0) f[x][1] = val[x];
	for (int i = ls[x]; i; i = a[i].nxt)
		if (a[i].to != fa)
		{
			dfs(a[i].to, x);
			if (g[x] != 1 && g[a[i].to] != 0) f[x][0] += f[a[i].to][1];
			if (g[x] != 0)
			if (g[a[i].to] == -1)
			{
				f[x][1] += fmin(f[a[i].to][0], f[a[i].to][1]);
			}
			else if (g[a[i].to] == 0) f[x][1] += f[a[i].to][0];
				else f[x][1] += f[a[i].to][1];
		}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d", &n, &m);
	char c[4];
	scanf("%s", c);
	for (int i = 1; i <= n; i++) scanf("%lld", &val[i]),g[i] = -1;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	while(m--)
	{
		for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = 0;
		int aa,xx,bb,yy;
		scanf("%d%d%d%d", &aa, &xx, &bb, &yy);
		g[aa] = xx;
		g[bb] = yy;
		dfs(1, 0);
		if (!f[1][0] && !f[1][1]) f[1][0] = f[1][1] = -1;
		if (g[1] == -1) printf("%lld\n", fmin(f[1][0], f[1][1]));
		if (g[1] == 0) printf("%lld\n", f[1][0]);
		if (g[1] == 1) printf("%lld\n", f[1][1]);
		g[aa] = g[bb] = -1;
	}
	fclose(stdin);
	fclose(stdout);
}
