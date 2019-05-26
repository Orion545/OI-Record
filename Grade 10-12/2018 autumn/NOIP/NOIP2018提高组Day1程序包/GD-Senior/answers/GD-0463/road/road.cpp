#include <bits/stdc++.h>
#define llong long long
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int last = 0, now;
	llong ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &now);
		if (now > last)
			ans += (now - last);
		last = now;
	}
	printf("%lld", ans);
	return 0;
}
