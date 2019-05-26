#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 100005
 
using namespace std;

struct Node { int u, To, nxt; }e[N*2];
int a[105][105], ls[N], A[N], n, m, cnt, Answer;
bool vis[N];
char s[5];

void read(int &x)
{
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9')   { if (s == '-')   f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + (s - '0'); s = getchar(); }
	x = x * f;
}

void Addedge(int u, int v)
{
    e[++cnt].To = v, e[cnt].u = u, e[cnt].nxt = ls[u], ls[u] = cnt;
	e[++cnt].To = u, e[cnt].u = v, e[cnt].nxt = ls[v], ls[v] = cnt;	
}

void dfs(int now, int tot, int num)
{
	if (num >= Answer) return;
	if (tot == cnt)
	{
		Answer = num;
		return;
	}
	for (int i = now + 1; i <= n; i++)
	    if (!vis[i])
		{
		   int rp = 0;
		   for (int j = ls[i]; j; j = e[j].nxt) 
		        ++a[i][e[j].To], ++a[e[j].To][i];
		   
		   for (int j = 1; j <= cnt; j++) 
		       if (a[e[j].u][e[j].To]) rp++;    
		   
		   dfs(i, rp, num + A[i]);
		   
	       for (int j = ls[i]; j; j = e[j].nxt) 
	            --a[i][e[j].To], --a[e[j].To][i];
	}
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	read(n); read(m); scanf("%s", s);
	for (int i = 1; i <= n; i++) read(A[i]);
	for (int i = 1; i < n; i++)
	{
		int u, v; read(u); read(v); Addedge(u, v);
	}
	for (int i = 1; i <= m; i++)
	{
		int sa, ed, sb, sd;
		read(sa); read(ed); read(sb); read(sd);
		for (int i = 1; i <= n; i++)
		    for (int j = 1; j <= n; j++) a[i][j] = 0;
		int gdp = 0;
		if (!ed) vis[sa] = 1;
		else 
		{
			gdp += A[sa];
			vis[sa] = 1;
			for (int j = ls[sa]; j; j = e[j].nxt)
			    ++a[sa][e[j].To], ++a[e[j].To][sa];
		} 
		if (!sd) vis[sb] = 1;
		else 
		{
			gdp += A[sb];
			vis[sb] = 1;
			for (int j = ls[sb]; j; j = e[j].nxt)
			    ++a[sb][e[j].To], ++a[e[j].To][sb];
		}
		int cdp = 0;
		for (int i = 1; i <= cnt; i++) if (a[e[i].u][e[i].To]) cdp++;
		
		Answer = 0x3f3f3f3f;
		dfs(0, cdp, gdp);
		if (Answer == 0x3f3f3f3f) printf("-1\n"); else printf("%d\n", Answer);
		vis[sa] = 0; vis[sb] = 0;
	}
	return 0;
}
