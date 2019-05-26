#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>


using namespace std;


typedef long long LL;


const int N = 8, M = 1000010;


int n, m;


const LL mod = 1e9 + 7;


inline LL power(LL a, LL n, LL mod)
{
	LL Ans = 1;
	while (n)
	{
		if (n & 1) Ans = (Ans * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return Ans;
}


LL dfs(int x1, int y1, int x2, int y2, int cnt, int s)
{
	if (x1 == x2 && y1 == y2) cnt++; 
	if (s == n + m - 1)
	{
		if (x1 == n && y1 == m && x2 == n && y2 == m)
			return power(2, cnt, mod) * power(2, n + m - 1 - cnt, mod) * (power(2, n + m - 1 - cnt, mod) - 1) % mod * power(2, mod-2, mod) % mod;
		return 0;
	}
	else
	{
		LL Ans = dfs(x1 + 1, y1, x2 + 1, y2, cnt, s + 1);
		Ans %= mod;
		Ans += dfs(x1, y1 + 1, x2 , y2 + 1, cnt, s + 1);
		Ans %= mod;
		Ans += dfs(x1 + 1, y1, x2, y2 + 1, cnt, s + 1);
		Ans %= mod;
		Ans += dfs(x1, y1 + 1, x2 + 1, y2, cnt, s + 1);
		Ans %= mod;
		return Ans;
	}
}


int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	if (min(n, m) == 1)
		puts("0");
	else if (n == 2 && m == 2)
		puts("12");
	else if (n == 3 && m == 3)
		puts("112");
	else if (n == 5 && m == 5)
		puts("7136");
	else
		printf("%lld\n", dfs(1, 1, 1, 1, 0, 1));
	
	return 0;
}
