#include<cstdio>
#include<algorithm>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define N 100005
int n, a[N], ans;
int main ()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	fo (i, 1, n)
		scanf("%d", &a[i]);
	++n;
	fo (i, 1, n)
		if (a[i] - a[i - 1] > 0)
			ans += a[i] - a[i - 1];
	printf("%d\n", ans);
	return 0;
}
