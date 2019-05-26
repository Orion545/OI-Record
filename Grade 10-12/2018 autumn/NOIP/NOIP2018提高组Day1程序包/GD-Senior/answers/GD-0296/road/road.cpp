#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 100005
using namespace std;
int n, ans;
int num[maxn], minn[maxn];
int main(void)
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(minn, 0x3f, sizeof(minn));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)		scanf("%d", &num[i]);
	for(int i = 1; i <= n; i++)		minn[i] = min(num[i], minn[i-1]);
	for(int i = 2; i <= n; i++)
		if(num[i] != num[i-1] && minn[i] < num[i])	ans += abs(num[i]-num[i-1]);
	//for(int i = 2; i <= n; i++)
	//	if(num[i] != num[i-1])		ans += abs(num[i]-num[i-1]);
	
	/*
	for(int i = 2; i <= n; i++)
	{
		if(num[i] != num[i-1])		ans += abs(num[i]-num[i-1]);
		if(minn[i] >= num[i])		ans -= num[i];
	}
	*/
	
	printf("%d\n", ans+minn[n]);
	return 0;
}
