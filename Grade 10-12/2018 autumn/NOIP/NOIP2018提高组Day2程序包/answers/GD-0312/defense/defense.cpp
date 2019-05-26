#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define F(i, a, b) for (int i = a; i <= b; i ++)
#define G(i, a, b) for (int i = a; i >= b; i --)
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define lowbit(x) ((x) & (- x))
#define get getchar()

const int N = 2e5 + 10;

void Re(int &x) {
	char c = get; x = 0; int t = 1;
	for (; !isdigit(c); c = get) t = (c == '-' ? -1 : t);
	for (; isdigit(c); x = (x << 3) + (x << 1) + c - '0', c = get); x *= t;
}
void Wr(int x) {
	if (x < 0) { putchar('-'); x = - x; }
	if (x > 9) Wr(x / 10); putchar(x % 10 + '0');
}

int n, m, u, v, Now0, Now1, Ans;
int val[N], a[N], b[N], x[N], y[N], f[N][2];
int tov[N], nex[N], las[N], tot; char ch[10];

void ins(int x, int y) {
	tov[++ tot] = y, nex[tot] = las[x], las[x] = tot;
}

void DFS(int k, int La, int p) {
	for (int x = las[k]; x; x = nex[x])
		if (tov[x] ^ La)
			DFS(tov[x], k, p);

	Now0 = Now1 = 0;
	for (int x = las[k]; x; x = nex[x])
		if (tov[x] ^ La) {
			if (Now1 <= 842150450)
				Now1 += min(f[tov[x]][0], f[tov[x]][1]);
			if (Now0 <= 842150450)
				Now0 += f[tov[x]][1];
		}
	if (k == a[p]) {
		if (x[p] == 1) f[k][1] = min(f[k][1], Now1 + val[k]); else f[k][0] = min(f[k][0], Now0);
	} else
	if (k == b[p]) {
		if (y[p] == 1) f[k][1] = min(f[k][1], Now1 + val[k]); else f[k][0] = min(f[k][0], Now0);
	} else
		f[k][1] = min(f[k][1], Now1 + val[k]), f[k][0] = min(f[k][0], Now0);
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);

	Re(n), Re(m), scanf("%s", ch + 1);
	F(i, 1, n) Re(val[i]);
	F(i, 1, n - 1) Re(u), Re(v), ins(u, v), ins(v, u);
	F(i, 1, m) Re(a[i]), Re(x[i]), Re(b[i]), Re(y[i]);

	F(i, 1, m) {
		mem(f, 50);
		DFS(1, 0, i);
		Ans = min(f[1][0], f[1][1]);
		printf("%d\n", Ans >= 842150450 ? - 1 : Ans);
	}
	return 0;
}
