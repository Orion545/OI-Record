#include <cstdio>
#include <vector>
#include <algorithm>
#define PROGRAM "travel"

inline int read() {
	int x = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c>='0' && c<='9') {
		x = (x<<3) + (x<<1) + (c^'0');
		c = getchar();
	}
	return x;
}

const int N = 5000 + 10;
int n, m;
std::vector<int> a[N];
int vis[N];
int cStart, cEnd; // deal with circle
int init(int x, int last) {
	vis[x] = 1;
	for (int i=0; i<a[x].size(); ++i)
		if (a[x][i] != last)
			if (vis[a[x][i]]) {
				cEnd = x;
				return a[x][i];
			} else {
				int res = init(a[x][i], x);
				if (res == x || res == -1)
					return -1;
				if (res) {
					cStart = x;
					return res;
				}
			}
	return 0;
}

bool inCircle;
void dfs(int x) {
	vis[x] = 2;
	printf("%d ", x);
	for (int i=0; i<a[x].size(); ++i)
		if (vis[a[x][i]] != 2) {
			if (inCircle && a[x][i] > cEnd) {
				inCircle = false;
				return;
			}
			vis[x] = 2;
			if (a[x][i] == cStart)
				inCircle = true;
			dfs(a[x][i]);
		}
}

int main() {
	freopen(PROGRAM".in", "r", stdin);
	freopen(PROGRAM".out", "w", stdout);

	n = read(); m = read();
	for (int i=0; i<m; ++i) {
		int x = read(), y = read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i=1; i<=n; ++i)
		std::sort(a[i].begin(), a[i].end());
	if (m == n) init(1, 0);
	dfs(1);
}
