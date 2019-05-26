#include <cstdio>
#define MO 1000000007
using namespace std;
int i, ans, n, m;

int mi(int a, int b)
{
	int i, ans;
	if (!b) return 1;
	i = 0;
	ans = 1;
	while ((1 << i) <= b) {
		if ((1 << i) & b) {
			ans *= a;
			ans %= MO;
		}
		a *= a;
		a %= MO;
		i++;
	}
	return ans% MO;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n > m) {
		int tmp = n;
		n = m;
		m = tmp;
	}
	if (n == 1) {
		ans = mi(2, m);
	}
	if (n == 2) {
		ans = mi(3, m-1)*4 %MO;
	}
	if (n == 3) {
		ans = 112*mi(4, m-3)%MO;
	}
	if (n == 5) {
		ans = mi(6, m-5)%MO*7136%MO;
	}
	printf("%d\n", ans%MO);
//	for (i=1; i<=30; ++i) printf("%d\n", mi(2, i));
	return 0;
}
