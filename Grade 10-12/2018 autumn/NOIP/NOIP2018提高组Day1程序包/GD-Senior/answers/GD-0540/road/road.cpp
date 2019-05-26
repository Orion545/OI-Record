#include <iostream>
#include <cstdio>
#include <cmath>

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

const int N = 100005;

long long ans;

int a[N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	for (int i = n; i >= 1; i--)
		a[i] -= a[i - 1];
	for (int i = 1; i <= n; i++)
		if (a[i] > 0)
			ans += a[i];
	std::cout<<ans<<std::endl;
}
