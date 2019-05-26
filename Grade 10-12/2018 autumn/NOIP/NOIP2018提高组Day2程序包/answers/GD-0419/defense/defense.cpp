#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, num = 0, fst[100010], p[100010][2], fa[100010];
long long f[100010][2], mns[100010], s1[100010], sum = 0;
struct edge
{
	int x, y, n;
} e[200010];
char type[5];

void ins(int x, int y)
{
	num++;
	e[num].x = x;
	e[num].y = y;
	e[num].n = fst[x];
	fst[x] = num;
}
void dfs(int x)
{
	for (int i = fst[x]; i; i = e[i].n)
	{
		int y = e[i].y;
		if (y == fa[x]) continue;
		fa[y] = x;
		dfs(y);
		mns[x] += min(f[y][0], f[y][1]);
		s1[x] += f[y][1];
	}
	f[x][0] = s1[x] + p[x][0];
	f[x][1] = mns[x] + p[x][1];
}
void upd(int x)
{
	while (x)
	{
		long long f0 = f[x][0], f1 = f[x][1];
		f[x][0] = s1[x] + p[x][0];
		f[x][1] = mns[x] + p[x][1];
		if (f[x][0] == f0 && f[x][1] == f1) break;
		mns[fa[x]] = mns[fa[x]] - min(f0, f1) + min(f[x][0], f[x][1]);
		s1[fa[x]] = s1[fa[x]] - f1 + f[x][1];
		x = fa[x];
	}
}
int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d%s", &n, &m, type);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i][1]);
		sum += p[i][1];
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y);
		ins(y, x);
	}
	{
		dfs(1);
		for (int i = 0; i < m; i++)
		{
			int a, x, b, y;
			scanf("%d%d%d%d", &a, &x, &b, &y);
			int hh1 = p[a][x ^ 1], hh2 = p[b][y ^ 1];
			p[a][x ^ 1] = p[b][y ^ 1] = sum + 1;
			upd(a);
			upd(b);/*
			for (int i = 1; i <= n; i++)
				printf("%lld %lld\n", f[i][0], f[i][1]);*/
			long long hh = min(f[1][0], f[1][1]);
			if (hh > sum) puts("-1");
			else printf("%lld\n", hh);
			p[a][x ^ 1] = hh1;
			p[b][y ^ 1] = hh2;
			upd(a);
			upd(b);
		}
	}
}
