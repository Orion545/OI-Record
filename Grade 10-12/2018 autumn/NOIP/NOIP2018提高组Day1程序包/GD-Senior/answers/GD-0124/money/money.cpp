#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int read() {
	int t = 0; char ch = getchar();
	while ('0' > ch || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') 
		t = (t << 3) + (t << 1) + ch - '0',
		ch = getchar();
	return t;
}

const int maxn = 105;
int n, a[maxn], ans;
bool f[25005];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T = read();
	while (T--) {
		for (int i = 1; i <= a[n]; i++) f[i] = false;
		ans = 0, n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + 1 + n);
		f[0] = true;
		for (int i = 1; i <= n; i++) {
			if (!f[a[i]]) ans++, f[a[i]] = true;
			for (int j = 0; j <= a[n] - a[i]; j++)
				f[j + a[i]] |= f[j];
		}
		printf("%d\n", ans);
	}
	return 0;
}
