#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
template<class T> inline void read(T&x)
{
	char c = getchar(); T p = 1, n = 0;
	while(c < '0' || c > '9') {if(c == '-') p = -1; c = getchar();}
	while(c >= '0' && c <= '9'){n = n * 10 + c - '0'; c = getchar();}
	x = p * n;
}
template<class T, class U> inline void read(T&x, U&y){read(x), read(y);}
const int maxn = 1e5 + 100;
int a[maxn];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n; read(n);
	int ans = 0;
	read(a[0]);
	for(int i = 1; i < n; ++i)
	{
		read(a[i]);
		if(a[i] < a[i - 1]) ans += a[i - 1] - a[i];
	}
	printf("%d\n", ans += a[n - 1]);
	return 0;
}
