#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define int long long
#define MOD 1000000007
using namespace std;
int n, m;
signed main(void)
{
	///*
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	//*/
	scanf("%lld %lld", &n, &m);
	int res = 1;
	for(int i = 1; i <= m; i++) 
	{
		res = res*2;
		if(res > MOD)	res -= MOD;
	}
	printf("%lld\n", res);
	return 0;
}
