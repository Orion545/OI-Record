#include <cstdio>

const int NN = 5010;
const int MM = NN;
int N, M, ringPoint;

bool lineList[NN][NN];

bool onPath[NN];
bool onRing[NN];

void DfsTreePath(int cur, int from)
{
	printf("%d ", cur);
	for (int i=1; i<=N; i++)
		if (i != from && lineList[cur][i] == true)
		{
			// lineList[i][cur] = lineList[cur][i] = false;
			DfsTreePath(i, cur);
		}
}

bool DfsFindRing(int cur, int from)
{
	// printf("[Test] now %d, %d\n", cur, from);
	for (int i=1; i<=N; i++)
		if (i != from && lineList[cur][i] == true)
		{
			if (onPath[i])
			{
				ringPoint = i;
				onRing[cur] = true;
				lineList[cur][i] = lineList[i][cur] = false;
				return true;
			}
			onPath[i] = true;
			if (DfsFindRing(i, cur))
			{
				onRing[cur] = true;
				if (cur == ringPoint)
					return false;
				else
					return true;
			}
			onPath[i] = false;
		}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &N, &M);
	
	for (int i=1; i<=M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		lineList[u][v] = lineList[v][u] = true;
	}
	
	if (M != N)
	{
		DfsTreePath(1, 0);
		putchar('\n');
	}
	else
	{
		DfsFindRing(1, 0);
		DfsTreePath(1, 0);
		putchar('\n');
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

