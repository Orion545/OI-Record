#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int num[25005][105];
bool used[25005][105];

const int N = 105;

int n;
int a[N];
int del[N];
int mx;

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		mx = std::max(mx, a[i]);
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1;i <= n; i++)
	{
		num[a[i]][++num[a[i]][0]] = i;
		used[a[i]][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (del[i])
			continue;
		int now = i + 1;
		for (int k = 1; k * a[i] <= mx; k++)
		{
			int u = k * a[i];
			for (int j = u; j <= mx; j++)
			{
				if (num[j][0] == 0)
					continue;
				for (int p = 1; p <= num[j][0]; p++)
				{
					if (used[j - u][num[j][p]])
						continue;
					used[j - u][num[j][p]] = 1;
					num[j - u][++num[j - u][0]] = num[j][p];
				}
			}
			for (int j = n; j >= 1; j--)
			{
				if (a[j] < u)
					break;
				if (del[j])
					continue;
				if (a[j] == u && j != i)
					del[j] = 1;
				if (used[a[j] - u][j])
					continue;
				used[a[j] - u][j] = 1;
				num[a[j] - u][++num[a[j] - u][0]] = j;
			}
			if (num[u][0] > 0)
			{
				for (int  j = 1; j <= num[u][0]; j++)
					if (num[u][j] != i)
						del[num[u][j]] = 1;
				num[u][0] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!del[i])
		{
//			printf("%d\n",a[i]);
			ans++;
		}
	}
	printf("%d\n",ans);
}

void init()
{
	for (int i = 0; i <= 100; i++)
		for (int j = 1; j <= mx; j++)
			used[j][i] = 0;
	for (int i = 1; i <= mx; i++)
		num[i][0] = 0;
	for (int i = 1; i <= 100; i++)
		del[i] = 0, a[i] = 0;
	n = mx = 0;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T = read();
	while (T--)
	{
		init();
		solve();
	}
}
