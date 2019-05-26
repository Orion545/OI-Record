#include <cstdio>
using namespace std;

int a[100010], n = 0, l = 0, ans = 0;

int doit(const int &l,const int &r) {
	int MIN = 2147483640;
	for (int i = l; i <= r; ++i) if (a[i] < MIN) MIN = a[i];
	int ret = MIN, newL = 0;
	bool flag = false;
	for (int i = l; i <= r; ++i) {
		a[i] -= MIN;
		if (flag && !a[i]) {
			ret += doit(newL, i - 1);
			flag = false;
		}
		if (a[i] && !flag) {
			newL = i;
			flag = true;
		}
	}
	if (flag) ret += doit(newL, r);
	return ret;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (flag && !a[i]) {
			ans += doit(l, i - 1);
			flag = false;
		}
		if (a[i] && !flag) {
			l = i;
			flag = true;
		}
	}
	if (flag) ans += doit(l, n - 1);
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
