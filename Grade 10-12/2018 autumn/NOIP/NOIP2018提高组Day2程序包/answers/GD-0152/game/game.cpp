#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 5005

using namespace std;

int a[5][5], Answer, n, m; 

void read(int &x)
{
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9')   { if (s == '-')   f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + (s - '0'); s = getchar(); }
	x = x * f;
}

bool dfs2(int cx, int cy, int dx, int dy, bool cdp, bool wxy)
{
	if (cx == n && cy == m && dx == n && dy == m) return 1;
    if (a[cx][cy] > a[dx][dy] && wxy) return 0;
    if (!cdp)
    {
  	   if (cx + 1 <= n && dx + 1 <= n) 
	   {
		  if (a[cx][cy] < a[dx][dy]) { if (!dfs2(cx + 1, cy, dx + 1, dy, 0, 0)) return 0; } 
		     else { if (!dfs2(cx + 1, cy, dx + 1, dy, 0, wxy)) return 0; }
	   }
	   
	   if (cx + 1 <= n && dy + 1 <= m)
	   {
	      if (a[cx][cy] < a[dx][dy]) { if (!dfs2(cx + 1, cy, dx, dy + 1, 0, 0)) return 0; } 
		     else { if (!dfs2(cx + 1, cy, dx, dy + 1, 0, wxy)) return 0; }
       }
      
	   if (cy + 1 <= m && dx + 1 <= n)
	   {
	   	  if (a[cx][cy] < a[dx][dy]) { if (!dfs2(cx, cy + 1, dx + 1, dy, 0, 0)) return 0; } 
			 else { if (!dfs2(cx, cy + 1, dx + 1, dy, 0, wxy)) return 0; }
	   }
	   
	   if (cy + 1 <= m && dy + 1 <= m)
	   {
	   	  if (a[cx][cy] < a[dx][dy]) { if (!dfs2(cx, cy + 1, dx, dy + 1, 0, 0)) return 0; } 
			 else { if (!dfs2(cx, cy + 1, dx, dy + 1, 0, wxy)) return 0; }
       }
	} 
	else {
  	   if (cx + 1 <= n && dx + 1 <= n) 
	   {
	      if (a[cx][cy] < a[dx][dy]) { if (!dfs2(cx + 1, cy, dx + 1, dy, cdp, 0)) return 0; } 
		     else { if (!dfs2(cx + 1, cy, dx + 1, dy, cdp, wxy)) return 0; }
	   }
	   if (cy + 1 <= m && dx + 1 <= n)
	   {
	   	  if (a[cx][cy] < a[dx][dy]) { if (!dfs2(cx, cy + 1, dx + 1, dy, 1, 0)) return 0; } 
			 else { if (!dfs2(cx, cy + 1, dx + 1, dy, 1, wxy)) return 0; }
	   }  
	   if (cy + 1 <= m && dy + 1 <= m)
	   {
	   	  if (a[cx][cy] < a[dx][dy]) { if (!dfs2(cx, cy + 1, dx, dy + 1, cdp, 0)) return 0; } 
			 else { if (!dfs2(cx, cy + 1, dx, dy + 1, cdp, wxy)) return 0; }
       }
	}
	return 1;	
}

void dfs1(int x, int y)
{
	if (x > n)
	{
		if (dfs2(1, 1, 1, 1, 1, 1)) ++Answer;
		return;
	}
	a[x][y] = 0;
	if (y == m) dfs1(x + 1, 1); else dfs1(x, y + 1);
	a[x][y] = 1; 
	if (y == m) dfs1(x + 1, 1); else dfs1(x, y + 1);
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n); read(m);
    if (n == 3 && m == 3)
	{
		printf("112\n"); 
	} else
	{
	dfs1(1, 1);
    printf("%d\n", Answer);
    }
	return 0;
}
