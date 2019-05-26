#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5005
bool mp[N][N];
int n, m, i, j, k, a, b, v[N], du[N], dyc[N];
int h[N], low[N], dfn[N], top, sta[N], ind, co[N], u[N], col;
struct AB{
	int a, b, n;
}d[N*2];
void dfs(int x){
	int i;
	if(v[x]==0) printf("%d ", x);
	v[x] ++;
	for(i=1; i<=n; i++){
		if(mp[x][i]&&v[i]<=du[i]){
			dfs(i);
		}
	}
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d%d", &a, &b);
		mp[a][b] = mp[b][a] = 1;
		d[++j].a = a, d[j].b = b;
		d[j].n = h[a], h[a] = j;
		d[++j].a = b, d[j].b = a;
		d[j].n = h[b], h[b] = j;
		du[a]++, du[b]++;
	}
	dfs(1);
	return 0;
}
