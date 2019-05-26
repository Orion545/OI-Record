#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 100 + 5;
const int N = 25000 + 5;

int n, a[maxn], dp[maxn][N];

inline void init(int k) {
  memset(dp[k],0,sizeof(dp[k]));
  dp[k][0] = 1;
}

inline void solve() {
  scanf("%d", &n);
  for(int i = 1;i <= n;i ++) {
  	scanf("%d", &a[i]);
  	init(i);
	}
  sort(a + 1,a + n + 1);
  int Ans = 0;
  for(int i = 1;i <= n;i ++) {
  	if(!dp[i][a[i]]) {
  	  Ans ++;
  	  for(int j = i + 1;j <= n;j ++) {
  	    for(int k = a[i];k <= a[j];k ++) dp[j][k] |= dp[j][k - a[i]];
			}
		}
  }
  printf("%d\n", Ans);
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int cas; scanf("%d", &cas);
	while(cas --)
	  solve();
  return 0;
}
