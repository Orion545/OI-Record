# include <bits/stdc++.h>
using namespace std;
# define Rep(i, s, t) for (int i = (s), _ = (t); i <= _; i ++)
int T, n, a[105], v[30000], cnt;
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", & T);
	while (T --) {
		scanf("%d", & n);
		Rep (i, 1, n)
			scanf("%d", a + i);
		sort(a + 1, a + n + 1), memset(v, 0, sizeof v), v[0] = 1, cnt = 0;
		Rep (i, 1, n) {
			int cur = a[i];
			if (! v[cur]) {
				cnt ++;
				Rep (w, cur, 25000)
					v[w] |= v[w - cur];
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
