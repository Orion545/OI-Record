#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long LL;
int _max(int x, int y) {return x > y ? x : y;}

int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}

int a[110000], f[20][110000], Log[110000];
LL ans = 0;
int _min(int x, int y) {return a[x] < a[y] ? x : y;}

int Getmin(int l, int r) {
	int hh = Log[r - l + 1];
	return _min(f[hh][l], f[hh][r - (1 << hh) + 1]);
}

void Dfs(int l, int r, int last) {
	if(l > r) return ;
	int hh = Getmin(l, r);
	ans += (LL)a[hh] - last;
	Dfs(l, hh - 1, a[hh]), Dfs(hh + 1, r, a[hh]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read();
	memset(f, 0, sizeof(f)); a[0] = 999999999;
	Log[1] = 0; for(int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for(int i = 1; i <= n; i++) a[i] = read(), f[0][i] = i;
	for(int i = 1; i <= 18; i++) {
		for(int j = 1; j <= n - (1 << i) + 1; j++) {
			f[i][j] = _min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
		}
	} Dfs(1, n, 0);
	printf("%lld\n", ans);
	return 0;
}

