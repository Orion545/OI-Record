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


vector<int> cir;


bool vis[N];
bool bo[N];

int p[N];
int dep[N];


void dfs(int x, int fa, int depth)
{
	dep[x] = depth;
	bo[x] = 1;
	vis[x] = 1;
	for (int i = head[x]; ~i; i = nxt[i])
	{
		edge & e = edges[i];
		if (e.to == fa) continue;
		if (bo[e.to])
		{
			int u = x, v = e.to;
			cir.push_back(i);
			while (u != v)
			{
				if (dep[u] < dep[v]) swap(u, v);
				cir.push_back(p[u]);
				u = edges[p[u]].from;
			}
		}
		else if (!vis[e.to])
		{
			p[e.to] = i;
			dfs(e.to, x, depth + 1);
		}
	}
	bo[x] = 0;
}


struct Data
{
	vector<int> vec;

	Data() { }

	void Add(int x) { vec.push_back(x); }
	
	void init() { vec.clear(); }

	bool operator < (const Data & rhs) const
	{
		for (int i = 0; i < min(vec.size(), rhs.vec.size()); i++)
			if (vec[i] < rhs.vec[i])
				return 1;
			else if (vec[i] > rhs.vec[i])
				return 0;
		return 0;
	}
};


Data Ans;
Data now;


bool tag[M];

vector<int> son[N];


void Get(int x)
{
	now.Add(x);
	vis[x] = 1;
	
	son[x].clear();
	for (int i = head[x]; ~i; i = nxt[i])
	{
		edge & e = edges[i];
		if (!tag[i] && !vis[e.to])
			son[x].push_back(e.to);
	}
	
	sort(son[x].begin(), son[x].end());
	
	for (int i = 0; i < son[x].size(); i++)
		Get(son[x][i]);
}


int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	init();
	
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		add_edge(x, y);
	}
	
	if (m == n-1)
	{
		Get(1);
		for (int i = 0; i < now.vec.size(); i++)
			printf("%d ", now.vec[i]);
		return 0;
	} 
	
	dfs(1, 0, 1);
	
	for (int i = 0; i < cir.size(); i++)
	{
		tag[cir[i]] = 1;
		tag[cir[i]^1] = 1;
		
		memset(vis, 0, sizeof(vis));
		
		now.init();
		
		Get(1);
		if (!Ans.vec.size() || now < Ans)
			Ans = now;
		
		tag[cir[i]] = 0;
		tag[cir[i]^1] = 0;
	}
	
	for (int i = 0; i < Ans.vec.size(); i++)
		printf("%d ", Ans.vec[i]);
	
	return 0;
}
