#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

int d[100010];

ll dfs(int l, int r, int min)
{
	int lmin = 100000;
	int rmin = 100000;
	ll cnt1 = min;
	int i;
	if (l > r)
		return 0;
	if (l == r)
		return min;
	for (i = l;i <= r;i++)
		d[i] -= min;
	i = l;
	int j;
	int l1;
	while (i <= r)
	{
		while (d[i] == 0 && i <= r)
			i++;
		l1 = i;
		lmin = 100000;
		for (i;d[i] != 0 && i <= r;i++)
		{
			if (d[i] < lmin)
				lmin = d[i];
		}
		j = i;
		cnt1 += dfs(l1, j - 1, lmin);
	}
	return cnt1;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(false);
	int min = 100000;
	ll cnt;
	int n;
	cin >> n;
	//int d[n + 10];
	//memset(d, 0, sizeof(d));
	int i;
	for (i = 1;i <= n;i++)
	{
		cin >> d[i];
		if (d[i] < min)
		{
			min = d[i];
		}
	}
	cnt = dfs(1, n, min);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
