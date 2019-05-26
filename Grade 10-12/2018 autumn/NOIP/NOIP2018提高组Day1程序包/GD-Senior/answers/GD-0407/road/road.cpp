#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std ;

const int INF = 2000000000,N = 100001 ;

int n,a[N],c[N],ans ;
int f[1005][1005];

inline int read() {
	int ret = 0,f = 1 ;
	char ch = getchar() ;
	while (!((ch >= '0' && ch <= '9') || (ch == '-'))) ch = getchar() ;
	if (ch == '-') {
		f = -1 ;
		ch = getchar() ;
	}
	while ((ch >= '0' && ch <= '9')) {
		ret = ret * 10 + ch - '0' ;
		ch = getchar() ;
	}
	return f * ret ;
}

int dfs(int i,int x,int sum) {
	int u ;
	if (a[i] < x) return -1 ;

	u = a[i] - x ;
	if (i == n) {
		if (sum + u <= ans) ans = sum + u ;
		return 1 ;
	}
	if (sum < f[i][x]) return -1 ;
	  else f[i][x] = sum ;
	for (int v = 0 ;v <= x + u ; v++) {
		
		dfs(i + 1,x + u - v,sum + u) ;
	}
}

int main() {
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	n = read() ;
	ans = 0 ;
	for (int i = 1 ; i <= n ; i++) {
		a[i] = read() ;
		ans += a[i] ;
	}
	for (int i = 0 ; i < n ; i++) {
		c[i] = a[i] - a[i + 1] ;
	}
	c[n] = a[n] ;
	dfs(1,0,0) ; 
	cout << ans << '\n' ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
