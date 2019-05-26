#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#define LL long long
#define N  50005
#define INF 0x3f3f3f3f
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define drep(i,a,b) for (int i = a; i >= b; -- i)
#define il inline
using namespace std;
struct Edge {
	int v,next;
	LL w;
} e[N<<1];
int n,m,head[N],ecnt = 1,cnt = 0,id[N],top[N],son[N],siz[N],dep[N],fa[N],leaf[N],cntl = 0,que[N],vis[N];
LL dis[N];
struct cmp {
	bool operator()(int a,int b) {
		return id[a] > id[b];
	}
};
priority_queue<int,vector<int>,cmp> q;
il void add(int u,int v,int w) {
	e[++ecnt] = (Edge){v,head[u],w};
	head[u] = ecnt;
}
void dfs1(int u,int father,int depth) {
	fa[u] = father;
	dep[u] = depth;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v != father) {
			dis[v] = dis[u] + e[i].w;
			dfs1(v,u,depth+1);
			siz[u] += siz[v];
			if (siz[son[u]] < siz[v])
				son[u] = v;
		}
	}
}
void dfs2(int u,int f) {
	id[u] = ++cnt;
	top[u] = f;
	if (!son[u]) {
		leaf[++cntl] = u;
		return;
	}
	dfs2(son[u],f);
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v != fa[u] && v != son[u])
			dfs2(v,v);
	}
}
il int LCA(int x,int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]])
			x = fa[top[x]];
		else y  = fa[top[y]];
	}
	if (dep[x] < dep[y])
		return x;
	return y;
}
int dfs(int u,int len) {
	
}
il bool check(LL lim) {
	memset(vis,0,sizeof(vis));
	int num = 0;
	
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a,b;
	LL c,l = INF,r = 0,mid,ma = 0;
	scanf("%d%d",&n,&m);
	rep(i,1,n-1) {
		scanf("%d%d%lld",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		l = min(l,c);
		r += c;
	}
	if (m == n-1) {
		printf("%lld\n",l);
		return 0;
	}
	dfs1(1,0,1);
	dfs2(1,1);
	if (m == 1) {
		LL ans = 0;
		rep(i,1,n)
			rep(j,i+1,n) {
				ans = max(ans,dis[i] + dis[j] - (dis[LCA(i,j)] << 1));
			}
		printf("%lld\n",ans);
		return 0;
	}
	r /= m;
	while (l <= r) {
		mid = l + ((r-l) >> 1);
		if (check(mid))
			l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n",l);
	return 0;
}
