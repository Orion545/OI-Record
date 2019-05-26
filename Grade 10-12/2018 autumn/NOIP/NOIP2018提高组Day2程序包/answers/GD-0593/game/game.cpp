#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;
#define ri rd<int>
#define rep(i,a,b) for (int i = (a), _ = (b); i <= _; ++i)
#define per(i,a,b) for (int i = (a), _ = (b); i >= _; --i)
#define For(i,a,b) for (int i = (a), _ = (b); i < _; ++i)
const int O = 1000000007;
typedef long long LL;

template<class T> T rd() {
	T x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

int pwr(int x, int t) {
	int res = 1;
	for (; t > 0; t >>= 1) {
		if (t & 1) res = 1LL * res * x % O;
		x = 1LL * x * x % O;
	}
	return res;
}

inline void Add(int &x, int y) {
	x = (x + y) % O;
}

int solve(int m) {
	int ans = 0;
	rep (i, 2, m-1) {
		if (i == m-1) Add(ans, 4);
		else Add(ans, 8LL * pwr(3, m-i-2) % O); // 8 = 2 * 4
	}
	if (m > 2) Add(ans, 24LL * pwr(3, m-3) % O); // 24 * 3 * 4 * 2
	else Add(ans, 9);
	return ans;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	int n = ri(), m = ri();
	if (n == 1 || m == 1) {
		printf("%d\n", pwr(2, max(n, m)));
		return 0;
	}
	if (n == 2) {
		printf("%d\n", 4LL * pwr(3, m-1) % O);
		return 0;
	}
	int ans = 1LL * pwr(2, n-1) * solve(m) % O;
	printf("%d\n", ans);

	return 0;
}
