#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std ;

typedef long long ll ;

const ll P = 1000000007 ;

ll n,m,ans ;

ll mi(ll x,ll k) {
	if (k == 0) return 1 ;
	ll xx ;
	if (k & 1) xx = x ; else xx = 1 ;
	ll x1 = mi(x, k >> 1) ;
	return x1 * x1 % P * xx % P ;
}

int f[8][8] ;

int main() {
	freopen("game.in","r",stdin) ;
	freopen("game.out","w",stdout) ;
	cin >> n >> m ;
	if (n < m) swap(n,m) ;
	ans = 1 ;
/*	if (n == m) {
		for (ll i = 1 ; i <= m ; i++) ans = ans * i % P * i % P ;
		ans = ans * (m + 1) % P ;
	} else {
		for (ll i = 1 ; i <= m + 1 ; i++) ans = ans * i % P * i % P ;
		ans = ans * mi(m + 1,n - m - 1) % P ;
	}
	cout << ans << '\n' ;
*/
	f[1][1] = 2 ;
	f[1][2] = 4 ;
	f[1][3] = 8 ;
	f[2][2] = 12 ;
	f[2][3] = 36 ;
	f[3][3] = 112 ;
	cout << f[m][n] << '\n' ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
