#include<bits/stdc++.h>
using namespace std;
const int N = 10007;
int n , m , cnt , road[N] , vis[N];
int mp[5007][5007];
inline int read ()
{
	int i = 0 , f = 1;
	char ch;
	for (ch = getchar (); ch < '0' || ch > '9'; ch = getchar ()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar ()) 
	i = (i << 3) + (i << 1) + ch - '0';
	return i * f; 
}
inline void init ()
{
	n = read (); m = read ();
	for (int i = 1 , x , y; i <= m; i++)
	{
		x = read (); y =read ();
		mp[x][y] = mp[y][x] = 1;
	}
}
inline void dfs (int x)
{
	vis[x] = 1;
	for (int i = 1; i <= n; i ++)
	{
		if (mp[x][i] && vis[i] != 1)
		{
			road[++cnt] = i;
			dfs (i);
		}
	}
}
inline void solve ()
{
	road[++cnt] = 1;
	dfs (1);
	for (int i = 1; i <= cnt; i++)
	{
		printf ("%d " , road[i]);
	}
	return;
}
int main ()
{
	freopen ("travel.in" , "r" , stdin);
	freopen ("travel.out" , "w" , stdout);
	init ();
	solve ();
	return 0;
}
