// money.cpp
// NOIP2018 2018.11.10
// GD-0370 HurryPeng

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int Dp[25001] = {0}; // 0 unknown, 1 unavailable, 2 available
int A[101] = {0};

bool dfs(const int & cash)
{
	if (Dp[cash])
	{
		if (Dp[cash] == 1) return false;
		else return true;
	}
	for (register int i = 1; i <= cash / 2; i++)
	{
		int j = cash - i;
		if (dfs(i) && dfs(j))
		{
			Dp[cash] = 2;
			return true;
		}
	}
	Dp[cash] = 1;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		memset(Dp, 0, sizeof(Dp));
		for (register int i = 1; i <= n; i++) cin >> A[i];
		sort(A + 1, A + n + 1);
		for (register int i = 1; i < A[1]; i++) Dp[i] = 1;
		
		int ans = n;
		for (register int i = 1; i <= n; i++)
		{
			if (dfs(A[i])) ans--;
			else Dp[A[i]] = 2;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}

