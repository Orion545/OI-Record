#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define REP(i, a, b) for(register int i = (a); i < (b); i++)
#define _for(i, a, b) for(register int i = (a); i <= (b); i++)
using namespace std;

const int N = 1e5 + 10;
int a[N], n;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d", &n);
	_for(i, 1, n) scanf("%d", &a[i]);
	
	int pre = 0, maxt = a[1], ans = 0;
	_for(i, 1, n)
		if(a[i] < a[i+1] || i == n)
		{
			ans += maxt - pre;
			pre = a[i];
			maxt = a[i+1];
		}

	printf("%d\n", ans);
	
	return 0;
}
