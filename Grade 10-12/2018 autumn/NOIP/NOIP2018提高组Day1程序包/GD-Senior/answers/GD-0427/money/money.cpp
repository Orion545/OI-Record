#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 210;
const int M = 25010;

int a[N], v[N], p[M];

int main() {
	
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	int T; scanf("%d", &T);
	
	while(T--) {
		
		memset(v, 0, sizeof(v));
		
		bool flag = false;
		int n; scanf("%d", &n);
	
		for (int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			if(a[i] == 1) flag = false;
		}
		if(flag) { printf("1\n"); continue; }
	
		sort(a+1, a+n+1);	

		for (int i=2; i<=n; i++) {
			memset(p, 0, sizeof(p));
			p[0] = 1;
			for (int j=1; j<i; j++) {
				if(v[j]) continue;
				for (int k=a[j]; k<=a[i]; k++) {
					if(p[k-a[j]]) p[k] = 1;
				}
				if(p[a[i]]) { v[i] = 1; break; }
			}
		}
		
		int ans = 0;
		for (int i=1; i<=n; i++) if(!v[i]) ans ++;
		printf("%d\n", ans);
	}
	
	return 0;
}
