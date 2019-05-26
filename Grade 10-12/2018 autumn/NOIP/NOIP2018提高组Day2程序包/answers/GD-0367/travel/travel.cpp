#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 5005

using namespace std;

struct {
	int to;
	int next;
} edge[MAXN * 2];
int n, m;
int cnt;
int head[MAXN];
int book[MAXN];

void add_edge(int a, int b)
{
	cnt++;
	edge[cnt].to = b;
	edge[cnt].next = head[a];
	head[a] = cnt;
}

void search_tree(int u, int last)
{
	printf("%d ", u);
	int nextp[MAXN], sum = 0;
	for (int i = head[u]; i != 0; i = edge[i].next)
		if (edge[i].to != last)
			nextp[sum++] = edge[i].to;
	sort(nextp, nextp + sum);
	for (int i = 0; i < sum; i++) search_tree(nextp[i], u);
}
void search_graph(int u, int last)
{
	printf("%d ", u, last);
	book[u] = 1;
	int nextp[MAXN], sum = 0;
	for (int i = head[u]; i != 0; i = edge[i].next)
		if (edge[i].to != last && !book[edge[i].to])
			nextp[sum++] = edge[i].to;
	sort(nextp, nextp + sum);
	for (int i = 0; i < sum; i++)
		if (!book[edge[i].to])
			search_graph(nextp[i], u);
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
		add_edge(b, a);
	}
	if (m == n - 1)
		search_tree(1, 0);
	else search_graph(1, 0);
	return 0;
}
