#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 105

using namespace std;

int n, ans;
int a[MAXN];
int f[20005];

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ans = n;
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		f[0] = 1;
		for (int i = 0; i <= a[n]; i++)
			if (f[i] >= 1)
			{
				for (int j = 1; j <= n; j++)
					f[i + a[j]]++;
			}
		for (int i = 1; i <= n; i++)
			if (f[a[i]] > 1)
				ans--;
		printf("%d\n", ans);
	}
	return 0;
}

