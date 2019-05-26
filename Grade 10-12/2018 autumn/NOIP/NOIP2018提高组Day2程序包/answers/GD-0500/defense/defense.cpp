#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define F(i, x, y) for (int i = x; i <= y; i++)
#define D(i, x, y) for (int i = x; i >= y; i--)

using namespace std;

const int N = 1e5 + 5, Inf = 1 << 30;
int n, m, ans;
int f[N][2], a[N];
char ch, ch1;
int lx, rx, uu, vv;
int to[N * 2], nxt[N * 2], lst[N * 2], tms;

void Link(int x, int y) { to[++tms] = y, nxt[tms] = lst[x], lst[x] = tms; }

void Dfs(int x, int fa)
{
	f[x][1] = a[x], f[x][0] = 0;
	if (x == lx) f[x][uu ^ 1] = Inf;
	if (x == rx) f[x][vv ^ 1] = Inf;
	for (int i = lst[x]; i; i = nxt[i])
	{
		int that = to[i];
		if (that == fa) continue;
		Dfs(that, x);
		int k = min(f[that][1], f[that][0]);
		f[x][1] += k, f[x][0] += f[that][1];
	}
//	printf("%d %d %d\n", x, f[x][1], f[x][0]);
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	scanf("%d %d ", &n, &m);
	scanf("%c%c", &ch, &ch1);
	F(i, 1, n) scanf("%d", &a[i]);
//	F(i, 1, n) printf("%d ", a[i]); printf("\n");
	int x, y;
	F(i, 1, n - 1) scanf("%d %d", &x, &y), Link(x, y), Link(y, x);
	F(i, 1, m)
	{
		scanf("%d %d %d %d", &lx, &uu, &rx, &vv);
		Dfs(1, 0);
		ans = min(f[1][0], f[1][1]);
		if (ans >= Inf) ans = -1;
		printf("%d\n", ans);
	}
	
	return 0;
}
