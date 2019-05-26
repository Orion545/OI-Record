#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define N 105
#define M 55005
int T, n, a[N], ans;
bool fl[M];
int main ()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		fo (i, 1, n)
			scanf("%d", &a[i]);
		std::sort(a + 1, a + n + 1);
		memset(fl, 0, sizeof fl);
		ans = 0;
		fo (i, 1, n)
			if (!fl[a[i]])
			{
				fl[a[i]] = 1;
				for (int j = 1; j + a[i] <= a[n]; ++j)
					if (fl[j])
						fl[j + a[i]] = 1;
				++ans;
			}
		printf("%d\n", ans);
	}
	return 0;
}
