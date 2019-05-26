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
const int maxn = 200, maxa = 30000;
int a[maxn], ti[maxa];
bool flag[maxa];
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int t; read(t);
	while(t--)
	{
		int n; read(n);
		for(int i = 0; i < n; ++i) read(a[i]);
		sort(a, a + n);
		int ans = n;
		memset(flag, false, sizeof flag);
		memset(ti, 0, sizeof ti);
		for(int i = 0; i < n; ++i) 
			if(flag[a[i]]) --ans;
			else
			{
				flag[a[i]] = true; ti[a[i]] = i - 1;
				for(int k = 1; k < maxa; ++k) if(flag[k] && ti[k] < i)
					for(int j = k; j < maxa; j += a[i])
						flag[j] = true, ti[j] = i;
			}
		printf("%d\n", ans);
	}
	return 0;
}
