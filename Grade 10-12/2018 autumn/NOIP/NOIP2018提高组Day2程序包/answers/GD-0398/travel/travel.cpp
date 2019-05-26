#include <cstdio>
#define N 5005
using namespace std;
int mp[N][N], zhan[N], a, b, v[N], u[N*2], i, j, n, m, cnt;

void dfs(int a)
{
	int i, b;
	if (zhan[0] == n) return;
	for (i=1; i<=u[0]; ++i) {
		if (!mp[u[i]][a]) u[i] = 0;
	}
	v[a] = 1;
	u[++u[0]] = a;
	for (b=1; b<=n; ++b) {
		if (!v[b])
		{
			for (i=1; i<=u[0]; ++i) {
				if (u[i] && mp[u[i]][b]) {
					if (!v[b]) {
						zhan[++zhan[0]] = b;
						v[b] = 1;
						dfs(b);
						if (zhan[0] == n) return;
						else u[++u[0]] = a, b = 1;
						break;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (i=1; i<=m; ++i) {
		scanf("%d%d", &a, &b);
		mp[a][b] = mp[b][a] = 1;
	}
	v[1] = 1;
	u[0] = u[1] = 1;
	zhan[0] = zhan[1] = 1;
	dfs(1);
	for (j=1; j<=zhan[0]; ++j) {
		printf("%d ", zhan[j]);
	}
	printf("\n");
	return 0;
}
