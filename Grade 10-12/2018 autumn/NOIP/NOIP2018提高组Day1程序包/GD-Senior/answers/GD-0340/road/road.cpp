#include <cstdio>
#define R register
#define In inline
#define re(i, x, y) for (R int i = x; i <= y; ++ i)
#define de(i, x, y) for (R int i = x; i >= y; -- i)
using namespace std;

int n, ans, h[100005], f[100005];

int main() {
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	scanf("%d", &n);
	re(i, 1, n) scanf("%d", &h[i]);
	ans = h[1];
	re(i, 2, n) if (h[i]>h[i-1]) ans += (h[i]-h[i-1]);
 	printf("%d", ans);
	return 0;
}
