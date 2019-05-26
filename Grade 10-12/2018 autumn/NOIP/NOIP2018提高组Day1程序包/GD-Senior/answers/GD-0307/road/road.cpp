#include <bits/stdc++.h>

using namespace std;

unsigned int n, i, a[100002] = {0}, answer = 0;
int diff[100002] = {0};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		diff[i] = a[i] - a[i - 1];
		if (diff[i] > 0)
			answer += diff[i];
	}
	printf("%d\n", answer);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
