#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 100 + 10 , MAX_S = 25e3 + 10 ;

bool f[MAX_S] ;
int T , n , m , ma , a[MAX_N] ;

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

int main() {
	freopen("money.in" , "r" , stdin) ;
	freopen("money.out" , "w" , stdout) ;

	T = read() ;

	for (; T-- ;) {
		n = read() ; ma = 0 ;
		for (int i = 1 ; i <= n ; ++i) a[i] = read() , ma = std::max(ma , a[i]) ;

		///

		for (int i = 0 ; i <= ma ; ++i) f[i] = 0 ;
		f[0] = 1 ;
		std::sort(a + 1 , a + 1 + n) ;

		m = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			int t = a[i] ;
			if (f[t]) continue ;
			++m ;

			for (int i = t ; i <= ma ; ++i) f[i] = f[i - t] || f[i] ;
		}

		printf("%d\n" , m) ;
	}

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}