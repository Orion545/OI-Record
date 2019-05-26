#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int n, m;

namespace work1{

int g[12][12];
int a[10], b[10], c[10], d[10], tot;

inline void get(int sta, int *a, int ln) {
  int x = 1, y = 1, flag = 0;
  a[tot = 1] = g[x][y];
  for(int i = 0;i < ln;i ++) {
    if(sta & (1 << i)) y ++;
		else x ++;
		if(x > n || y > m) flag = 1;
		else a[++ tot] = g[x][y];
	}
	if(flag) for(int i = 1;i <= 5;i ++) a[i] = -1;
}

inline void get1(int sta, int *a, int ln) {
  a[tot = 1] = 0;
  for(int i = 0;i < ln;i ++) {
    if(sta & (1 << i)) a[++ tot] = 1;
		else a[++ tot] = 0;
	}
}

inline void print() {
  for(int i = 1;i <= n;i ++) {
    for(int j = 1;j <= m;j ++) printf("%d ", g[i][j]);
    puts("");
	}
	int ln = n + 2;
	for(int i = 1;i <= ln;i ++) printf("%d ", a[i]); puts("");
	for(int i = 1;i <= ln;i ++) printf("%d ", b[i]); puts("");
	for(int i = 1;i <= ln;i ++) printf("%d ", c[i]); puts("");
	for(int i = 1;i <= ln;i ++) printf("%d ", d[i]); puts("");
	puts("");
}

inline int check() {
  int ln = n + m - 2;
  for(int i = 0;i < (1 << ln);i ++) {
    for(int j = 0;j < (1 << ln);j ++) {
    	get(i,a,ln);
    	get1(i,c,ln);
    	get(j,b,ln);
    	get1(j,d,ln);
    	int bo1 = -1, bo2 = -1;
    	for(int k = 2;k <= ln + 1;k ++) {
    	  if(a[k] == -1 || b[k] == -1) { bo1 = -2; break; }
				if(a[k] > b[k]) { bo1 = 1; break; }
				if(a[k] < b[k]) { bo1 = 0; break; }
			}
    	for(int k = 2;k <= ln + 1;k ++) {
    	  if(c[k] == -1 || d[k] == -1) { bo2 = -2; break; }
				if(c[k] > d[k]) { bo2 = 1; break; }
				if(c[k] < d[k]) { bo2 = 0; break; }
			}
			if(bo1 == -2 || bo2 == -2) continue;
			if(bo1 == 1 && bo2 == 1) {
//				print();
				return 0;
			}
			if(bo1 == 0 && bo2 == 0) {
//				print();
				return 0;
			}
		}
	}
	return 1;
}

inline void solve() {
  int sum = n * m, Ans = 0;
  for(int sta = 0;sta < (1 << sum);sta ++) {
    for(int i = 1;i <= n;i ++) {
      for(int j = 1;j <= m;j ++) {
        int x = (i - 1) * m + j;
        if(sta & (1 << (x - 1))) g[i][j] = 1;
        else g[i][j] = 0;
	    }
	  }
//	  if(g[1][1] != 1 || g[n][m] != 1) continue;
//	  if(g[1][2] != 0 || g[2][1] != 0) continue;
//		cout << sta << endl;
	  if(check()) { 
		  Ans ++;
//      for(int i = 1;i <= n;i ++) {
//        for(int j = 1;j <= m;j ++) printf("%d ", g[i][j]);
//        puts("");
//   	  }
//   	  puts("");
   	}
  }
  printf("%d\n", Ans);
}

}

inline ll get(int x) {
	ll tmp = 1;
  for(int i = 1;i <= x;i ++) {
    tmp *= 2;
	}
}

inline ll power(ll x, ll k) {
  ll tmp = 1;
	while(k) {
		if(k & 1) tmp = tmp * x % MOD;
		x = x * x % MOD;
		k >>= 1;
  }
  return tmp;
}

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d", &n, &m);
	if(n != 2 && n <= 8 && m <= 8) {
	  work1::solve();
	  return 0;
	}
	ll Ans = power(3,m - 1);
	Ans = (ll)Ans * 2 % MOD * 2 % MOD;
	printf("%lld\n", Ans);
  return 0;
}
