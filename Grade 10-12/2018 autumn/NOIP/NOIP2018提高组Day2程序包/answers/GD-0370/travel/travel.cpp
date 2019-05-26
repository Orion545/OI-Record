// travel.cpp
// NOIP2018 2018.11.11
// GD-0370 HurryPeng

#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Edge
{
	int to;
	bool exist;
	
	bool operator<(const Edge & e) const
	{
		return to < e.to;
	}
};

bool compare(Edge * a, Edge * b)
{
	return *a < *b;
}

struct Vertex
{
	int id;
	list<Edge *> edge;
	bool visited;
};

int N = 0, M = 0;
Vertex G[5001];
Edge E[5001][2];
vector<int> Seq;
vector<int> SeqCur;

void dfs(int id)
{
	Vertex & cur = G[id];
	cur.visited = true;
	SeqCur.push_back(cur.id);
	for (list<Edge *>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
	{
		Edge & edge = **it;
		Vertex & nex = G[edge.to];
		if (!edge.exist) continue;
		if (nex.visited) continue;
		dfs(nex.id);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		Seq.push_back(N);
	}
	for (int i = 1; i <= N; i++)
	{
		G[i].id = i;
		G[i].visited = false;
	}
	for (int i = 1; i <= M; i++)
	{
		int u = 0, v = 0;
		cin >> u >> v;
		E[i][0] = (Edge){v, true};
		G[u].edge.push_back(&E[i][0]);
		E[i][1] = (Edge){u, true};
		G[v].edge.push_back(&E[i][1]);
	}
	for (int i = 1; i <= N; i++)
	{
		G[i].edge.sort(compare);
	}
	
	if (M == N - 1) // tree
	{
		for (int i = 1; i <= N; i++) G[i].visited = false;
		dfs(1);
		Seq = SeqCur;
	}
	else // tree + 1 loop
	{
		for (int i = 1; i <= M; i++) // try deleting each edge
		{
			for (int j = 1; j <= N; j++) G[j].visited = false;
			SeqCur.clear();
			E[i][0].exist = E[i][1].exist = false;
			dfs(1);
			E[i][0].exist = E[i][1].exist = true;
			if (Seq.size() != SeqCur.size()) continue;
			
			for (int p = 0; p < N; p++)
			{
				if (SeqCur[p] == Seq[p]) continue;
				if (SeqCur[p] < Seq[p])
				{
					Seq = SeqCur;
					break;
				}
				if (SeqCur[p] > Seq[p]) break;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << Seq[i] << ' ';
	}
	
	return 0;
}

