#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int MaxN = 5E4;
const int Maxint = 1E9;

struct node
{
	int v, w, nxt;
	node(int _v = 0, int _w = 0, int _nxt = 0) {v = _v, w = _w, nxt = _nxt;}
};

int n, m;
node d[MaxN * 2 + 5];
int final[MaxN + 5], cnt;
int dep[MaxN + 5], pos[MaxN + 5];
int tmp[MaxN + 5];
bool bj[MaxN + 5];
int g[MaxN + 5];
int ans;

bool cmp(int a, int b) {return dep[a] > dep[b];}

void Link(int u, int v, int w)
{
	d[++cnt] = node(v, w, final[u]), final[u] = cnt;
	d[++cnt] = node(u, w, final[v]), final[v] = cnt;
}

void Bfs()
{
	queue <int> q;
	q.push(1);
	
	for (; !q.empty(); q.pop())
	{
		int u = q.front(), v;
		dep[u]++;
		
		for (int i = final[u]; i; i = d[i].nxt)
		{
			v = d[i].v;
			
			if (dep[v])
				continue;
				
			dep[v] = dep[u], q.push(v);
		}
	}
	
	for (int i = 1; i <= n; i++)
		pos[i] = i;
		
	sort(pos + 1, pos + n + 1, cmp);
}

bool Judge(int lim)
{
	int cnt = 0;
	
	for (int k = 1; k <= n && cnt < m; k++)
	{
		int u = pos[k], v;
		g[u] = 0;
		tmp[0] = 0;
		
		for (int i = final[u]; i; i = d[i].nxt)
		{
			v = d[i].v;
			
			if (dep[v] < dep[u])
				continue;
				
			tmp[++tmp[0]] = g[v] + d[i].w;
			bj[tmp[0]] = false;
		}
		
		sort(tmp + 1, tmp + tmp[0] + 1);
		
		for (; tmp[tmp[0]] >= lim; tmp[0]--)
			cnt++;
			
		tmp[tmp[0] + 1] = Maxint;
		bj[tmp[0] + 1] = false;
		
		for (int i = 1; i <= tmp[0]; i++)
			if (!bj[i])
			{
				int val = lower_bound(tmp + i + 1, tmp + tmp[0] + 2, lim - tmp[i]) - tmp;
				
				for (; bj[val]; val++);
				
				if (val <= tmp[0])
					cnt++, bj[val] = true;
				else
					g[u] = tmp[i];
			}
	}
	
	return cnt >= m;
}

int Binary_Search(int l, int r)
{
	if (l >= r)
		return l;
		
	int mid = (l + r >> 1) + 1;

	if (Judge(mid))
		Binary_Search(mid, r);
	else
		Binary_Search(l, mid - 1);
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		Link(u, v, w);
	}
	
	Bfs();
	printf("%d\n", Binary_Search(0, 5E8));
	
	return 0;
}

