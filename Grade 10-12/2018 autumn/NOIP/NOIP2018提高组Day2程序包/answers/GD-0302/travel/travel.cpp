#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 5E3;
const int MaxM = 5E3;

struct vect
{
	int v, nxt;
	vect(int _v = 0, int _nxt = 0) {v = _v, nxt = _nxt;}
};

struct node
{
	int u, v;
	node(int _u = 0, int _v = 0) {u = _u, v = _v;}
	bool friend operator < (node a, node b) {return a.v > b.v;}
};

int n, m, lim;
node p[MaxN + 5];
vect d[MaxM * 2 + 5];
int final[MaxN + 5], cnt;
bool bj[MaxN + 5];
int q[MaxN + 5];
int ans[MaxN + 5];

void Dfs(int u)
{
	bj[u] = true, q[++q[0]] = u;
	
	for (int i = final[u]; i; i = d[i].nxt)
	{
		int v = d[i].v;
		
		if (bj[v] || i == lim)
			continue;
		
		Dfs(v);
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		p[i] = node(u, v), p[i + m] = node(v, u);
	}
	
	m *= 2;
	sort(p + 1, p + m + 1);
	
	for (int i = 1; i <= m; i++)
		d[++cnt] = vect(p[i].v, final[p[i].u]), final[p[i].u] = cnt;
	
	memset(ans, 0x7f, sizeof(ans));
	
	for (lim = 1; lim <= m; lim++)
	{
		q[0] = 0, memset(bj, false, sizeof(bj));
		Dfs(1);
		
		if (q[0] == n)
		{
			bool judge = false;
			
			for (int i = 1; i <= n; i++)
				if (q[i] != ans[i])
				{
					judge = q[i] < ans[i];
					break;
				}
				
			if (judge)
				memcpy(ans, q, sizeof(ans));
		}
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
		
	printf("\n");
	
	return 0;
}

