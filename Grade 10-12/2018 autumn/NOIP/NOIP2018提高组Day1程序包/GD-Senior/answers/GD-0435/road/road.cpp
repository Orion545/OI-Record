#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;


typedef long long LL;


const int N = 100010;

const LL INF = 1e16;


int n;

LL a[N];


struct SegmentTree
{
	#define ls (cur << 1)
	#define rs (cur << 1 | 1)

	int pos[N << 2];

	inline int maintain(int L, int R)
	{
		if (a[L] <= a[R])
			return L;
		else
			return R;
	}

	void build(int cur, int l, int r)
	{
		if (l == r)
			pos[cur] = l;
		else
		{
			int mid = (l + r) >> 1;
			build(ls, l, mid);
			build(rs, mid+1, r);
			pos[cur] = maintain(pos[ls], pos[rs]);
		}
	}

	int query(int cur, int l, int r, int ql, int qr)
	{
		if (r < ql || l > qr) return 0;
		if (ql == l && qr == r)
			return pos[cur];
		int mid = (l + r) >> 1;
		if (qr <= mid)
			return query(ls, l, mid, ql, qr);
		else if (ql > mid)
			return query(rs, mid+1, r, ql, qr);
		else
			return maintain(query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr)); 
	}
} seg;


LL solve(int l, int r, LL val)
{
	if (l > r) return 0;
	if (l == r)
		return a[l] - val;
	int p = seg.query(1, 1, n, l, r);
	LL Ans = a[p] - val;
	Ans += solve(l, p-1, val + a[p] - val);
	Ans += solve(p+1, r, val + a[p] - val);
	return Ans;
}


int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	
	a[0] = INF;
	seg.build(1, 1, n);
	
	printf("%lld\n", solve(1, n, 0));
	
	return 0;
}
