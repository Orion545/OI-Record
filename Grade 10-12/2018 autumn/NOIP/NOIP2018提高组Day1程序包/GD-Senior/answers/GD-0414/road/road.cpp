#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long
#define fo(i, x, y) for(int i = x; i <= y; i++)
#define fd(i, x, y) for(int i = x; i >= y; i--)
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
void init() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}
int read() {
	int b = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if (c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) b = b * 10 + c - '0';
	return b * k;
}
const int N = 1e5 + 5;
int n, a[N], last, ans;
int main() {
	init();
	n = read();
	fo(i, 1, n) a[i] = read();
	a[++n] = 0;
	a[++n] = 1 << 30;
	last = a[1];
	fo(i, 1, n - 1) {
		if (a[i] < a[i + 1]) {
			ans += last - a[i];
			last = a[i + 1];
		}
	}
	printf("%d\n", ans);
	return 0;
}
