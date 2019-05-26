#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#define fo(i, x, y) for (int i = x; i <= y; ++i)
#define fd(i, x, y) for (int i = x; i >= y; --i)

using namespace std;

const int maxn = 100 + 5, maxs = 1e6 + 5, inf = 1e9;

int n, lim, ans;
int a[maxn];
bool f[maxs], af[maxs];

int getint() {
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

int cnt(int s) {
	fo (i, 1, lim)
		if (af[i] != f[i]) return inf;
	int res = 0;
	while (s) res++, s -= s & -s;
	return res;
}

void work1() {
	if (!(a[2] % a[1])) printf("1\n");
		else printf("2\n");
}

void work2() {
	if (!(a[3] % a[1]) && !(a[2] % a[1])) printf("1\n");
		else {
			if (a[1] + a[2] > a[3]) ans = 3;
			if (!ans)
				fo (i, 1, a[3])
					fo (j, 1, a[3])
						if (a[1] * i + a[2] * j == a[3]) {
							ans = 2;
							break;
						}
			printf("%d\n", ans);
		}
}

int cb(int s) {
	int res = 0;
	while (s) res++, s -= s & -s;
	return res;
}

void work3() {
	int allset = (1 << n) - 1;
	ans = inf;
	lim = a[n] * a[n - 1];
	
	fo (i, 1, lim) af[i] = false;
	af[0] = true;
	
	fo (i, 1, n)
		fo (j, a[i], lim) af[j] |= af[j - a[i]];
	
	fo (s, 0, allset) {
		if (cb(s) > ans) continue;
		fo (i, 1, lim) f[i] = false;
		f[0] = true;
		fo (i, 1, n)
			if (s & (1 << (i - 1)))
				fo (j, a[i], lim)
					f[j] |= f[j - a[i]];
		ans = min(ans, cnt(s));
	}
	printf("%d\n", ans);
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	int kase = getint();
	while (kase--) {
		n = getint();
		fo (i, 1, n) a[i] = getint();
		sort(a + 1, a + 1 + n);
		if (n == 1) printf("1\n");
			else if (n == 2) work1();
				else if (n == 3) work2();
					else work3();
	}
	return 0;
}
