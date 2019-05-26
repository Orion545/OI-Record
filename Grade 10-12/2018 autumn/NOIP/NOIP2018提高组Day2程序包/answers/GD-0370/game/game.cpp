// game.cpp
// NOIP2018 2018.11.11
// GD-0370 HurryPeng

#include <stdio.h>
#include <iostream>

const int Mod = 1e9 + 7;

using namespace std;

long long int N = 0, M = 0;

long long int fastPow(long long int base, long long int exp)
{
	long long int ans = 1;
	while (exp)
	{
		if (exp & 1) ans *= base;
		ans %= Mod;
		base *= base;
		base %= Mod;
		exp >>= 1;
	}
	ans %= Mod;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	cin >> N >> M;
	
	if (N == 1)
	{
		cout << fastPow(2, M);
		
		return 0;
	}
	
	if (N == 2)
	{
		cout << fastPow(3, M - 1) * 4 % Mod;
		
		return 0;
	}
	
	return 0;
}

