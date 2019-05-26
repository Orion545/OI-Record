# include <bits/stdc++.h>
using namespace std;
# define Rep(i, s, t) for (int i = (s), _ = (t); i <= _; i ++)
const int N = 100005;
int n, a[N], ans;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", & n);
	Rep (i, 1, n)
		scanf("%d", a + i);
	int d = 0;
	Rep (i, 1, n)
		if (d <= a[i])
			d = a[i];
		else
			ans += d - a[i], d = a[i];
	printf("%d\n", ans + d);
	return 0;
}
