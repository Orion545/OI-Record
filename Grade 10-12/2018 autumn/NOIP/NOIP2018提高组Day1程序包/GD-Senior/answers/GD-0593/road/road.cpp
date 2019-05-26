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
const int maxN = 1e5 + 7;

template<class T> T rd() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

struct Node {
	int h, p;
	inline bool operator < (const Node &v) const {
		return h > v.h;
	}
}a[maxN];

bool vis[maxN];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n = ri();
	rep (i, 1, n) a[i].h = ri(), a[i].p = i;
	sort(a+1, a+n+1);
	
	int res = 0, cnt = 0;
	for (int i = 10000, j = 1; i >= 1; --i) {
		for (; i == a[j].h && j <= n; ++j) {
			vis[a[j].p] = true;
			++cnt;
			if (vis[a[j].p-1]) --cnt;
			if (vis[a[j].p+1]) --cnt;
			//if (vis[a[j].p-1] && vis[a[j].p+1]) ++cnt;
		}
		res += cnt;
	}
	printf("%d\n", res);

	return 0;
}
