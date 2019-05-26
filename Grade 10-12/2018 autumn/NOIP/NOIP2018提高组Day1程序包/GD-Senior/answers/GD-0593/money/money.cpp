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
const int maxN = 107;
const int V = 25000;
const int maxV = 25007;

template<class T> T rd() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

int n;
int a[maxN];
bool f[maxV];

void solve() {
	memset(f, false, sizeof f);
	sort(a+1, a+n+1);
	int res = 0;
	f[0] = true;
	rep (i, 1, n) {
		if (f[a[i]]) continue;
		++res;
		for (int v = a[i]; v <= V; ++v) f[v] |= f[v-a[i]];
	}
	printf("%d\n", res);
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	rep (cas, 1, ri()) {
		n = ri();
		rep (i, 1, n) a[i] = ri();
		solve();
	}

	return 0;
}

