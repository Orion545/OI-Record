#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, num = 0, fst[50010], dis[50010];
struct edge
{
	int x, y, c, n;
} e[100010];

void ins(int x, int y, int c)
{
	num++;
	e[num].x = x;
	e[num].y = y;
	e[num].c = c;
	e[num].n = fst[x];
	fst[x] = num;
}
int bfs(int x)
{
	static queue<int> q;
	memset(dis, 63, sizeof(dis));
	dis[x] = 0;
	q.push(x);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = fst[x]; i; i = e[i].n)
		{
			int y = e[i].y;
			if (dis[y] > dis[x] + e[i].c)
			{
				dis[y] = dis[x] + e[i].c;
				q.push(y);
			}
		}
	}
	int id = x;
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] > dis[id]) id = i;
	}
	return id;
}
int cmp(edge x, edge y)
{
	return x.c > y.c;
}
bool chk(int x)
{
	int ans = 0, last = 1;
	for (int i = 2; i <= n; i++)
	{
		if (dis[i] - dis[last] >= x)
		{
			ans++;
			last = i;
		}
	}
	return ans >= m;
}
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		ins(x, y, c);
		ins(y, x, c);
	}
	if (m == 1)
	{
		printf("%d\n", dis[bfs(bfs(1))]);
	}
	else
	{
		bfs(1);
		int l = 1, len = dis[n];
		while (len)
		{
			int md = l + (len >> 1);
			if (chk(md))
			{
				l = md + 1;
				len = len - (len >> 1) - 1;
			}
			else
				len >>= 1;
		}
		printf("%d\n", l - 1);
	}
}
