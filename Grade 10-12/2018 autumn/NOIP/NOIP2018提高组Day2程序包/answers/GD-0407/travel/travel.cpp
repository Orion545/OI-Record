#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std ;

const int N = 5001 ;

bool f[N][N],vis[N] ;
int n,m,R[N],x,y,L[N],k ;
int H[200001],l[200001],r[200001],siz[200001],top ;

struct EDGE {
	int x,y ;
}ed[3 * N] ;
int hd[N],tl[N],tot1,tot ;

inline int read() {
	int ret = 0 ;
	char ch = getchar() ;
	while (!(ch >= '0' && ch <= '9')) ch = getchar() ;
	while (ch >= '0' && ch <= '9') {
		ret = ret * 10 + ch - '0' ;
		ch = getchar() ;
	}
	return ret ;
}

inline int ME(int x,int y) {
	//f[x][y] =  1 ;
	ed[++tot1].x = x ;
	ed[tot1].y = y ;
	return 0 ;
}

inline bool cmp(EDGE e1,EDGE e2) {
	if (e1.x != e2.x) return e1.x < e2.x ;
	return e1.y < e2.y ;
}

bool dfs(int i) {
	r[++k] = i ;
	for (int j = 1 ; j <= n ; j++) if (f[i][j]) {
		if (!vis[j]) {
			vis[j] = 1 ;
			dfs(j) ;
		}
	}
	return 0 ;
}

int push(int x,int &k) {
	if (k == 0) {
		k = ++tot ;
		siz[k] = 1 ;
		H[k] = x ;
		l[k] = r[k] = 0 ;
		return 1 ;
	}
	if (x < H[k]) {
		swap(x,H[k]) ;
	}
	if (siz[l[k]] < siz[r[k]]) push(x,l[k]) ;
	  else push(x,r[k]) ;
	siz[k] = siz[l[k]] + siz[r[k]] + 1 ;
	return 1 ;
	
}

int pop(int x) {
	int ret = H[x] ;
	if (siz[x] == 1) {
		l[x] = 0 ;
		r[x] = 0 ;
		H[x] = 0 ;
		siz[x] = 0 ;
		return 0 ;
	}
	if (H[l[x]] > H[r[x]] || l[x] == 0) {
		H[x] = H[r[x]] ;
		r[x] = pop(r[x]) ;
		siz[x] = siz[l[x]] + siz[r[x]] + 1 ;
	} else {
		H[x] = H[l[x]] ;
		l[x] = pop(l[x]) ;
		siz[x] = siz[l[x]] + siz[r[x]] + 1 ;
	}
}

int dfs1 (int i) {
	cout << i << ' ' ;
	for (int j = 1 ; j <= n ; j++) if ((!vis[j]) && f[i][j]) {
		vis[j] = 1 ;
		dfs1(j) ;
	}
}

int main() {
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	n = read() ;
	m = read() ;
	if (n - m == 1) {
		for (int i = 1 ; i <= m ; i++) {
			x = read() ;
			y = read() ;
			f[x][y] = f[y][x] = 1 ;
		}		
		for (int i = 1 ; i <= n ; i++) vis[i] = 0 ;
		vis[1] = 1 ;
		dfs1(1) ;
		cout << '\n' ;
		fclose(stdin) ;
		fclose(stdout) ;
		return 0 ;
	}
/*	for (int i = 1 ; i <= m ; i++) {
		x = read() ;
		y = read() ;
		ME(x,y) ;
		ME(y,x) ;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) vis[j] = 0 ;
		vis[i] = 1 ;
		k = 0 ;
		if (dfs(i)) {
			for (int j = 1 ; j <= n ; j++) {
				cout << r[j] << ' ' ;
			}
			cout << '\n' ;
			break ;
		}
	}
	return 0 ;
	*/
	for (int i = 1 ; i <= m ; i++) {
		x = read() ;
		y = read() ;
		ME(x,y) ;
		ME(y,x) ;
	}
	sort(ed + 1,ed + m * 2 + 1,cmp) ;
	ed[0].x = ed[0].y = 0 ;
	ed[2 * m + 1] = ed[1] ;
	for (int i = 1 ; i <= 2 * m ; i++) {
		if (ed[i].x != ed[i - 1].x) hd[ed[i].x] = i ;
		if (ed[i].x != ed[i + 1].x) tl[ed[i].x] = i ;
	}
	bool p = 0 ;
	for (int i = 1 ; i <= n ; i++) if (tl[i] - hd[i] != 1) p = 1 ;
	if (!p) {
		L[1] = 1 ;
		int t = ed[tl[1]].y ;
		for (int i = 1 ; i <= n ; i++) vis[i] = 0 ;
		vis[1] = 1 ;
		for (int i = 1 ; i <= n ; i++) {
			cout << L[i] << ' ' ;
			for (int j = hd[L[i]] ; j <= tl[L[i]] ; j++) {
				if (!vis[ed[j].y]) {
					if (t < ed[j].y && (!vis[t])) {
						L[i + 1] = t ;
						vis[t] = 1 ;
					} else {
						L[i + 1] = ed[j].y ;
						vis[ed[j].y] = 1 ;
					}
					break ;
				}
			}
		}
		cout << '\n' ;
		fclose(stdin) ;
		fclose(stdout) ;
		return 0 ;
	}
	for (int i = 1 ; i <= n ; i++) vis[i] = 0 ;
	vis[1] = 1 ;
	L[1] = 1 ;
	top = 0 ;
	tot = 0 ;
	l[0] = r[0] = siz[0] = 0 ;
	for (int i = hd[1] ; i <= tl[1] ; i++) push(ed[i].y,top),vis[ed[i].y] = 1 ;
	for (int t = 2 ; t <= n ; t++) {
		L[t] = H[top] ;
		top = pop(top) ;
		for (int i = hd[L[t]] ; i <= tl[L[t]] ; i++) if (!vis[ed[i].y]) {
			push(ed[i].y,top) ;
			vis[ed[i].y] = 1 ;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << L[i] << ' ' ;
	}
	cout << '\n' ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
