#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define F(i, x, y) for (int i = x; i <= y; i++)
#define D(i, x, y) for (int i = x; i >= y; i--)

using namespace std;

const int N = (1e5 + 5), Inf = (1 << 30);

struct edge { int x, y, v; } e[N];

bool cmp(edge a, edge b) { return a.v > b.v; }
bool cmp1(edge a, edge b) { return a.x < b.x; }

int to[N * 2], nxt[N * 2], lst[N], val[N * 2], tms;
int n, m, ans, sum = 0;

void Link(int x, int y, int v)
{ to[++tms] = y, nxt[tms] = lst[x], lst[x] = tms, val[tms] = v; }

int dep[N], son[N];

int Dfs(int x, int fa)
{
	son[x] = x;
	for (int i = lst[x]; i; i = nxt[i])
	{
		int that = to[i];
		if (that == fa) continue;
		dep[that] = dep[x] + val[i];
		int p = Dfs(that, x);
		if (dep[p] > dep[son[x]]) son[x] = p;
	}
	return son[x];
}

void work1()
{
	int rt1 = Dfs(1, 0);
	memset(dep, 0, sizeof(dep));
	memset(son, 0, sizeof(son));
	int rt2 = Dfs(rt1, 0);
	printf("%d\n", dep[rt2]);
}

int d[N], c[N];
void work2()
{
	sort(e + 1, e + n, cmp);
	ans = Inf;
	if (n > m * 2)
	{
		int k = m * 2;
		F(i, 1, k) d[i] = e[i].v;
		F(i, 1, k) ans = min(ans, d[i] + d[k - i + 1]);
		printf("%d\n", ans);
	}
	else
	{
		int k = m * 2 - n + 1, u = n - 1 - k;
		F(i, 1, k) d[i] = e[i].v;
		F(i, k + 1, n - 1) c[i - k] = e[i].v;
		F(i, 1, k) ans = min(ans, d[i]);
		F(i, 1, u) ans = min(ans, c[i] + c[u - i + 1]);
		printf("%d\n", ans);
	}
}

bool judge(int x)
{
	int t = 0, s = 0;
	F(i, 1, n - 1)
	{
		s += e[i].v;
		if (s >= x) t++, s = 0;
	}
	return t >= m;
}

void work3()
{
	int l, r;
	l = r = ans = 0;
	sort(e + 1, e + n, cmp1);
	F(i, 1, n - 1) r += e[i].v;
	for (int mid = l + r >> 1; l <= r; mid = l + r >> 1)
	{
		if (judge(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	int tag1 = (1), tag2 = (1);
	scanf("%d %d", &n, &m);
	F(i, 1, n - 1)
	{
		scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v);
		if (e[i].x > e[i].y) swap(e[i].x, e[i].y);
		tag1 &= (e[i].x == 1);
		tag2 &= (e[i].y == (e[i].x + 1));
		sum += e[i].v;
		Link(e[i].x, e[i].y, e[i].v);
		Link(e[i].y, e[i].x, e[i].v);
	}
	if (m == 1) { work1(); return 0; }
	if (tag1) { work2(); return 0; }
	if (tag2) { work3(); return 0; }
	printf("%d\n", sum / m);
	
	return 0;
}
