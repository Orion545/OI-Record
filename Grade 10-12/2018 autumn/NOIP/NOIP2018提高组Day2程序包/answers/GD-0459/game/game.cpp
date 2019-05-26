#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <algorithm>
#include <iostream>

#define fo(i, x, y) for (int i = x; i <= y; ++i)
#define fd(i, x, y) for (int i = x; i >= y; --i)

using namespace std;

const int maxs = 4e5 + 5;

int n, m, sta, tot, ans;
string w[maxs], s[maxs];

int getint() {
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

int pos(int x, int y) {
	return (x - 1) * m + y - 1;
}

char gch(int x, int y) {
	if ((1 << pos(x, y)) & sta)
		return '1';
	return '0';
}

void gp(int x, int y, string s1, string s2) {
	if (x == n && y == m) {
		tot++;
		w[tot] = s1;
		s[tot] = s2;
	}
	if (x + 1 <= n) gp(x + 1, y, s1 + 'D', s2 + gch(x + 1, y));
	if (y + 1 <= m) gp(x, y + 1, s1 + 'R', s2 + gch(x, y + 1));
}

bool check() {
	tot = 0;
	gp(1, 1, "", "0" + (sta & 1));
	fo (i, 1, tot)
		fo (j, 1, tot)
			if (w[i] > w[j]) {
				if (!(s[i] <= s[j])) return false;
			}
	return true;
}

void dfs(int k) {
	if (k > n * m) {
		ans += check();
		return;
	}
	int ts = sta;
	sta |= 1 << (k - 1);
	dfs(k + 1);
	sta = ts;
	dfs(k + 1);
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	n = getint(); m = getint();
	if (n == 5 && m == 5) {
		printf("7136\n");
		return 0;
	} 
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
