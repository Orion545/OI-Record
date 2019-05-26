#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
LL _min(LL x, LL y) {return x < y ? x : y;}
LL _max(LL x, LL y) {return x > y ? x : y;}
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}

struct edge {
	int x, y, next;
} e[4100]; int len, last[2100];
int a, X, b, Y;
int A[2100]; LL f[2][2100];
LL s1[2][110000], s2[2][110000];
char ss[10];

void ins(int x, int y) {
	e[++len].x = x, e[len].y = y;
	e[len].next = last[x], last[x] = len;
}

void treedp(int x, int fa) {
	f[0][x] = 0, f[1][x] = A[x];
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		if(y != fa) {
			treedp(y, x);
			if(f[0][x] != -1) {
				if(f[1][y] == -1) f[0][x] = -1;
				else f[0][x] += f[1][y];
			}
			if(f[1][x] != -1) {
				int hh = f[0][y];
				if(hh == -1) hh = f[1][y];
				else if(f[1][y] != -1) hh = _min(hh, f[1][y]);
				if(hh == -1) f[1][x] = -1;
				else f[1][x] += hh;
			}
		}
	} if(x == a) f[X ^ 1][x] = -1;
	if(x == b) f[Y ^ 1][x] = -1;
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int n = read(), m = read(); scanf("%s", ss + 1);
	for(int i = 1; i <= n; i++) A[i] = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		ins(x, y), ins(y, x);
	}
	if(n <= 2000 && m <= 2000) {
		for(int i = 1; i <= m; i++) {
			a = read(), X = read(), b = read(), Y = read();
			treedp(1, 0); LL ans = f[0][1];
			if(ans == -1) ans = f[1][1];
			else if(f[1][1] != -1) ans = _min(ans, f[1][1]);
			printf("%lld\n", ans);
		} return 0;
	}
	if(ss[1] == 'A' && ss[2] == '1') {
		s1[1][1] = A[1]; s1[0][1] = 999999999;
		for(int i = 2; i <= n; i++) {
			s1[0][i] = 0, s1[1][i] = A[i];
			s1[0][i] = s1[1][i - 1];
			s1[1][i] += _min(s1[0][i - 1], s1[1][i - 1]);
		}
		for(int i = n; i >= 1; i--) {
			s2[1][i] = A[i];
			s2[0][i] = s2[1][i + 1];
			s2[1][i] += _min(s2[0][i + 1], s2[1][i + 1]);
		}
		for(int i = 1; i <= m; i++) {
			a = read(), X = read(), b = read(), Y = read();
			if(a == b && X != Y) printf("-1\n");
			else {
				if(Y == 0) printf("%lld\n", s1[1][b - 1] + s2[1][b + 1]);
				else printf("%lld\n", _min(s1[0][b - 1], s1[1][b - 1]) + _min(s2[0][b + 1], s2[1][b + 1]) + A[b]);
			}
		}
	} else if(ss[1] == 'A' && ss[2] == '2') {
		for(int i = 1; i <= n; i++) {
			s1[0][i] = 0, s1[1][i] = A[i];
			s1[0][i] = s1[1][i - 1];
			s1[1][i] += _min(s1[0][i - 1], s1[1][i - 1]);
		}
		for(int i = n; i >= 1; i--) {
			s2[1][i] = A[i];
			s2[0][i] = s2[1][i + 1];
			s2[1][i] += _min(s2[0][i + 1], s2[1][i + 1]);
		}
		for(int i = 1; i <= m; i++) {
			a = read(), X = read(), b = read(), Y = read();
			if(a > b) swap(a, b), swap(X, Y);
			if(X == 0 && Y == 0) printf("-1\n");
			else {
				LL u1; if(X == 0) u1 = s1[1][a - 1];
				else u1 = _min(s1[0][a - 1], s1[1][a - 1]) + A[a];
				LL u2; if(Y == 0) u2 = s2[1][b + 1];
				else u2 = _min(s2[0][b + 1], s2[1][b + 1]) + A[b];
				printf("%lld\n", u1 + u2);
			}
		}
	}
	return 0;
}

