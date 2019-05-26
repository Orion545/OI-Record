/*
60%.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define DEBUG
using namespace std;
const int SCP=682*999/120;
int n, m, i, u, v;
int pre[SCP<<1], to[SCP<<1], head[SCP], wcnt;
int far[SCP];
int son[SCP][SCP], stop[SCP];
bool vis[SCP];
int deg[SCP], q[SCP], ql, qr;
int px, py;
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
void toposort(){
	int i, u, v;
	ql=1; qr=0;
	for(i=1; i<=n; i++) if(deg[i]==1) q[++qr]=i;
	while(ql<=qr){
		u=q[ql++];
		for(i=head[u]; i; i=pre[i]){
			deg[v=to[i]]--;
			if(deg[v]==1) q[++qr]=v;
		}
	}
	#ifdef DEBUG
	printf("DEBUG: ");
	for(i=1; i<=n; i++) printf("%d ", deg[i]);
	putchar('\n');
	#endif
}
void dfs1(int u){ // 确定儿子 
	int i;
	vis[u]=1;
	for(i=head[u]; i; i=pre[i]) if((deg[u]^2 or deg[to[i]]^2) and far[u]^to[i]){
		far[to[i]]=u;
		son[u][++stop[u]]=to[i];
		if(deg[to[i]]^2) dfs1(to[i]); 
	}
	sort(son[u]+1, son[u]+stop[u]+1);
}
void dfs2(int u){ // 输出子树 
	int i;
	vis[u]=1;
	printf("%d ", u);
	for(i=1; i<=stop[u]; i++) if(!vis[son[u][i]] and deg[son[u][i]]^2) dfs2(son[u][i]);
}
void dfs3(int u){
	int i, j;
	if(deg[u]^2){
		dfs2(u);
		for(i=head[u]; i and deg[to[i]]^2; i=pre[i]);
		if(i){
			q[ql=qr=1]=to[i];
			dfs3(to[i]);
		}
	}
	else{
		for(i=head[u]; i and (deg[to[i]]^2 or vis[to[i]]); i=pre[i]);
		for(j=head[u]; j and (deg[to[j]]^2 or vis[to[j]] or i==j); j=pre[j]);
		if(to[i]) q[++qr]=to[i];
		if(to[j]) q[++qr]=to[j];
		j=0;
		for(i=1; i<=qr; i++) if(q[i]<q[j] and !vis[q[i]] and q[i]^u) j=i;
		if(j){
			for(i=head[u]; i and to[i]^q[j]; i=pre[i]);
			if(i){
				vis[u]=1;
				printf("%d ", u);
				for(i=1; i<=stop[u] and son[u][i]<q[j]; i++) dfs2(son[u][i]);
				dfs3(q[j]);
				for(; i<=stop[u]; i++) dfs2(son[u][i]);
			}
			else{
				dfs2(u);
				dfs3(q[j]);
			}
		}
		else
			dfs2(u);
	}
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &u, &v);
		add2edge(u, v);
		deg[u]++;
		deg[v]++;
	}
	toposort();
	q[0]=10000000;
	ql=1; qr=0;
	for(i=1; i<=n; i++) if(!vis[i]) dfs1(i);
	memset(vis, 0, sizeof(vis));
	if(m==n-1){
		dfs2(1);
	}
	else{
		dfs3(1);
	}
	return 0;
}
