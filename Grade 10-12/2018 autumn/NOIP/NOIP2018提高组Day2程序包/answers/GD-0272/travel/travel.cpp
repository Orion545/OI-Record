#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
bool g[maxn][maxn];
bool visited[maxn], underVisiting[maxn];
int order[maxn];
int cntVisited = 0;

int n, m;

//priority_queue<int, vector<int>, greater<int> > q;
queue<int> q;

void dfs(int nowVisiting = 1)
{
//	printf("Now processing is %d.\n", nowVisiting);
	if (underVisiting[nowVisiting])
		return;
	if (!visited[nowVisiting])
	{
//		printf("*****Unvisited point %d.*****\n", nowVisiting);
		visited[nowVisiting] = true;
		order[cntVisited++] = nowVisiting;
	}
	
	for (int i = 0; i <= n; ++i)
		if (g[nowVisiting][i] && !underVisiting[i])
		{
			underVisiting[nowVisiting] = true;
			g[nowVisiting][i] = false;
//			printf("Entering solve(%d).\n", i);
			dfs(i);
//			printf("Exiting solve(%d).\n", i);
//			getchar();
			underVisiting[nowVisiting] = false;
		}
}

void bfs()
{
	q.push(1);
	while (!q.empty())
	{
		int nowVisiting = q.front();	q.pop();
		if (!visited[nowVisiting])
		{
			visited[nowVisiting] = true;
			order[cntVisited++] = nowVisiting;
		}
		
		for (int i = 0; i <= n; ++i)
			if (g[nowVisiting][i] && !visited[i])
			{
				g[nowVisiting][i] = false;
				q.push(i);
			}
	}
}
/*
void query()
{
	while (true)
	{
		printf("Enter a node:");
		int node;
		scanf("%d", &node);
		for (int i = 0; i <= n; ++i)
			if (g[i][node] && !visited[node])
				printf("%d ", i);
		visited[node] = !visited[node];
		printf("\n");
	}
}
*/
int main()
{
	FILE* fin = fopen("travel.in", "rb");
	FILE* fout = fopen("travel.out", "wb");
	
	fscanf(fin, "%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		fscanf(fin, "%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	
//	query();
	
	if (n == m)	bfs();
	else	dfs();

//	dfs();
	
	for (int i = 0; i < n; ++i)
		fprintf(fout, "%d ", order[i]);
	return 0;
}
