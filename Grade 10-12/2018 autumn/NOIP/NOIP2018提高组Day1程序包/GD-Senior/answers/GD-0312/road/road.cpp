#include <cstdio>
#include <cstring>
#include <iostream>

#define F(i, a, b) for (int i = a; i <= b; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mem(a, b) memset(a, b, sizeof a)

#define Ls (x << 1)
#define Rs (Ls | 1)
#define M (st + en >> 1)

const int N = 2e5 + 10, Mx = 4 * N;

using namespace std;

int n, Ans, Miner, POS, a[N], tr[Mx], w[Mx];

void Modify(int x, int st, int en, int p) {
	if (st == en)
		tr[x] = a[p],
		w[x] = p;
	else
		M >= p ? Modify(Ls, st, M, p) : Modify(Rs, M + 1, en, p),
		tr[x] = min(tr[Ls], tr[Rs]),
		w[x] = tr[x] == tr[Ls] ? w[Ls] : w[Rs];
}

void Find(int x, int st, int en, int l, int r) {
	if (l <= st && en <= r) {
		if (tr[x] < Miner)
			Miner = tr[x], POS = w[x];
		return;
	}
	if (M >= l) Find(Ls, st, M, l, r);
	if (M < r) Find(Rs, M + 1, en, l, r);
}

void Divide(int l, int r, int now) {
	if (l > r || l < 1 || r > n)
		return;
	Miner = 1e9, POS = 0, Find(1, 1, n, l, r);
	int pos = POS, MM = Miner;
	Ans += MM - now, Divide(l, pos - 1, MM), Divide(pos + 1, r, MM);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n), mem(tr, 7);
	F(i, 1, n)
		scanf("%d", &a[i]), Modify(1, 1, n, i);
	Divide(1, n, 0);
	printf("%d\n", Ans);

	return 0;
}
