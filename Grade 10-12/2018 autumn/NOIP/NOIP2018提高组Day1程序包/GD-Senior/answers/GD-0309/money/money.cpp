#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define LL long long
#define db double
#define ms(i, j) memset(i, j, sizeof i)
#define FN2 "money"
using namespace std;

namespace flyinthesky {
	
	int n, ai[105], dp[25000 + 5];
	
	void clean() {
		ms(ai, 0);
	}
	int solve() {
		clean();
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &ai[i]);
		sort(ai + 1, ai + 1 + n);
		int tot = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= ai[i]; ++j) dp[j] = 0;
			dp[0] = 1;
			for (int j = 1; j < i; ++j) {
				for (int k = ai[j]; k <= ai[i]; ++k) dp[k] |= dp[k - ai[j]];
			}
			if (!dp[ai[i]]) ++tot;
		}
		printf("%d\n", tot);
		return 0;
	}
}
int main() {
	freopen(FN2".in", "r", stdin), freopen(FN2".out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) flyinthesky::solve();
	fclose(stdin), fclose(stdout);
	return 0;
}
