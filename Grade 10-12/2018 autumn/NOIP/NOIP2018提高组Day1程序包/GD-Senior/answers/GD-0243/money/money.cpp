#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

long t, n, a[10000], flag[30000], max, ans;

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	std::cin >> t;
	while (t > 0) {
		t--;
		std::cin >> n;
		if (n == 2) {
			long aa, bb;
			std::cin >> aa >> bb;
			if (aa < bb) {
				long t;
				t = aa;
				aa = bb;
				bb = t;
			}
			if (aa % bb == 0) {
				std::cout << 1 << std::endl;
			} else {
				std::cout << 2 << std::endl;
			}
			continue;
		} else {
			max = 0;
			ans = n;
			for (long i = 0; i < n; i++) {
				std::cin >> a[i];
				if (a[i] > max) {
					max = a[i];
				}
			}
			std::sort(a, a+n);
			memset(flag, 0, sizeof(flag));
			for (long i = a[0]; i <= max; i += a[0]) {
				flag[i] = true;
			}
			for (long i = 1; i < n; i++) {
				if (flag[a[i]]) {
					ans--;
					continue;
				}
				flag[a[i]] = true;
				for (long j = 0; j < max; j += a[i]) {
					for (long i = a[0]; i < max; i++) {
						if (flag[i]) {
							flag[i + j] = 1;
						}
					}
				}
			}
			std::cout << ans << std::endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
