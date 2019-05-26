#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>

const int N = 5005;

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

struct Edge
{
	int to,next;
}e[N * 2],cir[N * 2];

int n,m;

int next[N],head[N],tot,cnt;
bool vis[N];

int ans[N];
int tmp[N],num[N];
bool isCir[N];

void add(int x,int y)
{
	e[++cnt].next = next[x], e[cnt].to = y, next[x] = cnt;
	e[++cnt].next = next[y], e[cnt].to = x, next[y] = cnt;
}

void ADD(int x,int y)
{
	cir[++tot].next = next[x], next[x] = tot, cir[tot].to = y;
	cir[++tot].next = next[y], next[y] = tot, cir[tot].to = x;
}

int fa[N];

bool findC(int x,int s)
{
	vis[x] = 1;
	for (int i = next[x]; i; i = e[i].next)
	{
		if (e[i].to == s && fa[x] != s)
			return 1;
		if (vis[e[i].to])
			continue;
		if (findC(e[i].to, s))
		{
			isCir[e[i].to] = 1;
			num[++num[0]] = e[i].to;
		}
	}
	return 0;
}

bool vis1[N];

void dfs1(int x)
{
	vis[x] = 1;
	vis1[x] = 1;
	for (int i = next[x]; i; i = e[i].next)
	{
		if (!vis1[e[i].to])
		{
			for (int i = 1; i <= n; i++)
				vis[i] = vis1[i];
			fa[e[i].to] = x;
			if (findC(e[i].to, x))
				return;
			dfs1(e[i].to);
		}
	}
}

void dfs2(int x,int a)
{
	ans[++ans[0]] = x;
	vis[x] = 1;
	tmp[0] = 0;
	for (int i = next[x]; i; i = e[i].next)
	{
		if (vis[e[i].to])
			continue;
		else tmp[++tmp[0]] = e[i].to;
	}
	std::sort(tmp + 1, tmp + tmp[0] + 1);
	std::queue<int> Q;
	for (int i = 1; i <= tmp[0]; i++)
		Q.push(tmp[i]);

	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		dfs2(u,a);
	}
}

void dfsC(int x,int mn)
{
	if (num[x] > mn)
	{
		for (int i = x; i <= num[0]; i++)
			isCir[num[i]] = 0;
		return;
	}
	if (x > num[0])
		return;
	vis[num[x]] = 1;
	int now = N;
	for (int i = next[num[x]]; i; i = e[i].next)
	{
		if (vis[x] || isCir[x])
			continue;
		now = std::min(now, e[i].to);
	}
	ans[++ans[0]] = num[x];
	dfsC(x + 1, now);
	for (int i = next[num[x]]; i; i = e[i].next)
	{
		if (vis[x] || isCir[x])
			continue;
		dfs2(e[i].to, -1);
	}
}

void dfs(int x,int a)
{
	if (isCir[x])
		return;
	ans[++ans[0]] = x;
	vis[x] = 1;
	bool f = 0;
	int mn = N;
	tmp[0] = 0;
	for (int i = next[x]; i; i = e[i].next)
	{
		if (vis[e[i].to])
			continue;
		if (isCir[e[i].to])
			f = 1;
		else tmp[++tmp[0]] = e[i].to;
	}
	std::sort(tmp + 1, tmp + tmp[0] + 1);
	std::queue<int> Q;
	for (int i = 1; i <= tmp[0]; i++)
		Q.push(tmp[i]);
	int pos = 1;
	mn = std::min(num[1],num[num[0]]);
	int mx = std::max(num[1],num[num[0]]);
	if (f)
	{
		while (Q.front() < mn)
		{
			int u = Q.front();
			Q.pop();
			dfs(u, a);
		}
		dfsC(1, Q.front());
	}
	int u;
	while (!Q.empty())
	{
		u = Q.front();Q.pop();
		if (f && num[num[0]] < u)
		{
			dfs(num[num[0]], a);
		}
		dfs(u,a);
	}
	if (num[num[0]] > u)
		dfs(u,a);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		int u = read(), v = read();
		add(u,v);
	}
	dfs1(1);
	if (num[1] > num[num[0]])
	{
		for (int i = 1; i <= num[0] / 2; i++)
			std::swap(num[i], num[num[0] - i + 1]);
	}
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	dfs(1,-1);
	for (int i = 1; i <= n; i++)
		printf("%d ",ans[i]);
}
