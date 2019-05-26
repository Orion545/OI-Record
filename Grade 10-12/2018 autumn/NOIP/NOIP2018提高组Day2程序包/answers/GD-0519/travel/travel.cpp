#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#define N 5005
#define INF 0x3f3f3f3f
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define il inline
using namespace std;
//struct Edge {
//	int v,next;
//} e[N<<1];
int n,m,tans[N],ans[N],tot = 0,sta[N],top = 0,d[N],totd = 0/*,ecnt = 0,head[N]*/;
bool g[N][N],vis[N],in[N];
//il void add()
bool work(int u,int fa) {
	if (vis[u]) {
		while (sta[top+1] != u) {
			d[++totd] = sta[top--];
			in[sta[top]] = 1;
		}
		return 1;
	}
	sta[++top] = u;
	vis[u] = 1;
	rep(i,1,n)
		if (g[u][i] && i != fa)
			if (work(i,u)) return 1;
	vis[u] = 0;
	return 0;
}
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	tans[++tot] = u;
	rep(i,1,n)
		if (g[u][i] && !vis[i])
			dfs(i);
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	scanf("%d%d",&n,&m);
	rep(i,1,m) {
		scanf("%d%d",&a,&b);
		g[a][b] = g[b][a] = 1;
	}
	if (m == n) {
		memset(ans,INF,sizeof(ans));
		bool flag = 0;
		work(1,0);
		rep(i,1,totd-1) {
			memset(vis,0,sizeof(vis));
			memset(tans,INF,sizeof(tans));
			flag = (tot = 0);
			a = d[i],b = d[i+1];
			g[a][b] = g[b][a] = 0;
			dfs(1);
			rep(j,1,n) {
				if (tans[j] < ans[j]) {
					flag = 1;
					break;
				}
				if (tans[j] > ans[j]) break;
			}
			if (flag)
				rep(j,1,n)
					ans[j] = tans[j];
			g[a][b] = g[b][a] = 1;
		}
	}
	else {
		dfs(1);
		rep(i,1,n)
			ans[i] = tans[i];
	}
	rep(i,1,n)
		printf("%d ",ans[i]);
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
