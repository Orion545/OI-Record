#include <cstdio>
#include <cstring>
#define PROGRAM "game"

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

const int MAXN = 1 << 8;
const int MOD = 1e9+7;
int n, m, N, ans, cur, nxt = 1;
int f[2][MAXN];

int main() {
	freopen(PROGRAM".in", "r", stdin);
	freopen(PROGRAM".out", "w", stdout);

	n = read(); m = read();
	N = 1<<n;
	for (int i=0; i<N; ++i) f[0][i] = 1;
	for (int i=1; i<m; ++i) {
		memset(f[nxt], 0, sizeof(f[nxt]));
		for (int j=0; j<N; ++j) {
			int jj = j<<1 & (N-1);
			for (int k=0; k<N; ++k) {
				if (((k & jj) ^ jj) == 0) {
					f[nxt][k] += f[cur][j];
					if (f[nxt][k] > MOD)
						f[nxt][k] -= MOD;
				}
			}
		}
		cur ^= 1;
		nxt ^= 1;
	}
	for (int i=0; i<N; ++i) {
		ans += f[cur][i];
		if (ans > MOD)
			ans -= MOD;
	}
	printf("%d", ans);
}
