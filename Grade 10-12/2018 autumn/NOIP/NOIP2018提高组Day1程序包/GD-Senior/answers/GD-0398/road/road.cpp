#include <cstdio>
#include <algorithm>
#define INF 2147483600
using namespace std;
int i, j, flag, n, p, Minn, ans=0, a[100005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (i=1; i<=n; ++i) scanf("%d", &a[i]);
	flag = 1;
	while (flag) {
		flag = 0;
		i = 1;
		while (i<=n) {
			while ( (i<=n) && !a[i] ) i++;
			if (i>n) break;
			Minn = INF;
			p = i;
			while (a[i]) {
				Minn = min(Minn, a[i]);
				i++;
			}
			for (j=p; j<i; ++j) {
				a[j] -= Minn;
				if (a[j]) flag = 1;
			}
			ans += Minn;
		}
	}
	printf("%d\n", ans);
	return 0;
}
