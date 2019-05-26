# include <bits/stdc++.h>
using namespace std;
# define For(i, s, t) for (int i = (s), _ = (t); i < _; i ++)
const int P = 1e9 + 7;
int n, m, fu, ans;
struct Mat {
	int h, w, a[100][100];
	Mat (int _1 = 0, int _2 = 0) : h(_1), w(_2) {
		memset(a, 0, sizeof a);
	}
	friend Mat operator * (Mat A, Mat B) {
		Mat C(A.h, B.w);
		For (i, 0, C.h)
			For (j, 0, C.w)
				For (k, 0, A.w)
					C.a[i][j] = (C.a[i][j] + 1LL * A.a[i][k] * B.a[k][j]) % P;
		return C;
	}
} f, c, C;
int Judge(int s, int t) {
	For (i, 0, n - 1)
		if ((s >> i & 1) < (t >> i + 1 & 1))
			return 0;
	return 1;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d", & n, & m), fu = 1 << n;
	f = Mat(fu, 1);
	For (s, 0, fu)
		f.a[s][0] = 1;
	c = Mat(fu, fu);
	For (s, 0, fu)
		For (t, 0, fu)
			c.a[s][t] = Judge(s, t);
	C = Mat(fu, fu);
	For (s, 0, fu)
		C.a[s][s] = 1;
	for (m --; m; m >>= 1) {
		if (m & 1)
			C = C * c;
		c = c * c;
	}
	f = C * f;
	For (s, 0, fu)
		ans = (ans + f.a[s][0]) % P;
	printf("%d\n", ans);
	return 0;
}
