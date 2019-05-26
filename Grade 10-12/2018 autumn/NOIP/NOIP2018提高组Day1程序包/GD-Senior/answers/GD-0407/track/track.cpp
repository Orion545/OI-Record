#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std ;

const int N = 100005 ;

struct EDGE {
	int x,y,k ;
} ed[N] ;
int fi[N],ne[N] ;

int n,m,x,y,k,tot,ans,c[N],l,r,mid,cnt ;
bool vis[N] ;

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

inline int ME(int x,int y,int k) {
	ed[++tot].x = x;
	ed[tot].y = y ;
	ed[tot].k = k ;
	ne[tot] = fi[x] ;
	fi[x] = tot ;
	return 0 ;
}

int dfs(int i,int s) {
	if (s >= ans) {
		ans = s ;
		x = i ;
	}
	for (int x = fi[i] ; x ; x = ne[x]) if (!vis[ed[x].y]) {
		vis[ed[x].y] = 1 ;
		dfs(ed[x].y,s + ed[x].k) ;
		vis[ed[x].y] = 0 ;
	}
	return 0 ;
}

int main() {
	freopen("track.in","r",stdin) ;
	freopen("track.out","w",stdout) ;
	n = read() ;
	m = read() ;
	bool p = 0 ;
	for (int i = 1 ; i < n ; i++) {
		x = read() ;
		y = read() ;
		k = read() ;
		ME(x,y,k) ;
		ME(y,x,k) ;
		if (x != 1) p = 1 ;
		c[i] = k ;
	}
	if (m == 1) {
		ans = 0 ;
		for (int i = 1 ; i <= n ; i++) vis[i] = 0 ;
		vis[1] = 1 ;
		dfs(1,0) ;
		for (int i = 1 ; i <= n ; i++) vis[i] = 0 ;
		vis[x] = 1 ;
		dfs(x,0) ;
		cout << ans << '\n' ;
	} else if (!p) {
		sort(c + 1, c + n) ;
		l = c[1] ; r = 2 * c[n - 1] + 1 ;
		while (r - l > 1) {
			mid = (l + r) >> 1 ;
			x = mid ;
			int i ;
			for (i = 1 ; c[i] < x && i < n ; i++) ;
			if (n - i >= m) {
				l = mid ;
				r = r ;
				continue ;
			} else {
				cnt = n - i ;
				int j,j1 ;
				for (j = i - 1,j1 = 1 ; j > j1 ; j-- ) {
					while (c[j] + c[j1] < x && j1 < j) j1++ ;
					if (j1 < j) {
						cnt++ ;
						j1++ ;
					}
				}
				if (cnt >= m) {
					l = mid ;
					r = r ;
				} else {
					l = l ;
					r = mid ;
				}
			}
		}
		cout << l << '\n' ;
	}
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
