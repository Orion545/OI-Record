#include <cstdio>
#define N 100005
using namespace std;

struct arr
{
 int nxt, to;
}a[N];
int n,m,b[N],v[N],tot;
int l,ls[N],c[5005][5005];

void fswap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

void dfs(int x, int fa)
{
	b[++tot] = x;
	v[x]++;
	if (tot == n) return;
	for (int i = 1; i <= c[x][0]; i++)
		if (!v[c[x][i]]) dfs(c[x][i], x);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		c[x][++c[x][0]] = y;
		c[y][++c[y][0]] = x;
	}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= c[k][0]; i++)
				for (int j = i + 1; j <= c[k][0]; j++)
					if (c[k][i] > c[k][j]) fswap(c[k][i], c[k][j]);
		}
		dfs(1, 0);
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	fclose(stdin);
	fclose(stdout);
}
