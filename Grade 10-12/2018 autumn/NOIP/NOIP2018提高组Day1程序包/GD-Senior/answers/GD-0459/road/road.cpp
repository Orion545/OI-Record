#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#define fo(i, x, y) for (int i = x; i <= y; ++i)
#define fd(i, x, y) for (int i = x; i >= y; --i)

using namespace std;

const int maxn = 1e5 + 5;

int n, kz, kf;
int a[maxn], b[maxn], sz[maxn], sf[maxn];

int getint() {
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = getint();
	fo (i, 1, n) {
		a[i] = getint();
		int tmp = a[i] - a[i - 1];
		if (tmp < 0) sf[++kf] = tmp;
		if (tmp > 0) sz[++kz] = tmp;
	}
	if (a[n]) sf[++kf] = -a[n];
	int ans = 0, j = 1;
	fo (i, 1, kz)
		while (sz[i] && j <= kf) {
			int tmp = min(sz[i], -sf[j]);
			sz[i] -= tmp;
			sf[j] += tmp;
			ans += tmp;
			if (!sf[j]) j++;
		}
	printf("%d\n", ans);
	return 0;
}
