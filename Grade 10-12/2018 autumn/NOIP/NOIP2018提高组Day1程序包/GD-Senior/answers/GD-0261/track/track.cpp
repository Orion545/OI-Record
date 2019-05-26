#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#define MAXN 50007
using namespace std;
struct Edge {
	int to, next, weight;
} e[MAXN];
int head[MAXN], etop = 0, n ,m;
void build(int from, int to, int weight){
	e[++etop].to = to;
	e[etop].weight = weight;
	e[etop].next = head[from];
	head[from] = etop;
}
int f[MAXN];
bool vis[MAXN];
int dfs(int now){
	f[now] = 0; vis[now] = true;
	for (int i = head[now]; i != 0; i=e[i].next){
		if (!vis[e[i].to]){
			int nl = e[i].weight + dfs(e[i].to);
			f[now] = max(f[now], nl); 
		}
	}
	return f[now];
}
int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int fr,t,w;
	for (int i = 0; i < n - 1; i++){
		scanf("%d %d %d", &fr,&t, &w);	
		build(fr, t, w);
		build(t, fr, w);
	}
	for (int i = 1; i<=n; i++){
		if (f[i] != 0) continue;
		memset(vis, 0,sizeof(vis));
		dfs(i);
	}
	int maxl = 0;
	for (int i = 1; i <=n;i++){
		if (f[i] > maxl) maxl = f[i];
	}
	printf("%d", maxl);
	return 0;
}

