#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define LL long long
#define db double
#define ms(i, j) memset(i, j, sizeof i)
#define FN2 "road"
using namespace std;

namespace flyinthesky {
	
	int whw[1005][10005], n, d[100005], gg[10000 + 5], maxd;
	// whw[pos][high], gg[high]

	int mymax(int a, int b) {return a > b ? a : b;}

	void clean() {
		ms(whw, 0), ms(gg, 0), maxd = 0;
	}
	int solve() {
		clean();
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &d[i]); 
			maxd = mymax(maxd, d[i]);
			for (int j = 1; j <= d[i]; ++j) whw[i][j] = 1;
		}
		for (int i = 1; i <= maxd; ++i) {
			for (int j = 2; j <= n; ++j) if (whw[j][i] == 0 && whw[j - 1][i] != 0) ++gg[i];
			if (whw[n][i] != 0) ++gg[i];
		}
		int ans = 0, cnt = 1;
		for (int i = 1; i <= maxd; ++i) {
			if (gg[i] == gg[i - 1]) ++cnt;
			else if (gg[i] != gg[i - 1]) ans += gg[i - 1] * cnt, cnt = 1;
		} 
		if (cnt != 0) ans += gg[maxd] * cnt;
		printf("%d\n", ans);
		return 0;
	}
}
int main() {
	freopen(FN2".in", "r", stdin), freopen(FN2".out", "w", stdout);
	flyinthesky::solve();
	fclose(stdin), fclose(stdout);
	return 0;
}
