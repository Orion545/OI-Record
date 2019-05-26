#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
//#include <queue>
#include <cmath>

typedef long long ll;

using namespace std;

struct node
{
	int data;
	bool pd = false;
};
node defense[100010];

bool check(int l, int r)
{
	int i;
	for (i = 1;i < r;i++)
	{
		if (defense[i].pd == false && defense[i + 1].pd == false)
			return false;
	}
	return true;
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string ss;
	cin >> ss;
	int i, j;
	int u, v;
	int cnt;
	int a, b, x, y;
	if (ss[0] == 'A')
	{
		for (i = 1;i <= n;i++)
			cin >> defense[i].data;
		for (i = 1;i < n;i++)
			cin >> u >> v;
		while (m--)
		{
			cnt = 0;
			cin >> a >> x >> b >> y;
			defense[a].pd = x;
			defense[b].pd = y;
			if (a > b)
				swap(a, b);
			for (i = a - 1;i >= 1;i--)
				defense[i].pd = !defense[i + 1].pd;
			for (j = b + 1;j <= n;j++)
				defense[j].pd = !defense[j - 1].pd;
			i = a;
			j = b;
			while (j - i > 1)
			{
				defense[i + 1].pd = !defense[i].pd;
				i++;
				defense[j - 1].pd = !defense[j].pd;
				j--;
			}
			if (check(1, n))
			{
				for (i = 1;i <= n;i++)
				{
					if (defense[i].pd)
						cnt += defense[i].data;
				}
				cout << cnt << endl;
			}
			else
				cout << -1 << endl;
			for (i=  1;i <= n;i++)
				defense[i].pd = false;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
