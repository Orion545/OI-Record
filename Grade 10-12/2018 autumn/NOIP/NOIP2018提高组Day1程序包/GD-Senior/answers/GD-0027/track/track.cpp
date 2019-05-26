#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 5e4 + 10 ;

struct Link {
	int num , val ;
	Link *next ;
}list[MAX_N << 1] ;
struct Edge {
	int x , y , v ;
}eg[MAX_N] ;

bool chl , chj ;
Link *head[MAX_N] ;
int n , m , cur , tot ;

///

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

void ins(int x , int y , int v) {
	list[cur].num = y ;
	list[cur].val = v ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

///

int dis[MAX_N] ;

void work1_dfs(int x , int fa) {
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		dis[nx] = dis[x] + h->val ;
		work1_dfs(nx , x) ;
	}
}

void work1() {
	dis[1] = 0 ;
	work1_dfs(1 , 1) ;

	int md = 0 , p = -1 ;
	for (int i = 1 ; i <= n ; ++i) if (dis[i] > md) md = dis[i] , p = i ;
	dis[p] = 0 ; work1_dfs(p , p) ;

	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) ans = std::max(ans , dis[i]) ;

	printf("%d\n" , ans) ;
}

///

bool work2_cmp(Edge a , Edge b) {return a.x < b.x ;}

bool work2_check(int x) {
	int tmp = 0 , k = 0 ;
	for (int i = 1 ; i < n ; ++i) {
		tmp += eg[i].v ;

		if (tmp >= x) ++k , tmp = 0 ;
	}

	return k >= m ;
}

void work2() {
	std::sort(eg + 1 , eg + n , work2_cmp) ;

	int L = 0 , R = tot + 1 ;
	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 ;

		if (work2_check(mid)) L = mid ;
		else R = mid ;
	}

	printf("%d\n" , L) ;
}

///


bool work3_cmp(Edge a , Edge b) {return a.v < b.v ;}

bool work3_check(int x) {
	int L = 1 , R = n - 1 , k = 0 ;

	for (; R ;) if (eg[R].v >= x) {++k ; --R ;} else break ;

	for (; L < R ;) {
		for (; L < R && eg[L].v + eg[R].v < x ; ++L) ;

		if (L < R) ++k , ++L , --R ;
	}

	return k >= m ;
}

void work3() {
	std::sort(eg + 1 , eg + n , work3_cmp) ;

	int L = 0 , R = tot + 1 ;
	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 ;

		if (work3_check(mid)) L = mid ;
		else R = mid ;
	}

	printf("%d\n" , L) ;
}

///

int main() {
	freopen("track.in" , "r" , stdin) ;
	freopen("track.out" , "w" , stdout) ;

	n = read() ; m = read() ;

	chl = 1 ;
	for (int i = 1 ; i < n ; ++i) {
		int a , b , v ;
		a = read() ; b = read() ; v = read() ;

		ins(a , b , v) ; ins(b , a , v) ;
		eg[i] = (Edge){a , b , v} ;
		tot += v ;

		if (b != a + 1) chl = 0 ;
		if (a != 1) chj = 0 ;
	}

	///

	if (m == 1) work1() ;
	else if (chl) work2() ;
	else work3() ;

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}