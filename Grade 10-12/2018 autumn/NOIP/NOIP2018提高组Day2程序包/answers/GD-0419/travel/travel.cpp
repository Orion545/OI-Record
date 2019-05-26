#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, e[5010][5010], fa[5010], num = 0, del = 0, ans[5010], tmp[5010];
bool v[5010];
struct cir
{
	int x, y;
} c[5010];

void dfs(int x, int *ans)
{
	ans[++ans[0]] = x;
	v[x] = 1;
	for (int i = 1; i <= e[x][0]; i++)
	{
		int y = e[x][i];
		if (v[y] || ((x == c[del].x && y == c[del].y) || (x == c[del].y && y == c[del].x))) continue;
//		printf("%d %d %d %d\n", x, y, c[del].x, c[del].y);
		dfs(y, ans);
	}
}
bool fdcir(int x)
{
	if (v[x])
	{
		int hh = fa[x];
		num++;
		c[num].x = x;
		c[num].y = fa[x];
		while (hh != x)
		{
			num++;
			c[num].x = hh;
			c[num].y = fa[hh];
			hh = fa[hh];
		}
		return 1;
	}
	v[x] = 1;
	for (int i = 1; i <= e[x][0]; i++)
	{
		int y = e[x][i];
		if (y == fa[x]) continue;
		fa[y] = x;
		if (fdcir(y)) return 1;
	}
	return 0;
}
bool chk()
{
	for (int i = 1; i <= n; i++)
		if (tmp[i] < ans[i])
			return 1;
		else if (tmp[i] > ans[i])
			return 0;
	return 0;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(e, 0, sizeof(e));
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x][++e[x][0]] = y;
		e[y][++e[y][0]] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		sort(e[i] + 1, e[i] + 1 + e[i][0]);
	}
	memset(v, 0, sizeof(v));
	if (fdcir(1))
	{
		for (int i = 1; i <= num; i++)
//			printf("%d %d\n", c[i].x, c[i].y);
		ans[1] = 2;
		for (int i = 1; i <= num; i++)
		{
			memset(v, 0, sizeof(v));
			del = i;
			tmp[0] = 0;
			dfs(1, tmp);/*
			printf("%d %d\n", c[del].x, c[del].y);
			for (int i = 1; i <= n; i++)
				printf("%d ", tmp[i]);
			puts("");*/
			if (chk())
			{
				for (int i = 1; i <= n; i++)
					ans[i] = tmp[i];
			}
		}
	}
	else
	{
		memset(v, 0, sizeof(v));
		dfs(1, ans);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	puts("");
}
