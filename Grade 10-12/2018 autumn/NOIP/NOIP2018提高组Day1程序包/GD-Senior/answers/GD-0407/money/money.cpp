#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std ;

const int INF = 2000000000,N = 101 ;

int a[N],Gcd,ans,n,tot,c[N] ;
bool b[25001] ;

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

inline int preset() {
	Gcd = 0 ;
	ans = INF ;
	for (int i = 1 ; i <= 25000 ; i++) {
		b[i] = 0 ;
	}
	for (int i = 1 ; i <= 100 ; i++) a[i] = 0 ;
}

int gcd(int x,int y) {
	if (y == 0) return x ;
	return gcd(y,x % y) ;
}

int exgcd(int x,int y,int &a,int &b) {
	if (y == 0) {
		a = 1 ;
		b = 0 ;
		return x ;
	} 
	int x1 = x % y ;
	exgcd(y,x % y,b,a) ;
	a = a ;
	b = b - a * (x / y) ;
}

inline bool judge(int z,int x,int y) {
	int a,b ;
	exgcd(x,y,a,b) ;
	if (a >= 0)return (a * z / y > (-b) * z / x) ;
	return (b * z / x > ((-a) * z / y)) ;
}

int main() {
	freopen("money.in","r",stdin) ;
	freopen("money.out","w",stdout) ;
	int TTT = read() ;
	while (TTT--) {
		preset() ;
		n = read() ;
		for (int i = 1 ; i <= n ; i++) {
			a[i] = read() ;
			b[a[i]] = 1 ;
			
		}
		for (int i = 1 ; i < n ; i++) {
			for (int j = i + 1 ; j <= n ; j++) {
				if (a[i] % a[j] == 0) a[i] = a[j] ;
				  else if (a[j] % a[i] == 0) a[j] = a[i] ;
			}
		}
		sort(a + 1,a + n + 1) ;
		for (int i = 1 ; i <= n ; i++) {
			Gcd = gcd(Gcd,a[i]) ;
		}
		for (int i = 1 ; i <= n ; i++) {
			a[i] = a[i] / Gcd ;
		}
		tot = 0 ;
		for (int i = 1 ; i < n ; i++) {
			if (a[i] == a[i + 1]) {
				tot++ ;
				a[i] = INF ;
			}
		} 
		sort(a + 1,a + n + 1) ;
		n = n - tot ;
		if (a[1] == 1) {
			ans = 1 ;
		} else if (n == 2) {
			if (a[1] == 1) ans = 1 ;
			  else ans = 2 ;
		} else {
			c[1] = a[1] ;
			c[2] = a[2] ;
			int g = gcd(a[1],a[2]) ;
			int x = c[1] * c[2] / g  - c[1] - c[2] + g ;
			for (int i = 3 ; i <= n ; i++) {
				if (a[i] >= x) {
					n = i - 1 ;
					break ;
				}
			}
			int n1 = 1 ;
			int n2 = 1 ;
			while (n2 < n) {
				bool p = 0 ;
				++n1 ;
				++n2 ;
				while (a[n2] == 0) {
					n2++ ;
					if (n2 > n) break ;
				}
				if (n2 > n) {
					n1-- ;
					n = n1 ;
					break ;
				} 
				c[n1] = a[n2] ;
				for (int i = 1 ; i < n1 ; i++) {
					//int g = gcd(a[i],a[n1]) ;
					//int x = c[i] * c[n1] / g  - c[i] - c[n1] + g ;
					//for (int i = n1 + 1 ; i <= n ; i++) {
					//	if (a[i] >= x) {
					//		n = i - 1 ;
					//		p = 1 ;
					//		break ;
					//	}
					//}	
					for (int j = n2 + 1 ; j <= n ; j++) {
						if (judge(a[j],c[i],c[n1])) a[j] = 0 ;
					}				
				}
				//if (!p) break ;
			}
			ans = n1 ;
/*			for (int i = 2 ; i <= n ; i++) {
				for (int j = 1 ; j < i ; j++) {
					for (int k = i + 1 ; k <= n ; k++) {
						if (judge(k,c[i],c[j])) c[k] 
					}
				}
			}*/
		}
		cout << ans << '\n' ;
	} 
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
