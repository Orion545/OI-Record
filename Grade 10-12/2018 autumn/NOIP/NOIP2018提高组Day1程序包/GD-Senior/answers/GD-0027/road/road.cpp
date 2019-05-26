#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 1e5 + 10 ;

int n , ans , a[MAX_N] ;

int main() {
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;

	scanf("%d" , &n) ;
	a[0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%d" , &a[i]) ;

		int tmp = a[i] - a[i - 1] ;
		if (tmp > 0) ans += tmp ; 
	}

	printf("%d\n" , ans) ;

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}