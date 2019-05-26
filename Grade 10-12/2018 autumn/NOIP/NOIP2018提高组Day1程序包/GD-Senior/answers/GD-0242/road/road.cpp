#include <cstdio>
#define PROGRAM "road"
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

const int N = 100010;
int n, ans, a[N];

int main() {
	freopen(PROGRAM".in", "r", stdin);
	freopen(PROGRAM".out", "w", stdout);
	n = read();
	for (int i=0; i<n; ++i) a[i] = read();

	int imin = 0, imax = a[0];
	for (int i=1; i<=n; ++i) {
		if (a[i-1] < a[i]) {
			imax = a[i];
		} else {
			ans += imax - imin;
			imin = imax = a[i];
		}
	}

	printf("%d\n", ans);
}
