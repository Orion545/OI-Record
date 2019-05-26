#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

#define inf 0x3f3f3f3f
#define N 50005

using namespace std;

struct Node { int To, w, nxt; }e[N*2];
int f[N][2], ls[N], A[N], n, m, cnt, Answer;

bool vis[N], Check1 = 1, Check2 = 1;


void read(int &x)
{
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9')   { if (s == '-')   f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + (s - '0'); s = getchar(); }
	x = x * f;
}

void Addedge(int u, int v, int w)
{
	e[++cnt].To = v, e[cnt].w = w, e[cnt].nxt = ls[u], ls[u] = cnt;
    e[++cnt].To = u, e[cnt].w = w, e[cnt].nxt = ls[v], ls[v] = cnt;
}

void dfs(int x, int father)
{
	f[x][1] = 0;
	int cmax = 0, dmax = 0;
	for (int i = ls[x]; i; i = e[i].nxt)
	{
		if (e[i].To == father) continue;
	    int y = e[i].To; dfs(y, x);
	    f[x][0] = max(f[x][0], f[y][0]);
	    f[x][1] = max(f[x][1], f[y][1] + e[i].w);
	    if (f[y][1] + e[i].w >= cmax) dmax = cmax, cmax = f[y][1] + e[i].w;
	       else dmax = max(dmax, f[y][1] + e[i].w);
	}
	f[x][0] = max(f[x][0], cmax + dmax);
}

void work(int x, int num, int tot, int cmin)
{
	if (Answer >= cmin) return;
	if (x > m)
	{
		Answer = cmin;
		return;
	}
	if (tot <= 1)
	{
	   for (int i = 1; i < n; i++)
	       if (!vis[i])
	       {
		       vis[i] = 1;
			   work(x, num + A[i], tot + 1, cmin);
		       vis[i] = 0;
		   }
    }
	if (tot) work(x + 1, 0, 0, min(cmin, num));
}

void Find(int x, int now, int num, int tot, int cmin)
{
	if (Answer >= cmin) return;
	if (x > m)
	{
		Answer = cmin;
		return;
	}
	if (tot) Find(x + 1, now, 0, 0, min(cmin, num));
	if (now >= n) return;
	Find(x, now + 1, num + A[now], tot + 1, cmin);
    
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i < n; i++)
	{
		int u, v, w; read(u); read(v); read(w); Addedge(u, v, w);
	    if (u != 1) Check1 = 0; A[i] = w;
	    if (v != u + 1) Check2 = 0;
	}
	dfs(1, -1);
	if (m == 1) printf("%d\n", f[1][0]);
	   else if (Check1)
	   {
			work(1, 0, 0, inf);
			printf("%d\n", Answer);
	   }
	   else if (Check2)
	   {
	   	    Find(1, 1, 0, 0, inf);
	   	    printf("%d\n", Answer);
	   }
	return 0;
}
