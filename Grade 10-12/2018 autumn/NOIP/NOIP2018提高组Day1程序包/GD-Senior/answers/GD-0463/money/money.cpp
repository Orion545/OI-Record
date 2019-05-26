#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int Gcd(int a, int b) {
	return b ? Gcd(b, a % b) : a;
}

int ModEq1(int a, int b, int c, int d) {
	return a == 1 ? d : ModEq1(b, a % b, d - c * (a / b), c);
}

int ModEq1Ex(int a, int b, int m) {
	int e = m / Gcd(a, m);
	if (b % Gcd(a, m) != 0) return -1;
	b %= m;
	int d = Gcd(b, m);
	b /= d; m /= d;
	if (a % d == 0) {
		a /= d;
		d = 1;
	}
	int q = ModEq1(m, b, 1, 0);
	if (q < m) q += m;
	a *= q; a %= m;
	int x = ModEq1(m, a, 1, 0) * d;
	x %= e;
	if (x < 0) x += e;
	return x;
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int ti = 0; ti < t; ti++) {
		int n;
		int a[MAXN];
		bool tick[MAXN];
		memset(tick, 0, sizeof(tick));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int ans = n;
		for (int k = 2; k <= n; k++) {
			for (int i = 1; i <= k - 1; i++) {
				if (tick[i]) continue;
				if (a[k] % a[i] == 0 && !tick[k]) {
					//printf("%d / %d test NG\n", a[k], a[i]);
					ans--;
					tick[k] = true;
					break;
				}
			}
			if (tick[k]) continue;
			for (int i = 1; i <= k - 2; i++) {
			//if (tick[i]) continue;
				for (int j = i + 1; j <= k - 1; j++) {
					//if (tick[j]) continue;
					int x = ModEq1Ex(a[i], a[k], a[j]);
					//printf("now judging %d = %d * %d + %dy\n", a[k], x, a[i], a[j]);
					if (!(x == -1 || a[k] < a[i] * x) && !tick[k]) {
						//printf("%d = %d * %d + %dy test NG\n", a[k], x, a[i], a[j]);
						ans--;
						tick[k] = true;
						break;
					}
					x = ModEq1Ex(a[j], a[k], a[i]);
					if (!(x == -1 || a[k] < a[j] * x) && !tick[k]) {
						//printf("%d = %d * %d + %dy test NG\n", a[k], x, a[j], a[i]);
						ans--;
						tick[k] = true;
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
