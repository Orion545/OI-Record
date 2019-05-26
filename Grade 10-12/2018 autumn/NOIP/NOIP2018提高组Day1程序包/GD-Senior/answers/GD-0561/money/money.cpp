#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#define N 105
using namespace std;

int n,a[N];
int ans;
bool fl,v[N];

int cmp(int x, int y){return x > y;}

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

void dfs(int dep, int x, int num)
{
	if (fl) return;
	if (x == 0)
	{
		fl = true;
		ans--;
		v[num] = true;
		return;
	}
	if (dep > n) return;
	int k = x / a[dep];
	if (num == dep || v[dep]) k = 0;
	for (int i = 0; i <= k; i++)
		if (x - a[dep] * i >= 0)
			dfs(dep + 1, x - a[dep] * i, num);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) a[i] = read(), v[i] = false;
		sort(a + 1, a + n + 1, cmp);
		ans = n;
		for (int i = 1; i <= n; i++)
		{
			fl = false;
			dfs(1, a[i], i);
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
