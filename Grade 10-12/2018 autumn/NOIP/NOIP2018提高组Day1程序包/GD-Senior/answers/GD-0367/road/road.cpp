#include <iostream>
#include <cstdio>

#define MAXN 100005

using namespace std;

long long n, ans = 0;
int d[MAXN], c[MAXN];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		c[i] = d[i] - d[i - 1];
	}
	c[n + 1] = -d[n];
	while (true)
	{
		bool f = 0;
		int start = 0, minu = 100000;
		for (int i = 1; i <= n; i++)
		{
			d[i] = d[i - 1] + c[i];
			if (f)
			{
				if (d[i] != 0)
					minu = min(minu, d[i]);
				else {
					c[start] -= minu;
					c[i] += minu;
					ans += minu;
					f = 0;
//		cout << start << " " << i - 1 << " " << minu << " " << ans << endl;
				}
			}
			else {
				if (d[i] != 0)
				{
					f = 1;
					start = i;
					minu = d[i];
				}
			}
		}
		if (f == 1) {
			c[start] -= minu;
			c[n + 1] += minu;
			ans += minu;
//		cout << start << " " << n << " " << minu << " " << ans << endl;
		}
		bool g = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] != 0)	{g = 1;break;}
		}
		if (!g) {
			printf("%d", ans);
			return 0;
		}
	}
	return 0;
}
