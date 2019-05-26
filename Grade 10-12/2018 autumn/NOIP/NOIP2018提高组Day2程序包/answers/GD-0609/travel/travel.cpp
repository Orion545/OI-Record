#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 5007;

int n, m, tot, a, ans[N], vis[N];
vector<int> lis[N];

void dfs(int u)
{
	ans[++tot] = u, vis[u] = 1;
	int siz = lis[u].size();
	for (int i = 0; i < siz; i++)
		if (!vis[lis[u][i]])
			dfs(lis[u][i]);
}

int flag, top, fir, stk[N], f[N];
void findr(int u, int from)
{

	stk[++top] = u, vis[u] = 1;
	int siz = lis[u].size();
	for (int i = 0; i < siz; i++)
	{
		if (vis[lis[u][i]] && lis[u][i] != from)
		{
			while (stk[top] != lis[u][i]) f[stk[top]] = 1, top--;
			f[stk[top]] = 1, top--;
			flag = 1; return;
		}
		if (!vis[lis[u][i]]) findr(lis[u][i], u);
		if (flag) return;
	}
	top--;
}

void dfsx(int u)
{
	ans[++tot] = u, vis[u] = 1;
	int siz = lis[u].size();
	int a = N;
	for (int i = 0; i < siz; i++)
		if (!vis[lis[u][i]])
		{
			if (f[u] && f[lis[u][i]])
			{
				if (lis[u][i] > a && !vis[a]) dfsx(a);
				for (int j = 0; j < siz; j++)
					if (lis[u][j] != lis[u][j] && lis[u][j] < a)
						a = lis[u][j];
				else dfsx(lis[u][i]);
			}
			else dfsx(lis[u][i]);
		}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		lis[u].push_back(v), lis[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) sort(lis[i].begin(), lis[i].end());
	if (m == n - 1) dfs(1);
	else
	{
		findr(1, 0);
		memset(vis, 0, sizeof(vis));
		dfsx(1);
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
