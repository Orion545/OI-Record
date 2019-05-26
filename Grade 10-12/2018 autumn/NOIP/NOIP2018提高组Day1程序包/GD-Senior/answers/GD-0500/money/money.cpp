#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define F(i, x, y) for (int i = x; i <= y; i++)
#define D(i, x, y) for (int i = x; i >= y; i--)

using namespace std;

const int N = (1e5 + 5);

int T, n, m, ans;
int a[N], d[N];
long long f[N];

void work()
{
	int mx, k;
	scanf("%d", &n), ans = n;
	F(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1), mx = a[n];
	F(i, 0, a[n]) f[i] = 0, d[i] = 0;
	F(i, 1, n) f[a[i]] = d[a[i]] = 1;
	F(i, 0, mx)
	{
		F(j, 1, n)
		{
			k = i - a[j];
			if (k <= 0) break;
			f[i] += f[k];
		}
	}
	F(i, 0, mx)
		if (f[i] > 1 && d[i]) ans--;
	printf("%d\n", ans);
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	for (scanf("%d", &T); T; T--) work();
	
	return 0;
}
