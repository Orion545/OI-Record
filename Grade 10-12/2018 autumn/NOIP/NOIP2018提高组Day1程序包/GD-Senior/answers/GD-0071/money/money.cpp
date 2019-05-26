#include<cstdio>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 105, M = 25000;

int T, n, a[N], f[M + 1], ans;

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	f[0] = 1;
	for(scanf("%d", &T); T; T --) {
		ans = 0;
		fo(i, 1, M) f[i] = 0;
		scanf("%d", &n);
		fo(i, 1, n) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		fo(i, 1, n) if(!f[a[i]]) {
			ans ++; fo(j, a[i], M) f[j] |= f[j - a[i]];
		}
		printf("%d\n", ans);
	}
	return 0;	
}
