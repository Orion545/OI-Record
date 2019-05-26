#include <algorithm>
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

const int N = 30005;

int n,m;

struct Edge
{
	int to,next,dis;
}e[N * 2];

int next[N],cnt;

void add(int x,int y,int z)
{
	e[++cnt].next = next[x];
	e[cnt].to = y;
	e[cnt].dis = z;
	next[x] = cnt;

	e[++cnt].next = next[y];
	e[cnt].to = x;
	e[cnt].dis = z;
	next[y] = cnt;
}

int ans, d;

bool vis[N];

void dfs(int x,int ansNow)
{
	vis[x] = 1;
	if (ansNow > ans)
		ans = ansNow, d = x;
	for (int i = next[x]; i; i = e[i].next)
	{
		if (!vis[e[i].to])
			dfs(e[i].to, ansNow + e[i].dis);
	}
}

void findD()
{
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read(), z = read();
		add(x,y,z);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	dfs(d, 0);
	printf("%d\n",ans);
}

int val[N];

bool check(int need)
{
	int tmp = n;
	while (val[n] >= need)
		n--;
	if (tmp - n >= m)
	{
		n = tmp;
		return 1;
	}
	int p = 1;
	for (int i = n; i >= 1; i--)
	{
		while (val[i] + val[p] < need)
			p++;
		if (p >= i)
		{
			n = tmp;
			return 0;
		}
		p++;
		if (tmp - i + 1 == m)
		{
			n = tmp;
			return 1;
		}
	}
	n = tmp;
	return 1;
}

void ass()
{
	n--;
	std::sort(val + 1, val + n + 1);
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx += val[i];
	int l = 1, r = mx;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", l - 1);
}

void dfs1(int x)
{
	vis[x] = 1;
	for (int i = next[x]; i; i = e[i].next)
	{
		if (!vis[e[i].to])
		{
			val[++val[0]] = e[i].dis;
			dfs1(e[i].to);
		}
	}
}

bool check1(int need)
{
	int now = 0, p = 0;
	for (int i = 1; i <= val[0]; i++)
	{
		now += val[i];
		if (now >= need)
		{
			now = 0;
			p++;
		}
	}
	if (p >= m)
		return true;
	else return false;
}

void half()
{
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	dfs1(d);
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx += val[i];
	int l = 1, r = mx;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check1(mid))
			l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", l - 1);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n = read(), m = read();
	if (m == 1)
	{
		findD();
		return 0;
	}
	bool f = 0;
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read(), z = read();
		val[i] = z;
		add(x,y,z);
		if (y != x + 1)
			f = 1;
	}
	if (f)
		ass();
	else
		half();
}
