#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef set<int>::iterator It;
int _min(int x, int y) {return x < y ? x : y;}
int _max(int x, int y) {return x > y ? x : y;}
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
void put(int x) {
	if(x < 10) putchar(x + '0');
	else put(x / 10), putchar(x % 10 + '0');
}

struct edge {
	int x, y, next;
} e[11000]; int len, last[5100];
int mm, st, sm[5100];
int gh, lh, gg[5100], ll[5100];
bool v[5100], bk;
int ff[5100][5100];
int ii, pp, ans[5100];
int tp = 0, sta[5100];

void ins(int x, int y) {
	e[++len].x = x, e[len].y = y;
	e[len].next = last[x], last[x] = len;
}

void dfs(int x) {
	ff[pp][++ii] = x;
	int fg = tp + 1;
	for(int k = last[x]; k; k = e[k].next) if(k != gg[pp] && (k ^ 1) != gg[pp]){
		int y = e[k].y;
		if(!v[y]) v[y] = 1, sta[++tp] = y;
	} if(fg > tp) return ;
	sort(sta + fg, sta + tp + 1);
	int yy = tp;
	for(int i = fg; i <= yy; i++) dfs(sta[i]);
}

void dfs2(int x, int fa) {
	if(bk) return ;
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		if(y != fa) {
			if(v[y]) {
				int uu = mm, now = k;
				while(e[now].x != y) {
					gg[++gh] = now;
					now = sm[uu--];
				} gg[++gh] = now; bk = 1; return ;
			}
			v[y] = 1;
			sm[++mm] = k;
			dfs2(y, x);
			if(bk) return ;
			--mm;
		}
	}
}

//void solve() {
//	for(int i = 1; i <= gh; i++) v[gg[i]] = 1;
//	dfs(gg[st]);
//	int h1 = st - 1, h2 = st + 1;
//	if(h1 == 0) h1 = gh; if(h2 == gh + 1) h2 = 1;
//	if(h1 == h2) dfs(h1);
//	else {
//		if(gg[h1] < gg[h2]) {
//			for(int i = st; i >= 1; i--) ll[++lh] = gg[i];
//			for(int i = gh; i > st; i--) ll[++lh] = gg[i];
//		} else {
//			for(int i = st; i <= gh; i++) ll[++lh] = gg[i];
//			for(int i = 1; i < st; i++) ll[++lh] = gg[i];
//		}
//		int last = lh + 1;
//		for(int i = 2; i <= lh; i++) {
//			if(ll[i] <= ll[lh]) dfs(ll[i]);
//			else {last = i; break;}
//		} for(int i = lh; i >= last; i--) dfs(ll[i]);
//	}
//}

//void dfs3(int x) {
//	if(belong[x]) {st = belong[x]; solve(); return ;}
//	put(x); putchar(' ');
//	int tp = 0, sta[5100];
//	for(int k = last[x]; k; k = e[k].next) {
//		int y = e[k].y;
//		sta[++tp] = y;
//	} sort(sta + 1, sta + tp + 1);
//	for(int i = 1; i <= tp; i++) if(!v[sta[i]]) v[sta[i]] = 1, dfs3(sta[i]);
//}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n = read(), m = read();
	if(n == m + 1) {
		for(int i = 1; i < n; i++) {
			int x = read(), y = read();
			ins(x, y), ins(y, x);
		} v[1] = 1; gg[0] = -1; dfs(1);
		for(int i = 1; i <= n; i++) printf("%d ", ff[0][i]);
	} else {
		len = 1; 
		for(int i = 1; i <= n; i++) {
			int x = read(), y = read();
			ins(x, y), ins(y, x);
		} v[1] = 1; dfs2(1, 0);
		for(int i = 1; i <= gh; i++) {
			pp = i; ii = 0;
			memset(v, 0, sizeof(v));
			v[1] = 1; tp = 0; dfs(1);
		} memset(ans, 63, sizeof(ans));
		for(int i = 1; i <= gh; i++) {
			bool kk = 0;
			for(int j = 1; j <= n; j++) {
				if(ff[i][j] < ans[j]) {kk = 1; break;}
				else if(ff[i][j] > ans[j]) break;
			} if(kk) for(int j = 1; j <= n; j++) ans[j] = ff[i][j];
		} for(int i = 1; i <= n; i++) put(ans[i]), putchar(' ');
//		if(belong[1]) {
//			st = 1; solve();
//		} else {
//			v[1] = 1; dfs3(1); 
//		}
	}
	return 0;
}

