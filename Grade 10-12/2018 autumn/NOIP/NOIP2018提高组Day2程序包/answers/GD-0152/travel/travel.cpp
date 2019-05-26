#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 5005

using namespace std;

struct Node { int u, v, nxt; }e[N*2];
int Answer[N], Ru[N], A[N], ls[N], kop[N], n, m, cnt, tot, root;
bool vis[N], wxylove = 1;

void read(int &x)
{
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9')   { if (s == '-')   f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + (s - '0'); s = getchar(); }
	x = x * f;
}

bool cmp(Node aa, Node bb)
{
    return aa.v > bb.v;	
}

void dfs(int x, int father)
{
	printf("%d ", x);
    for (int i = ls[x]; i; i = e[i].nxt)
	{
		if (e[i].v == father) continue;
		dfs(e[i].v, x);
	}	
}

void work(int x, int father, int cdp)
{
	if (vis[x]) return;
	vis[x] = 1;
	A[++tot] = x;
	if (tot == n)
	{ 
	    bool reds = 1;
	    for (int i = 1; i <= n; i++) 
		{
		    if (Answer[i] > A[i]) { reds = 0; break; } 
		    if (Answer[i] < A[i]) break;
		}
		if (!reds) for (int i = 1; i <= n; i++) Answer[i] = A[i];
	    return;
	}
	for (int i = ls[x]; i; i = e[i].nxt)
	    {	
	       if (e[i].u == e[cdp].u && e[i].v == e[cdp].v) continue;
	       if (e[i].u == e[cdp].v && e[i].v == e[cdp].u) continue;
		   if (e[i].v == father) continue;
		   work(e[i].v, x, cdp);
	    }	
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= m; i++) 
	{
	    ++cnt; read(e[cnt].u); read(e[cnt].v); 
	    ++cnt; e[cnt].u = e[cnt - 1].v; e[cnt].v = e[cnt - 1].u;
	}
	sort(e + 1, e + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
    {
		 e[i].nxt = ls[e[i].u], ls[e[i].u] = i;
	     ++Ru[e[i].u]; ++Ru[e[i].v];
	}	 	 
	if (m == n - 1)
	{
		dfs(1, -1);
	} else 
	{    
		for (int i = 1; i <= n; i++) Answer[i] = n + 1;
		for (int i = 1; i <= cnt; i++) 
		{
			for (int j = 1; j <= n; j++) vis[j] = 0;
			
			if (Ru[e[i].u] - 2 > 0 && Ru[e[i].v] - 2 > 0)
			{
			    tot = 0; work(1, -1, i);
		    }
		}
		for (int i = 1; i <= n; i++) printf("%d ", Answer[i]);
	}
	return 0;
}
