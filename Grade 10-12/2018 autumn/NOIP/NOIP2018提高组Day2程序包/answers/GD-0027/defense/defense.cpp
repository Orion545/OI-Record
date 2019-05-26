#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long

const ll INF = 1e12 ;
const int MAX_N = 1e5 + 10 , MAX_M = 2e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_M] ;

char op[10] ;
ll f[MAX_N][2] ;
Link *head[MAX_N] ;
int n , m , px , py , vx , vy , cur , p[MAX_N] ;

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

void dp(int x , int fa) {
	ll s1 = 0 , s2 = 0 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		dp(nx , x) ;
		s1 += std::min(f[nx][0] , f[nx][1]) ; s2 += f[nx][1] ;
	}

	f[x][0] = s2 ; f[x][1] = p[x] + s1 ;

	if (x == px) f[x][vx^1] = INF ;
	else if (x == py) f[x][vy^1] = INF ;
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main() {
	freopen("defense.in" , "r" , stdin) ;
	freopen("defense.out" , "w" , stdout) ;

	n = read() ; m = read() ; scanf("%s" , op) ;
	for (int i = 1 ; i <= n ; ++i) p[i] = read() ;
	for (int i = 1 ; i < n ; ++i) {
		int a , b ;
		a = read() ; b = read() ;

		ins(a , b) ; ins(b , a) ;
	}

	///

	for (int i = 0 ; i < m ; ++i) {
		int a , b , x , y ;
		a = read() ; x = read() ; b = read() ; y = read() ;

		px = a ; py = b ; vx = x ; vy = y ;
		dp(1 , 1) ;

		ll ans = std::min(f[1][0] , f[1][1]) ;
		if (ans >= INF) printf("-1\n") ;
		else printf("%lld\n" , ans) ;
	}

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}