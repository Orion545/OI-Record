#include <cstdio>
#include <cstring>
#include <algorithm>
#define PROGRAM "money"
const int INF = 0x3fffffff;

inline int min(int a, int b) { return a<b?a:b; }
inline int max(int a, int b) { return a>b?a:b; }
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

const int N = 100 + 10;
const int M = 250000 + 10;
int i, j, n, ans, a[N];
bool f[M];

int main() {
	freopen(PROGRAM".in", "r", stdin);
	freopen(PROGRAM".out", "w", stdout);

	int T = read();
	while (T--) {
		n = read();
		for (i=0; i<n; ++i) a[i] = read();
		std::sort(a, a+n);

		memset(f, 0, sizeof(f));
		f[0] = 1;
		ans = 0;
		for (i=0; i<n ; ++i) {
			bool flag = false;
			for (j=0; j+a[i]<M; ++j)
				if (f[j] && !f[j+a[i]]) {
					flag = true;
					f[j+a[i]] = 1;
				}
			if (flag) ++ans;
		}
		printf("%d\n", ans);
	}
}
