// defense.cpp
// NOIP2018 2018.11.11
// GD-0370 HurryPeng

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <list>
#include <algorithm>

using namespace std;

const long long int InfLL = LONG_LONG_MAX / 2;

struct Vertex
{
	int id;
	int cost;
	list<int> edge;
	bool visited;
	bool troop;
};

int N = 0, M = 0;
Vertex G[100001];
int A = 0, X = 0, B = 0, Y = 0;
long long int CurCost = 0;
long long int MinCost = InfLL;

long long int Dp[100001][2];

bool dfs(int id, bool preTroop, long long int cost)
{
	if (id == N + 1)
	{
		MinCost = min(MinCost, cost);
		return true;
	}
	
	if (Dp[id][preTroop] != -1)
	{
		if (Dp[id][preTroop] != -2) return true;
		return false;
	}
	
	Vertex & cur = G[id];
	cur.visited = true;
	if (cur.id == A || cur.id == B)
	{
		if ((cur.id == A && X == 1) || (cur.id == B && Y == 1)) // must troop
		{
			for (list<int>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
			{
				Vertex & nex = G[*it];
				if (nex.visited) continue;
				if (!dfs(nex.id, true, cost + cur.cost))
				{
					Dp[id][preTroop] = -2;
					return false;
				}
			}
			Dp[id][preTroop] = cost;
			return true;
		}
		else // must not troop
		{
			if (!preTroop) return false;
			for (list<int>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
			{
				Vertex & nex = G[*it];
				if (nex.visited) continue;
				if (!dfs(nex.id, false, cost))
				{
					Dp[id][preTroop] = -2;
					return false;
				}
			}
			Dp[id][preTroop] = cost;
			return true;
		}
	}
	
	// no limit
	bool flag = false;
	for (list<int>::iterator it = cur.edge.begin(); it != cur.edge.end(); it++)
	{
		Vertex & nex = G[*it];
		if (nex.visited) continue;
		if (dfs(nex.id, true, cost + cur.cost)) flag = true;
		if (dfs(nex.id, false, cost)) flag = true;
	}
	if (flag)
	{
		Dp[id][preTroop] = cost;
		return true;
	}
	Dp[id][preTroop] = -2;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	char hint = '\0';
	int type = 0;
	cin >> N >> M >> hint >> type;
	for (int i = 1; i <= N; i++)
	{
		G[i].id = i;
		G[i].visited = false;
		G[i].troop = false;
		cin >> G[i].cost;
	}
	for (int i = 1; i <= N - 1; i++)
	{
		int u = 0, v = 0;
		cin >> u >> v;
		G[u].edge.push_back(v);
		G[v].edge.push_back(u);
	}
	
	while (M--)
	{
		cin >> A >> X >> B >> Y;
		for (int i = 1; i <= N; i++)
		{
			G[i].visited = false;
			G[i].troop = false;
		}
		for (int i = 1; i <= N; i++)
		{
			Dp[i][0] = Dp[i][1] = -1;
		}
		CurCost = 0;
		MinCost = InfLL;
		bool flag = dfs(1, true, 0);
		
		if (!flag) cout << -1 << '\n';
		else cout << MinCost << '\n';
	}
	
	return 0;
}

