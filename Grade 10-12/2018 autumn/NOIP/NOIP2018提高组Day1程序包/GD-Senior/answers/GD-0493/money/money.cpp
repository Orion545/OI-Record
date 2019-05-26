#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define _FOR(i,a,b) for (register int i = (a); i<=(b); i++)
using namespace std;
const int maxn = 101;
int T, N, A[maxn], minA, maxA, cnt = 1;
bool yu[maxn];
void init(int x)
{
	int fx;
	_FOR(i,0,maxA)
	{
		if (!yu[i]) continue;
		fx = x;
		while (fx<=maxA)
		{
			yu[fx+i] = 1;
			fx+=x;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 1;
		memset(yu, 0, sizeof(yu));
		yu[0] = 1;
		scanf("%d", &N);
		_FOR(i,1,N)
		{
			scanf("%d", A+i);
		}
		sort(A+1, A+1+N);
		minA = A[1];
		maxA = A[N];
		init(A[1]);
		_FOR(i,2,N)
		{
			if (yu[A[i]]) continue;
			cnt++;
			init(A[i]);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
