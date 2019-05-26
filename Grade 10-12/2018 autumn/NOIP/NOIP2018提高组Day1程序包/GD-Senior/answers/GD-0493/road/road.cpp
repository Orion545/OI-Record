#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define _FOR(i,a,b) for (register int i = (a); i<=(b); i++)
#define _MID ((L+R)>>1)
using namespace std;
const int maxn = 100000+1, maxt = 400000+1;
int N, D[maxn], cnt = 0, last = 0;
inline int lc(int x)
{
	return x<<1;
}
inline int rc(int x)
{
	return(x<<1)|1;
}
struct SGT
{
	int T[maxt], tag[maxt];
	void pushup(int p)
	{
		T[p] = min(T[lc(p)], T[rc(p)]);
	}
	void build(int p, int L, int R)
	{
		if (L==R)
		{
			T[p] = D[L];
			return;
		}
		int mid = _MID;
		build(lc(p), L, mid);
		build(rc(p), mid+1, R);
		pushup(p);
	}
	void f_minus(int p, int k)
	{
		T[p] -= k;
		tag[p] += k;
	}
	void pushdown(int p, int L, int R)
	{
		f_minus(lc(p), tag[p]);
		f_minus(rc(p), tag[p]);
		tag[p] = 0;
	}
	void update(int p, int L, int R)
	{
		int tmp = T[p];
		if (tmp)
		{
			cnt+=tmp;
//			printf("%d %d\n", L, R);
			f_minus(p, tmp);
			return;
		}
		if (L==R) return;
		pushdown(p, L, R);
		int mid = _MID;
		update(lc(p), L, mid);
		update(rc(p), mid+1, R);
//		pushup(p);
	}
} sgt;
int main()
{
	scanf("%d", &N);
	_FOR(i,1,N)
	{
		scanf("%d", D+i);
	}
	sgt.build(1,1,N);
	while (1)
	{
		sgt.update(1,1,N);
		if (cnt == last) break;
		last = cnt;
	}
	printf("%d\n", cnt);
	return 0;
}
