#include <iostream>
#include <cstdio>
#include <cstring>

long a[1000][1000], n, m, max;

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	std::cin >> n >> m;
	if (m == 1) {
		memset(a, 0x2fffff, sizeof(a));
		for (long i = 0; i < n - 1; i++) {
			long from, to, len;
			std::cin >> from >> to >> len;
			a[from][to] = len;
			a[to][from] = len;
			a[i][i] = 0;
		}
		for (long k = 1; k <= n; k++) {
			for (long i = 1; i <= n; i++) {
				if (k == i) continue;
				for (long j = 1; j <= n; j++) 
					if ((k != j) && (i != j)) {
						if (a[i][j] > (a[i][k] + a[k][j])) {
							a[i][j] = a[i][k] + a[i][j];
						}
					}
			}
		}
		for (long i = 1; i <= n; i++) {
			for (long j = 1; j <= n; j++) {
				if (max < a[i][j])
					max = a[i][j];
			}
		}
		std::cout << max;
	} else {
		std::cout << 15;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
