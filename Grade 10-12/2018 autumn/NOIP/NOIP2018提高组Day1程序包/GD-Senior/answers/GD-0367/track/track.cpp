#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <math.h>

#define MAXN 50005

using namespace std;

struct {
	int next;
	int len;
	int to;
} edge[MAXN * 2];

int n, m, cnt;
int head[MAXN];
int len[MAXN][16];

void add_edge(int a, int b, int c)
{
	cnt++;
	edge[cnt].next = head[a];
	head[a] = cnt;
	edge[cnt].len = c;
	edge[cnt].to = b;
}
void solve_f()
{
	int dist[10][10];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) dist[i][j] = 99999;
			else dist[i][j] = 0;
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = dist[b][a] = c;
	}
	for (int k = 1; k <= n; k++)
		for (int i = k + 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int ans = 0;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (dist[i][j] < 10000)
				ans = max(ans, dist[i][j]);
	cout << ans;
}
bool check_b(int ch)
{
	int tote = 0, sum = 0, u = 1;
	for (int i = head[1]; i != 0; i = head[edge[i].to])
	{
		if (edge[i].to != u + 1) break;
		u++;
		tote += edge[i].len;
		if (tote >= ch)
		{
			tote = 0;
			sum++;
		}
	}
	if (sum < m)
		return 0;
	else return 1;
}
void solve_b()
{
	int tot = 0, u = 1;
	for (int i = head[1]; i != 0; i = head[edge[i].to])
		if (edge[i].to == u + 1)
		{
			u = edge[i].to;
			tot += edge[i].len;
		}
		else break;
	int l = 1, r = tot;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (r == l + 1) mid = r;
		if (check_b(mid))
			l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
}
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n <= 100 && m == 1)
	{
		solve_f();
		return 0;
	}
	bool solvep1 = 1, solvealla = 1;
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c);
		add_edge(b, a, c);
		if (b != a + 1) solvep1 = 0; 
		if (a != 1) solvealla = 0;
	}
	if (solvep1)
	{
		solve_b();
		return 0;
	}
	if (solvealla)
	{
		int alld[MAXN * 2];
		memset(alld, 0, sizeof(alld));
		int i, j;
		for (i = head[1], j = 1; i != 0; i = edge[i].next, j++)
			alld[j] = edge[i].len;
		j--;
		sort(alld + 1, alld + j + 1);
		printf("%d", alld[j - m + 1]);
		return 0;
	}
	return 0;
}

