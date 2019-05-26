#include<bits/stdc++.h>
#define MAXN 100005
#define MAXS 10004
using namespace std ;	int n ;
const double eps = 1e-7 ;
const double inf = 1e18 ;
inline int read() {
	register int ch = getchar() ;
	while (!isdigit(ch))	ch = getchar() ;
	register int rtn = 0 ;
	while (isdigit(ch))	rtn = rtn*10 + ch - '0', ch = getchar() ;
	return rtn ;
}
 
int pre[MAXN], pos[MAXS], col[MAXN] ;
int cnt[MAXN] ;
long long f[MAXN] ; 
 
vector<int> que[MAXS] ;
int top[MAXS] ;
 
long long X[MAXN], Y[MAXN] ;
inline double get_K(int u, int v) {
	if (X[u] == X[v])	return inf ;
	return ((double)Y[u] - Y[v]) / ((double)X[u] - X[v]) ; 
}
 
int main() {
	//freopen("1.in","r",stdin) ;
 
	n = read() ;
	for (int i=1; i<=n; ++i) {
		col[i] = read() ;
		pre[i] = pos[ col[i] ] ;
		pos[ col[i] ] = i ;
		cnt[i] = cnt[ pre[i] ] + 1 ;
	}
 
	memset(pos,0,sizeof pos) ;
	for (int i=1; i<=n; ++i)
		if (!pos[col[i]])
			que[col[i]].push_back(0), pos[ col[i] ] = 1 ;
	
	for (int i=1; i<=n; ++i) {
		int x = col[i], k = 2*cnt[i] ;
		
		X[i] = 1ll*cnt[ pre[i] ] * col[i] ;
		Y[i] = 1ll*col[i] * cnt[ pre[i] ] * cnt[ pre[i] ] + f[i-1] ;
 
		while ( top[x] > 0 && get_K ( que[x][ top[x]-1 ] , que[x][ top[x] ] ) < get_K ( que[x][ top[x] ], i )-eps )
			--top[x], que[x].pop_back() ;
		que[x].push_back(i), ++top[x] ;		
		
//		printf("i = %d\n",i) ;
//		printf("top = %d\n",top[x]) ;
//		printf("%d %d\n",que[x][ top[x]-1 ], que[x][ top[x] ] ) ;
		while ( top[x] > 0 && get_K ( que[x][ top[x]-1 ] , que[x][ top[x] ] ) - eps < k )
			--top[x], que[x].pop_back() ;
		int j = que[x][ top[x] ] ;
		f[i] = 1ll*col[i]*cnt[i]*cnt[i] + ( -2ll*cnt[i]* ( cnt[ pre[j] ] * col[j] ) + 1ll * col[j] * cnt[ pre[j] ] * cnt[ pre[j] ] + f[j-1] ) ;
	}
 
//	for (int i=1; i<=n; ++i)	printf("%lld ",f[i]) ;
//	puts("") ;
	printf("%lld\n",f[n]) ;
 
	return 0 ;
}
 

