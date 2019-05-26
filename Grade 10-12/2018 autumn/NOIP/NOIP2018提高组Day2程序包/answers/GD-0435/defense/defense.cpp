#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>


using namespace std;


const int N = 10010, M = 20010;

typedef long long LL;


struct edge
{
	int from, to;
	edge() { }
	edge(int a, int b) : from(a), to(b) { }
} edges[M];

int head[N], nxt[M], tot;

inline void init()
{
	memset(head, -1, sizeof(head));
	tot = 0;
}

inline void add_edge(int x, int y)
{
	edges[tot] = edge(x, y);
	nxt[tot] = head[x];
	head[x] = tot++;
	edges[tot] = edge(y, x);
	nxt[tot] = head[y];
	head[y] = tot++;
}


LL p[N];


namespace Solve1
{
	LL f[N][2];
	
	bool typ[N][2];
	
	void dfs(int x, int fa)
	{
		f[x][0] = 0;
		f[x][1] = p[x];
		
		bool flag1 = 0;
		bool flag2 = 0;
		
		bool bo = 0;
		
		int son = 0;
		
		for (int i = head[x]; ~i; i = nxt[i])
		{
			edge & e = edges[i];
			if (e.to != fa)
			{
				son++;
				
				dfs(e.to, x);
				
				if (typ[x][1] && typ[e.to][1])
				{
					bo = 1;
					break;
				}
				
				if (typ[e.to][1])
					flag1 = 1;
				else if (!typ[e.to][1])
					f[x][0] += f[e.to][1];
				
				if (!typ[e.to][0] && typ[e.to][1])
					f[x][1] += f[e.to][0];
				else if (typ[e.to][0] && !typ[e.to][1])
					f[x][1] += f[e.to][1];
				else if (!typ[e.to][0] && !typ[e.to][1])
					f[x][1] += min(f[e.to][1], f[e.to][0]);
				else if (typ[e.to][0] && typ[e.to][1])
					bo = 1;
			}
		}
		
		if (son == 0) return;
		
		if (flag1)
			typ[x][0] = 1, f[x][0] = 0;
		
		if (bo)
			typ[x][0] = 1, typ[x][1] = 1, f[x][0] = f[x][1] = 0;
	}

	void query(int a, int x, int b, int y)
	{
		typ[a][!x] = 1;
		typ[b][!y] = 1;
		
		dfs(1, 0);
		
		if (!typ[1][0] && !typ[1][1])
			printf("%lld\n", min(f[1][0], f[1][1]));
		else if (!typ[1][0] && typ[1][1])
			printf("%lld\n", f[1][0]);
		else if (typ[1][0] && !typ[1][1])
			printf("%lld\n", f[1][1]);
		else 
			puts("-1");
		
		typ[a][!x] = 0;
		typ[b][!y] = 0;
	}
}


int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	int n, m;
	char opt[5];
	
	scanf("%d %d %s", &n, &m, &opt);
	
	init();
	bool typ1 = 0;
	
	for (int i = 1; i <= n; i++)
		scanf("%lld", &p[i]);
	
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		add_edge(x, y);
	}
	
	for (int i = 1; i <= m; i++)
	{
		int a, x, b, y;
		scanf("%d %d %d %d", &a, &x, &b, &y);
		Solve1::query(a, x, b, y);
	}
	
	return 0;
}
