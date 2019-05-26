#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int N = 100007, MAX = 10007;
inline int read()
{
	int x = 0, f = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = 1;
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ '0');
	return f ? -x : x;
}
int max(int a, int b) { return a > b ? a : b; }

ll ans;
int n, d[N];

#define lson rt << 1
#define rson rt << 1 | 1
int mi[N << 2], mipos[N << 2];
void build(int rt, int l, int r)
{
	if (l == r) { mi[rt] = d[l], mipos[rt] = l; return; }
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	if (mi[lson] < mi[rson]) mi[rt] = mi[lson], mipos[rt] = mipos[lson];
	else mi[rt] = mi[rson], mipos[rt] = mipos[rson];
}
int mival, mipo;
void qrymin(int rt, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{
		if (mi[rt] < mival) mival = mi[rt], mipo = mipos[rt];
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid) qrymin(lson, l, mid, ql, qr);
	if (mid + 1 <= qr) qrymin(rson, mid + 1, r, ql, qr);
}

void solve(int l, int r, int res)
{
	if (l == r) { ans += max(d[l] - res, 0); return; }
	if (l > r) return;
	mival = MAX, mipo = 0;
	qrymin(1, 1, n, l, r);
	int tmp1 = mival, tmp2 = mipo;
	ans += tmp1 - res;
	solve(l, tmp2 - 1, res + tmp1 - res), solve(tmp2 + 1, r, res + tmp1 - res);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++) d[i] = read();
	build(1, 1, n);
	solve(1, n, 0);
	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

