#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define mem(a, b) memset(a, b, sizeof a)
#define F(i, a, b) for (int i = a; i <= b; i ++)

const int N = 1e2 + 10, M = 3e5;

int T, n, ans, MX, a[N];
bool vis[M];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	for (scanf("%d", &T) ; T --; ) {
		scanf("%d", &n), ans = n, MX = 0;
		F(i, 1, n) scanf("%d", &a[i]), MX = max(MX, a[i]);
		sort(a + 1, a + n + 1), mem(vis, 0), vis[0] = 1;
		F(i, 1, n) {
			if (vis[a[i]])
				{ ans --; continue; }
			F(j, a[i], MX)
				if (vis[j - a[i]])
					vis[j] = 1;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
