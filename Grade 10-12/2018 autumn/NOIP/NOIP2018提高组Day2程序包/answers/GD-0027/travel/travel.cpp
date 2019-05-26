#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 5e3 + 10 ;

struct Edge {
	int x , y ;
}eg[MAX_N << 1] ;
struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
int o , px , py , sta[MAX_N] ;
bool cir[MAX_N] , flag[MAX_N] ;
int n , m , tg , cur , tot , ans[MAX_N] , tmp[MAX_N] ;

///

bool cmp(Edge a , Edge b) {return a.x < b.x || (a.x == b.x && a.y > b.y) ;}

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

///

bool find(int x , int fa) {
	sta[++o] = x ; flag[x] = 1 ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		if (flag[nx]) {
			for (; sta[o] != nx ; --o) cir[sta[o]] = 1 ;
			cir[nx] = 1 ;
		
			return 1 ;
		}
		if (find(nx , x)) return 1 ;
	}

	--o ; flag[x] = 0 ;
	return 0 ;
}

void dfs(int x , int fa) {
	tmp[++o] = x ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;
		if ((x == px && nx == py) || (x == py && nx == px)) continue ;

		dfs(nx , x) ;
	}
}

void upd() {
	bool ok = 0 ;
	for (int i = 1 ; i <= n ; ++i)
		if (ans[i] > tmp[i]) {ok = 1 ; break ;}
		else if (tmp[i] > ans[i]) {ok = 0 ; break ;}

	if (ok) for (int i = 1 ; i <= n ; ++i) ans[i] = tmp[i] ;
}

///

int main() {
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;

	n = read() ; m = read() ;
	for (int i = 0 ; i < m ; ++i) {
		int a , b ;
		a = read() ; b = read() ;

		eg[tg++] = (Edge){a , b} ;
		eg[tg++] = (Edge){b , a} ;
	}

	std::sort(eg + 0 , eg + tg , cmp) ;

	for (int i = 0 ; i < tg ; ++i) {
		Edge *p = &eg[i] ;
		ins(p->x , p->y) ;
	}

	///

	for (int i = 1 ; i <= n ; ++i) ans[i] = n + 1 ;

	px = py = -1 ;
	if (m == n - 1) {
		o = 0 ;
		dfs(1 , 1) ; upd() ;
	}
	else {
		o = 0 ; bool tttmp = find(1 , 1) ;

		for (int i = 0 ; i < tg ; ++i) {
			Edge *p = &eg[i] ;
			if (!cir[p->x] || !cir[p->y]) continue ;

			px = p->x ; py = p->y ;

			o = 0 ; dfs(1 , 1) ;
			upd() ;
		}	
	}

	for (int i = 1 ; i <= n ; ++i) printf("%d " , ans[i]) ;
	printf("\n") ;

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}