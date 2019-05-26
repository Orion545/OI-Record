#include<cstdio>
#include<queue>
using namespace std;
int to[12000], nxt[12000], bgn[12000], tot;
void add(int x, int y){
	to[++tot] = y;
	nxt[tot] = bgn[x];
	bgn[x] = tot;
}
int ans[12000], n, cnt;
int fa[12000];
bool map[5001][5001], flag[5001], vis[5001];
void dfs2(int x){
	vis[x] = 1;
	ans[++cnt] = x;
	for(int i = 1; i <= n; i++)	if(map[x][i] && !vis[i]) dfs2(i);
}
int m;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		map[x][y] = map[y][x] = 1;
		add(x, y);add(y, x);
	}
	ans[1] = 1;
	if(n == m + 1) dfs2(1);
	else{
		queue<int> Q;
		Q.push(1);
		fa[1] = 1;
		while(!Q.empty()){
			int x = Q.front();
			Q.pop();
			for(int i = bgn[x]; i; i = nxt[i]){
				if(to[i] == fa[x]) continue;
				if(!fa[to[i]]){
					fa[to[i]] = x;
					Q.push(to[i]);
				}
				else{
					if(x < to[i]){
						if(x > fa[to[i]]) map[fa[to[i]]][to[i]] = map[to[i]][fa[to[i]]] = 0;
						else map[x][to[i]] = map[to[i]][x] = 0;
					}
				}
			}
		}
		dfs2(1);
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
