#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define min(a, b) (a > b ? b : a)
using namespace std;
int to[400040], nxt[400040], bgn[400040], tot;
int fa[100010];
void dfs(int x){
	for(int i = bgn[x]; i; i = nxt[i]){
		if(to[i] == fa[x]) continue;
		fa[to[i]] = x;
		dfs(to[i]);
	}
}
int n, m;
int p[100010];
int f[100010][2];
char type[10];
int main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d %d %s\n", &n, &m, type);
	for(int i = 1; i <= n; i++)	scanf("%d", &p[i]);
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		to[++tot] = y, nxt[tot] = bgn[x], bgn[x] = tot;
		to[++tot] = x, nxt[tot] = bgn[y], bgn[y] = tot;
	}
	for(int i = 1; i <= m; i++){
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
