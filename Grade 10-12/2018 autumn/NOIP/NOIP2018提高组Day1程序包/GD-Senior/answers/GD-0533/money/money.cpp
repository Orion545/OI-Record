#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int t, n, ans, macs, a[205];
bool rl[50005];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d", &n);
		memset(rl, 0, sizeof(rl));
		for (int i = 0; i < n; i++) scanf("%lld", a + i);
		
		ans = 0;
		rl[0] = true;
		sort(a, a + n);
		macs = a[n - 1];
		
		for (int i = 0; i < n; i++) {
			if (rl[a[i]]) {
//				printf("%d---", a[i]);
				ans++;
				continue;
			}
			for (int j = a[i]; j <= macs; j++) { 
				if (rl[j - a[i]]) {
					rl[j] = true;
				}
			}
		}
		
		printf("%d\n", n - ans);
		
	}
	
	return 0;
}
