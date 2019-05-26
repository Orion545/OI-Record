#include <algorithm>
#include <cstdio>
using std::sort;

const int MAXN = 110;
const int MAXA = 25010;
int t, n, a[MAXN], ans;
bool v[MAXA];

int main() {
	freopen("money.in" , "r", stdin );
	freopen("money.out", "w", stdout);

	scanf("%d", &t);
	while (t --) {
		ans = 0;
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		// if (n == 2) {
		// 	puts(!(a[2] % a[1]) ? "1" : "2");
		// 	continue;
		// }
		v[0] = true;
		for (int i=1; i<MAXA; i++)
			v[i] = false;
		for (int i=1; i<=n; i++) {
			if (v[a[i]])
				continue;
			ans ++;
			for (int j=0; j<MAXA-a[i]; j++)
				if (v[j])
					v[j+a[i]] = true;
		}
		printf("%d\n", ans);
	}


	return 0;
}
