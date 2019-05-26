#include<bits/stdc++.h>
using namespace std;
const int N = 300007;
int n , m , cnt , now , son , sum , tot , ans , minn , vis[N] , p[N] , q[N][3] , qt[N][3] , h[N];
string a;
struct bian 
{
	int to , nxt;
} bn[N * 2];
inline void ins (int x , int y)
{
	bn[++cnt].to = y;
	bn[cnt].nxt = h[x];
	h[x] = cnt;
}
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
	n = read (); m = read (); cin >> a;
	for (int i = 1; i <= n; i++) p[i] = read ();
	for (int i = 1 , x , y; i <= n - 1; i++)
	{
		x = read (); y = read ();
		ins (x , y); ins (y , x);
	}
	for (int i = 1 , x , y , a , b; i <= m; i++)
	{
			q[i][1] = read ();
			qt[i][1] = read ();
			q[i][2] = read ();
			qt[i][2] = read ();
	}
}
inline void dfs (int x , int a)
{
	vis[x] = 1;
	if (tot == n) 
	{
		if (ans < minn) minn = ans;
		tot = sum;
	}
	if (a == 0)
	{
		for (int i = h[x]; i; i = bn[i].nxt)
		{
			son = bn[i].to;
			if (vis[son] == 1) continue;
			if ((son == q[now][1] && qt[now][1] == 0) || (son == q[now][2] && qt[now][2] == 0)) return;
			sum ++;
			tot ++;
			ans += p[son];
			dfs (son , 1);
			sum --;
			ans -= p[son];
		}
	}
	else 
	{
		for (int i = h[x]; i; i = bn[i].nxt)
		{
			son = bn[i].to;
			if (vis[son] == 1) continue;
			if (son == q[now][1])
			{
				sum ++;
				tot ++;
				if (qt[now][1] == 1) ans += p[son];
				dfs (son , qt[now][1]);
				sum --;
				if (qt[now][1] == 1) ans += p[son];
			}
			else if (son == q[now][2])
			{
				sum ++;
				tot ++;
				if (qt[now][2] == 1) ans += p[son];
				dfs (son , qt[now][2]);
				sum --;
				if (qt[now][2] == 1) ans -= p[son];
			}
			else 
			{
				sum ++;
				tot ++;
				dfs (son , 0);
				sum --;
				sum ++;
				tot ++;
				ans += p[son];
				dfs (son , 1);
				sum --;
				ans -= p[son];
			}
		}
	}
	vis[x] = 0;
}
inline void solve ()
{
	for (int i = 1; i <= m; i++)
	{
		minn = 1e9;
		now = i;
		int flag = 0;
		if (qt[i][1] == 0 && qt[i][2] == 0)
		{
			for (int i = h[q[i][1]]; i; i = bn[i].nxt)
			{
				int son = bn[i].to;
				if (son == q[i][2]) 
				{
					flag = 1;
					printf ("-1\n");
					break;
				}
			}
		}
		if (flag == 1) continue;
		if (1 == q[i][1])
		{
			sum ++;
			if (qt[i][1] == 1) ans += p[1];
			dfs (q[i][1] , qt[i][1]);
			sum --;
			if (qt[i][1] == 1) ans -= p[1];
			continue;
		}
		if (1 == q[i][2])
		{
			sum ++;
			if (qt[i][2] == 1) ans += p[1];
			dfs (q[i][2] , qt[i][2]);
			sum --;
			if (qt[i][2] == 1) ans -= p[1];
			continue;
		}
		sum ++;
		dfs (1 , 0);
		sum --;
		sum ++;
		ans += p[1];
		dfs (1 , 1);
		sum --;
		ans -= p[1];
		printf ("%d\n" , minn);
	}
}
int main ()
{
	freopen ("defense.in" , "r" , stdin);
	freopen ("defense.out" , "w" , stdout);
	init ();
	solve ();
	return 0;
}
