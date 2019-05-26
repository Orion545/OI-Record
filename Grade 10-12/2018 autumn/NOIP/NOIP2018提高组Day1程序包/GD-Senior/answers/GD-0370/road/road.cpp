// road.cpp
// NOIP2018 2018.11.10
// GD-0370 HurryPeng

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	long long int n = 0;
	cin >> n;
	long long int ans = 0;
	stack<int> dp;
	dp.push(0);
	for (int i = 1; i <= n + 1; i++)
	{
		long long int temp = 0;
		if (i == n + 1) temp = 0;
		else cin >> temp;
		long long int high = dp.top();
		while (temp < dp.top()) dp.pop();
		dp.push(temp);
		if (high > temp) ans += high - temp;
	}
	
	cout << ans;
	
	return 0;
}

