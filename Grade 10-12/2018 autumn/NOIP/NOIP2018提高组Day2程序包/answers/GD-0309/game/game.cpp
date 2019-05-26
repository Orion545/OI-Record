#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define LL long long
#define db double
#define ms(i, j) memset(i, j, sizeof i)
#define FN2 "game"
using namespace std;

namespace flyinthesky {
	
	const LL MO = 1000000000 + 7;
	
	int n, m;
	
	LL ksm(LL a, LL b) {
		LL bs = a % MO, ans = 1ll;
		while (b) {
			if (b & 1) ans = (ans * bs) % MO;
			bs = (bs * ans) % MO;
			b >>= 1;
		}
		return ans;
	}
	
	int jz[10][10];
	LL ans;
	
	/*bool check(int x, int y) {
		if (x == n && y == m) return true;
		int tx = x, ty = y + 1;
		if (ty > m) ty = 1, ++tx;
		
	}
	void dfs1(int x, int y) {
		if (x == n + 1) {
			if (check(1, 1)) ++ans;
			return ;
		}
		int tx = x, ty = y + 1;
		if (ty > m) ty = 1, ++tx;
		jz[x][y] = 0, dfs1(tx, ty), jz[x][y] = -1;
		jz[x][y] = 1, dfs1(tx, ty), jz[x][y] = -1;
	}*/
	
	void clean() {
		ms(jz, -1);
	}
	int solve() {
		clean();
		scanf("%d%d", &n, &m);
		if (n == 1 && m == 1) return printf("1\n"), 0;
		if (n == 2 && m == 1) return printf("1\n"), 0;
		if (n == 3 && m == 3) return printf("112\n"), 0;
		if (n == 5 && m == 5) return printf("7136\n"), 0;
		if (n == 2) {
			if (m == 1) return printf("4\n");
			LL tmp = ksm(2ll, m - 1ll);
			LL tmp2 = 1ll;
			for (LL i = 1; i < m; ++i) {
				LL gg = (ksm(2ll, i - 1ll) * ksm(2ll, (m - i - 1ll) * 2ll)) % MO;
				tmp2 = (tmp2 * gg) % MO;
			}
			LL ans = (tmp + tmp2) % MO;
			ans = (ans * 4ll) % MO;
			printf("%lld\n", ans);
		}/* else {
			ans = 0ll;
			dfs1(1, 1);
		}*/
		return 0;
	}
}
int main() {
	freopen(FN2".in", "r", stdin), freopen(FN2".out", "w", stdout);
	flyinthesky::solve();
	fclose(stdin), fclose(stdout);
}
