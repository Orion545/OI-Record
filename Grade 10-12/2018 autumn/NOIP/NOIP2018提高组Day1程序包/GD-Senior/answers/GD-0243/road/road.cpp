#include <iostream>
#include <cstdio>

long a[100000], n, l, r, ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::cin >> n;
	bool flaga = true, flagb = false;
	for (long i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
		if (flaga) {
			if (a[i]) {
				l = i;
				r = i;
				flaga = false;
				flagb = true;
			}
		}
		if (flagb) {
			if (a[i]) {
				r = i;
			} else {
				flagb = false;
			}
		}
	}
	while (l < n) {
		long min = 10001;
		for (long i = l; i <= r; i++) {
			if (min > a[i])
				min = a[i];
		}
		for (long i = l; i <= r; i++) {
			a[i] -= min;
		}
		ans += min;
		for (; l < n; l++) {
			if (a[l]) {
				break;
			}
		}
		for (r = l; r < n; r++) {
			if (a[r] == 0) {
				break;
			}
		}
		r--;
		if (a[l] == 0) {
			l = n;
		}
	}
	std::cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
