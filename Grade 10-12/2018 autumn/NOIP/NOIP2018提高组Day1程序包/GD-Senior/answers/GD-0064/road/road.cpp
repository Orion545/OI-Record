#include <iostream>
#include <cstdio>
#define repu(i, x, y) for (int i = x; i <= y; ++i)
using namespace std;
const int MAXN = 100011;
int n, d[MAXN][25], ans;
void init()
{
	for (int j = 1; (1 << j) <= n; j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int l, int r)
{
	int len = r - l + 1, j = 0;
	while ((1 << j) <= len) j++; j--;
	return min(d[l][j], d[r - (1 << j) + 1][j]);
}
void solve(int l, int r, int off)
{
	int mind = query(l, r);
	ans += mind - off;
	off += mind - off;
	int lp = l;
	while (lp <= r)
	{
		while (lp <= r && d[lp][0] <= off) lp++;
		int rp = lp;
		while (rp <= r && d[rp][0] > off) rp++;
		rp--;
		if (lp <= rp) solve(lp, rp, off);
		lp = rp + 1;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	repu(i, 1, n) scanf("%d", &d[i][0]);
	init();
	solve(1, n, 0);
	printf("%d\n", ans);
	return 0;
}
