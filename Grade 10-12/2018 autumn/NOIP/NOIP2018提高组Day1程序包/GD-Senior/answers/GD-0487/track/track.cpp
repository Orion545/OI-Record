#include <set>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long LL;
typedef multiset<int>::iterator It;
int _min(int x, int y) {return x < y ? x : y;}
int _max(int x, int y) {return x > y ? x : y;}

int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}

struct edge {
	int x, y, c, next;
} e[110000]; int len, last[51000];
int tp, sta[51000];
int dis[51000], fg; int pp1;
int n, m, oo;

void ins(int x, int y, int c) {
	e[++len].x = x, e[len].y = y, e[len].c = c;
	e[len].next = last[x], last[x] = len;
}

void dfs(int x, int fa) {
	if(dis[x] > dis[pp1]) pp1 = x;
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		if(y != fa) {
			dis[y] = dis[x] + e[k].c;
			dfs(y, x);
		}
	}
}

int getans(int x, int fa) {
	tp = 0;
	multiset<int> q;
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		if(y != fa) {
			int df = getans(y, x);
			q.insert(df + e[k].c);
		}
	} if(!q.size()) return 0;
	It gg = q.end(); --gg;
	int jj = *gg;
	while(*gg >= fg) {
		q.erase(gg); ++oo;
		if(!q.size()) return 0;
		gg = q.end(); --gg; jj = *gg;
	}
	gg = q.begin();
	while(gg != q.end()) {
		int cc = *gg;
		It hh = q.lower_bound(fg - cc);
		if(hh == q.end()) {++gg; continue;}
		if(hh == gg) ++hh;
		if(hh == q.end()) {++gg; continue;}
		int pp = *hh;
//		if(pp < cc) break;
		++oo;
		if(pp == cc) {
			It hj = gg;
			++gg; q.erase(hj);
			hj = gg;
			++gg; q.erase(hj);
		} else {
			It hj = gg;
			q.erase(hh);
			++gg; q.erase(hj);
		}
	}
	if(!q.size()) return 0;
	gg = q.end(); --gg;
	return *gg;
}

bool check(int mid) {
	oo = 0; fg = mid;
	getans(1, 0);
	if(oo >= m) return 1;
	return 0;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = read(), m = read();
	bool bk = 0, gg = 0;
	for(int i = 1; i < n; i++) {
		int x = read(), y = read(), c = read();
		if(x + 1 != y) gg = 1;
		sta[++tp] = c;
		if(x != 1) bk = 1;
		ins(x, y, c), ins(y, x, c);
	} dis[1] = 0; pp1 = 0; dfs(1, 0);
	dis[pp1] = 0;int pp = pp1; pp1 = 0; dfs(pp, 0);
	if(m == 1) {
		printf("%d\n", dis[pp1]);
		return 0;
	} if(!bk) {
		sort(sta + 1, sta + tp + 1);
		if(n - 1 >= m * 2) {
			int ans = dis[pp1];
			int uu = tp;
			for(int i = tp - m * 2 + 1; i <= tp; i++) {
				if(i > uu) break;
				ans = _min(ans, sta[i] + sta[uu]);
				uu--;
			} printf("%d\n", ans);
		} else {
			int kk = m * 2 - tp;
			int ans = sta[tp - kk + 1];
			int uu = tp - kk;
			for(int i = 1; i <= tp - kk; i++) {
				if(i > uu) break;
				ans = _min(ans, sta[i] + sta[uu]);
				--uu;
			} printf("%d\n", ans);
		} return 0;
	} if(!gg) {
		int l = 0, r = dis[pp1], ans = 0;
		while(l <= r) {
			int mid = (l + r) / 2;
			int s = 0; int last = n + 1;
			for(int i = n; i >= 1; i--) {
				if(dis[i] - dis[last] >= mid) last = i, ++s;
			}
			if(s >= m) l = mid + 1, ans = mid;
			else r = mid - 1;
		} printf("%d\n", ans);
		return 0;
	} int l = 0, r = dis[pp1], ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	} printf("%d\n", ans);
	return 0;
}

