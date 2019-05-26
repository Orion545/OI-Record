#include <cstdio>
#include <cstring>
#define MAXN 5007
using namespace std;
bool e[MAXN][MAXN], vis[MAXN], has_make;
int n, m, ansq[MAXN], anstop = 0;
int dfs(int nc, int cnt){
	if (has_make) return n;
	ansq[anstop++] = nc;
	if (cnt == n){
		has_make = true;
		return n;
	}
	vis[nc] = true;
	for (int i = 1; i <= n; i++){
		if (!vis[i] && e[nc][i])
			cnt = dfs(i, cnt + 1);
	}
	return cnt;
}
int main(){ // accept n-1 
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++){
		int f, t;
		scanf("%d %d", &f, &t);
		e[f][t] = e[t][f] = true;
	}
	for (int i = 1; i <= n; i++){
		if (has_make) break;
		dfs(i, 0);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ansq[i]);
	return 0;
}
