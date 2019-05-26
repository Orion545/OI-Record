#include <bits/stdc++.h>

using namespace std;

long long n, m, answer = 0;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	if (n > m)
		swap(n, m);
	if (n <= 2) {
		answer = 4 * (m - n + 1) % 1000000007;
	}
	printf("%lld", answer);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
