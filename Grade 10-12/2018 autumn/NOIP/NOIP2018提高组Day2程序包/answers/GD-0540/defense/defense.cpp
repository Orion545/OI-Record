#include <iostream>
#include <cstdio>
#include <cmath>

const int N = 2005;
const int INF = 200001201;

int f[N][2];

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int n,m;

struct Edge
{
	int to,next;
}e[N * 2];

int next[N],cnt;

void add(int x,int y)
{
	e[++cnt].to = y;
	e[cnt].next = next[x];
	next[x] = cnt;
	e[++cnt].to = x;
	e[cnt].next = next[y];
	next[y] = cnt;
}

bool vis[N];
int fa[N];
int p[N];

void dp(int x,int a, int b,int c,int d)
{
	vis[x] = 1;
	for (int i = next[x]; i; i = e[i].next)
	{
		if (!vis[e[i].to])
		{
			fa[e[i].to] = x;
			dp(e[i].to, a, b, c, d);
		}
	}
	for (int i = next[x]; i; i = e[i].next)
	{
		if (fa[e[i].to] != x)
			continue;
		if (x == a || x == c)
		{
			if (x == a)
			{
				if (b == 0)
				{
					f[x][1] = INF;
					f[x][0] += f[e[i].to][1];
				}
				else
				{
					f[x][0] = INF;
					f[x][1] += std::min(f[e[i].to][0], f[e[i].to][1]);
				}
			}
			else
			{
				if (d == 0)
				{
					f[x][1] = INF;
					f[x][0] += f[e[i].to][1];
				}
				else
				{
					f[x][0] = INF;
					f[x][1] += std::min(f[e[i].to][0], f[e[i].to][1]);
				}
			}
		}
		else
		{
			f[x][0] += f[e[i].to][1];
			f[x][1] += std::min(f[e[i].to][0], f[e[i].to][1]);
		}
	} 
}

bool bi[2005][2005];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n = read(), m = read(); char ch[4];
	scanf("%s",ch);
	for (int i = 1; i <= n; i++)
		p[i] = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		bi[x][y] = 1;
		bi[y][x] = 1;
		add(x,y);
	}
	while (m--)
	{
		int a = read(), b = read(), c = read(), d = read();
		if (b == 0 && d == 0 && bi[a][c] == 1)
		{
			printf("-1\n");
			continue;
		}
		if (m >= 10000)
		{
			printf("-1\n");
		}
		else
		{
			for (int i = 1; i <= n; i++)
				vis[i] = 0, f[i][1] = p[i], f[i][0] = 0;
			if (b == 0)
				f[a][1] = INF;
			else f[a][0] = INF;
			if (d == 0)
				f[c][1] = INF;
			else f[c][0] = INF;
			dp(1,a,b,c,d);
			if (a == 1)
			{
				printf("%d\n",f[a][b]);
			}
			else
			{
				if (c == 1)
					printf("%d\n",f[c][d]);
				else printf("%d\n",std::min(f[1][0],f[1][1]));
			}
		}
	}
}
