#include <iostream>
#include <cstdio>
#include <algorithm>
#define goedge(u) for (int ei = head[u]; ei != 0; ei = edge[ei].nxt)
#define repu(i, x, y) for (int i = x; i <= y; ++i)
using namespace std;
int n, m;
//struct Edge
//{
//	int u,v,w,nxt;
//} edge[2 * MAXN];
//int head[MAXN], ecnt;
//void addEdge(int u, int v, int w)
//{
//	edge[++ecnt] = (Edge){u, v, w, head[u]};
//	head[u] = ecnt;
//}
int mp[1011][1011], dis[1011][1011];
//struct E
//{
//	int v, int w;
//	bool operator<(const E& other) { return w > other.w; }
//} e[2 * MAXN];
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	bool all1 = true;
	repu(i, 1, n - 1)
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		mp[u][v] = mp[v][u] = w;
		if (u != 1) all1 = false;
//		addEdge(u, v, w);
//		addEdge(v, u, w);
	}
	repu(i, 1, n) repu(j, 1, n)
	{
		if (mp[i][j]) dis[i][j] = mp[i][j];
		else dis[i][j] = 0x3f3f3f3f;
	}
	repu(k, 1, n)
	{
		repu(i, 1, n)
		{
			repu(j, 1, n)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	int ans = 0;
	repu(i, 1, n)
	{
		repu(j, 1, i - 1)
		{
			ans = max(ans, dis[i][j]);
		}
	}
	printf("%d\n", ans);
//	if (all1)
//	{
//		repu(i, 2, n)
//		{
//			e[i - 1] = (E){i, mp[1][i]};
//		}
//	}
//	sort(e + 1, e + n - 1);
//	
	return 0;
}
