#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 100005
using namespace std;
int n, m;
int k, head[maxn];
int mu, mv, mn = (1<<30), ans1, ans2, vis[maxn];
int top[maxn], siz[maxn], dep[maxn], son[maxn], fat[maxn], dis[maxn];
struct Edge{
	int to;
	int next;
	int weight;
}Edge[maxn];
void Build(int u, int v, int w){
	Edge[k].to = v;
	Edge[k].weight = w;
	Edge[k].next = head[u];
	head[u] = k++;
}
void dfs1(int x, int father, int deep){
	siz[x] = 1;
	dep[x] = deep;
	fat[x] = father;
	for(int i = head[x]; ~i; i = Edge[i].next)
	{
		if(Edge[i].to == father)		continue;
		dfs1(Edge[i].to, x, deep+1);
		siz[x] += siz[Edge[i].to];
		int maxson = -1;
		if(siz[Edge[i].to] > maxson)
			son[x] = Edge[i].to, maxson = siz[Edge[i].to];
	}
}
void dfs2(int x, int tp){
	top[x] = tp;
	if(son[x])	dfs2(son[x], tp);
	for(int i = head[x]; ~i; i = Edge[i].next)
	{
		if(Edge[i].to == fat[x] || Edge[i].to == son[x])	continue;
		dfs2(Edge[i].to, Edge[i].to);
	}
}
int LCA(int x, int y){
	while(top[fat[top[x]]] != top[fat[top[y]]])	 dep[x] > dep[y] ? x = fat[top[x]] : y = fat[top[y]];
	dep[top[x]] < dep[top[y]] ?	y = fat[top[y]] : x = fat[top[x]];
	return dep[x] > dep[y] ? y : x;
}
void ddfs1(int x, int val){
	if(Edge[head[x]].next == -1)
	{
		ans1 = max(ans1, val);
		return;
	}
	vis[x] = 1;
	for(int i = head[x]; ~i; i = Edge[i].next)
	{
		if(vis[Edge[i].to])		continue;
		if(Edge[i].to == mv)	continue;
		ddfs1(Edge[i].to, val+Edge[i].weight);	
	}
	vis[x] = 0;
}
void ddfs2(int x, int val){
	if(Edge[head[x]].next == -1)
	{
		ans2 = max(ans2, val);
		return;
	}
	vis[x] = 1;
	for(int i = head[x]; ~i; i = Edge[i].next)
	{
		if(vis[Edge[i].to])		continue;
		if(Edge[i].to == mu)	continue;
		ddfs2(Edge[i].to, val+Edge[i].weight);	
	}
	vis[x] = 0;
}
int main(void)
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n-1; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		Build(u, v, w);
		Build(v, u, w);
		if(w < mn)	mn = w, mu = u, mv = v;
	}
	dfs1(1, 1, 1);
	dfs2(1, 1);
	ddfs1(mu, 0);
	ddfs2(mv, 0);
	printf("%d\n", ans1+ans2+mn);
	//cout << mv << endl;
	//cout << ans1 << " " << ans2 << endl;
	return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
