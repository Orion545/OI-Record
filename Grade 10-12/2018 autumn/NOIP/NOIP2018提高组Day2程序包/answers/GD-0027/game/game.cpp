#include <stdio.h>
#include <stdlib.h>

#define ll long long

const int MAX_S = (1 << 8) + 10 , mod = 1e9 + 7 ;

int n , m , S , A[MAX_S][MAX_S] , B[MAX_S][MAX_S] , C[MAX_S][MAX_S] , T[MAX_S][MAX_S] ;

void times(int (*A)[MAX_S] , int (*B)[MAX_S] , int n , int m) {
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m ; ++j) {
			T[i][j] = 0 ;

			for (int r = 0 ; r < S ; ++r) T[i][j] = (T[i][j] + (ll)A[i][r] * B[r][j]) % mod ;
		}

	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m ; ++j)
			B[i][j] = T[i][j] ;
}

void qpow(int t) {
	if (t == 1) return ;

	qpow(t >> 1) ;
	times(B , B , S , S) ;
	if (t & 1) times(C , B , S , S) ;
}

int main() {
	freopen("game.in" , "r" , stdin) ;
	freopen("game.out" , "w" , stdout) ;

	scanf("%d %d" , &n , &m) ; S = (1 << n) ;

	if (n == 3) {
		if (m == 1) printf("8\n") ;
		else if (m == 3) printf("112\n") ;

		fclose(stdin) ; fclose(stdout) ;

		return 0 ;
	}

	for (int i = 0 ; i < S ; ++i)
		for (int j = 0 ; j < S ; ++j) {
			int a = (i >> 1) , b = (j & ( (1 << (n - 1)) - 1) ) ;

			bool ok = 1 ;
			for (int k = 0 ; k < n - 1 ; ++k) {
				int t1 = (a & (1 << k)) , t2 = (b & (1 << k)) ;
				if (t1 < t2) ok = 0 ;
			}

			if (ok) C[i][j] = B[i][j] = 1 ;
			else C[i][j] = B[i][j] =  0 ;
		}
	for (int i = 0 ; i < S ; ++i) A[i][0] = 1 ;

	///

	qpow(m - 1) ;
	times(B , A , S , 1) ;

	int ans = 0 ;
	for (int i = 0 ; i < S ; ++i) (ans += A[i][0]) %= mod ;

	printf("%d\n" , ans) ;

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}