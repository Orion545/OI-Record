#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 100005
using namespace std;
int n, m;
int k, head[maxn];
bool vis[maxn];
struct Edge{
	int to;
	int next;
}Edge[maxn];
struct Point{
	int w;
};
bool operator < (const Point &A, const Point &B){
	return A.w > B.w;
}
priority_queue<Point> q1[5005];
void Build(int u, int v){
	Edge[k].to = v;
	Edge[k].next = head[u];
	head[u] = k++;
}
void dfs(int x){
	vis[x] = true;
	printf("%d ", x);
	while(!q1[x].empty())
	{
		int tmp = q1[x].top().w;	q1[x].pop();
		if(vis[tmp])	continue;
		dfs(tmp);
	}
	//vis[x] = false;
}
int main(void)
{
	///*
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//*/
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		Build(u, v);
		Build(v, u);
		q1[u].push((Point){v});
		q1[v].push((Point){u});
	}
	dfs(1);
	return 0;
}
