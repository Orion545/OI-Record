#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long
#define fo(i, x, y) for(int i = x; i <= y; i++)
#define fd(i, x, y) for(int i = x; i >= y; i--)
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
void init() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
}
int read() {
	int b = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar()) if (c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) b = b * 10 + c - '0';
	return b * k;
}
const int N = 1e5 + 5;
int n, m, t, cnt, ans, a[N], sum;
int tot, to[N], ne[N], la[N], val[N];
struct node {
	int a, b, l;
}s[N];
void Link(int u, int v, int len) {to[++tot] = v, ne[tot] = la[u], val[tot] = len, la[u] = tot;}
void Dfs(int x, int fa, int len) {
	ans = max(ans, len);
	if (len > cnt) {
		cnt = len;
		t = x;
	}
	for(int i = la[x]; i; i = ne[i]) {
		int nex = to[i], w = val[i];
		if (nex == fa) continue;
		Dfs(nex, x, len + w);
	}
}
bool cmp(const node &a, const node &b) {return a.l > b.l;}
int main() {
	init();
	n = read(), m = read();
	bool _1 = 1, _2 = 1;
	fo(i, 1, n - 1) {
		s[i].a = read(), s[i].b = read(), s[i].l = read();
		Link(s[i].a, s[i].b, s[i].l);
		Link(s[i].b, s[i].a, s[i].l);
		if (s[i].a != 1) _1 = 0;
		if (s[i].a + 1 != s[i].b) _2 = 0;
	}
	if (m == 1) {
		t = cnt = 0;
		Dfs(1, 0, 0);
		ans = 0;
		Dfs(t, 0, 0);
		printf("%d\n", ans);
		return 0;
	}
	if (_1) {
		sort(s + 1, s + n - 1 + 1, cmp);
		printf("%d\n", min(s[m - 1].l, s[m].l + s[m + 1].l));
		return 0;
	}
	if (_2) {
		fo(i, 1, n - 1) a[i] = s[i].l, sum += s[i].l;
		int l = 0, r = sum;
		ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			t = cnt = 0;
			fo(i, 1, n - 1) {
				cnt += a[i];
				if (cnt >= mid) {
					t++;
					cnt = 0;
				}
				if (t == m) break;
			}
			if (t == m) {
				ans = max(ans, mid);
				l = mid + 1;
			} else r = mid - 1;
		}
		printf("%d\n", ans);
		return 0;
	}
	return 0;
}
