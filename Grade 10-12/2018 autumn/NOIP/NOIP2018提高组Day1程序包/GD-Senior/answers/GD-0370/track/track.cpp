// track.cpp
// NOIP2018 2018.11.10
// GD-0370 HurryPeng

#include <stdio.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
	int x, y;
	int l;
	
	bool used;
};

struct Vertex
{
	int id;
	list<Edge *> edge;
	int degree;
	
	bool visited;
	int dist;
	
	int to(const Edge & e)
	{
		if (id == e.x) return e.y;
		else return e.x;
	}
	
	bool operator<(const Vertex & v) const
	{
		return dist < v.dist;
	}
};

Vertex G[500001];
Edge E[500001];

int N = 0, M = 0, MinL = 0;

bool dfs(int routeFound, int curId, int curL)
{
	if (routeFound == M) return true;
	
	if (curL >= MinL) return dfs(routeFound + 1, 0, 0);
	
	if (curId == 0) // find a new start
	{
		for (int s = 1; s <= N; s++)
		{
			if (G[s].degree != 1) continue;
			if (dfs(routeFound, s, 0)) return true;
		}
		return false;
	}
	
	Vertex & cur = G[curId];
	for (list<Edge *>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
	{
		Edge & edge = *(*it);
		if (edge.used) continue;
		Vertex & nex = G[cur.to(edge)];
		edge.used = true;
		cur.degree--;
		nex.degree--;
		bool flag = dfs(routeFound, nex.id, curL + edge.l);
		edge.used = false;
		cur.degree++;
		nex.degree++;
		if(flag) return true;
	}
	
	return false;
}

bool dfsLinear(int routeFound, int curId, int curL)
{
	if (routeFound == M) return true;
	
	if (curL >= MinL) return dfsLinear(routeFound + 1, curId, 0);
	
	if (curId == N) return false;
	
	Vertex & cur = G[curId];
	for (list<Edge *>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
	{
		Edge & edge = *(*it);
		if (edge.used) continue;
		Vertex & nex = G[cur.to(edge)];
		edge.used = true;
		cur.degree--;
		nex.degree--;
		bool flag = dfs(routeFound, nex.id, curL + edge.l);
		edge.used = false;
		cur.degree++;
		nex.degree++;
		if(flag) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	cin >> N >> M;
	
	bool linear = true;
	
	for (register int i = 1; i <= N; i++)
	{
		G[i].id = i;
		G[i].degree = 0;
		G[i].visited = false;
		G[i].dist = 0;
	}
	int sumL = 0;
	for (register int i = 1; i <= N - 1; i++)
	{
		int a = 0, b = 0, l = 0;
		cin >> a >> b >> l;
		if (b != a + 1) linear = false;
		sumL += l;
		E[i] = (Edge) {a, b, l, false};
		G[a].edge.push_back(E + i);
		G[a].degree++;
		G[b].edge.push_back(E + i);
		G[b].degree++;
	}
	
	if (M == 1) // diametre of tree
	{
		queue<int> bfs;
		bfs.push(1);
		while (!bfs.empty())
		{
			Vertex & cur = G[bfs.front()];
			bfs.pop();
			cur.visited = true;
			for (list<Edge *>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
			{
				Edge & edge = *(*it);
				Vertex & nex = G[cur.to(edge)];
				if (nex.visited) continue;
				nex.dist = cur.dist + edge.l;
				bfs.push(nex.id);
			}
		}
		Vertex & p = *max_element(G + 1, G + N + 1);
		
		for (register int i = 1; i <= N; i++)
		{
			G[i].visited = false;
			G[i].dist = 0;
		}
		bfs.push(p.id);
		while (!bfs.empty())
		{
			Vertex & cur = G[bfs.front()];
			bfs.pop();
			cur.visited = true;
			for (list<Edge *>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
			{
				Edge & edge = *(*it);
				Vertex & nex = G[cur.to(edge)];
				if (nex.visited) continue;
				nex.dist = cur.dist + edge.l;
				bfs.push(nex.id);
			}
		}
		Vertex & q = *max_element(G + 1, G + N + 1);
		
		cout << q.dist;
		
		return 0;
	}
	
	if (linear)
	{
		int lo = 1, hi = sumL + 1;
		while (hi != lo + 1)
		{
			MinL = (lo + hi) / 2;
			if (dfsLinear(0, 1, 0)) lo = MinL;
			else hi = MinL;
		}
		
		cout << lo;
		
		return 0;
	}
	
	int lo = 1, hi = sumL + 1;
	while (hi != lo + 1)
	{
		MinL = (lo + hi) / 2;
		if (dfs(0, 0, 0)) lo = MinL;
		else hi = MinL;
	}
	
	cout << lo;
	
	return 0;
}

