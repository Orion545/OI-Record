#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

struct node
{
	int data;
	bool vis = false;
};

bool comp(node x, node y)
{
	return x.data < y.data;
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int n;
	int i;
	int j;
	int k;
	int temp;
	int cnt;
	bool pd = true;
	node a[110];
	while (T--)
	{
		cnt = 0;
		cin >> n;
		pd = true;
		for (i = 1;i <= n;i++)
		{
			cin >> a[i].data;
			a[i].vis = false;
		}
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		sort(a + 1, a + 1 + n, comp);
		for (i = 1;pd;i++)
		{
			if (a[i].vis)
				continue;
			temp = a[i].data * 2;
			if (a[n].data < temp)
			{
				pd = false;
				continue;
			}
			for (j = i + 1;j <= n;j++)
			{
				if (a[j].data == temp)
				{
					a[j].vis = true;
					temp += a[i].data;
				}
				while (a[j + 1].data > temp && j < n)
					temp += a[i].data;
			}
		}
		for (i = 1;i < n;i++)
		{
			if (a[i].vis)
				continue;
			temp = a[i].data;
			j = i;
			/*
			if (a[n].data < temp)
				break;
			*/
			while (a[j].data <= temp && j < n)
				j++;
			for (j;j <= n;j++)
			{
				if (a[j].vis)
					continue;
				for (k = j - 1;k >= 1;k--)
				{
					if ((a[j].data - a[i].data) % a[k].data == 0)
					{
						a[j].vis = true;
						continue;
					}
				}
			}
		}
		for (i = 1;i <= n;i++)
		{
			if (a[i].vis == false)
				cnt++;
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}