/*
44.
设

f[u][0] = u驻军而v驻军 
f[u][1] = u驻军而v不驻军
f[u][2] = u不驻军而v驻军 
f[u][3] = u不驻军而v不驻军 

f[u][0] = min{ sum{min{f[v][0], f[v][1], f[v][2], f[v][3]}|v!=k} + min{f[k][0], f[k][1]} } + 1
f[u][1] = sum{min{f[v][2], f[v][3]}} + 1
f[u][2] = min{ sum{min{f[v][0], f[v][1], f[v][2], f[v][3]}|v!=k} + min{f[k][0], f[k][1]} }
f[u][3] = sum{f[v][2]}

对于叶节点u
f[u][0] = INF
f[u][1] = 1
f[u][2] = INF
f[u][3] = 0 

对于要求u不驻军 
f[u][0] = INF
f[u][1] = INF

对于要求u驻军
f[u][2] = INF
f[u][3] = INF 
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int SCP=682*999/600, INF=1e9;
int f[SCP][4], far[SCP];
int pre[SCP<<1], to[SCP<<1], head[SCP], wcnt;
int val[SCP];
int qa, qx, qb, qy;
int n, m, u, v;
inline void addedge(int u, int v){ pre[++wcnt]=head[u]; head[u]=wcnt; to[wcnt]=v; }
inline void add2edge(int u, int v){ addedge(u, v); addedge(v, u); }
void predfs(int u){
	int i, v;
	for(i=head[u]; i; i=pre[i]) if(far[u]^(v=to[i])){
		far[v]=u;
		predfs(v);
	}
}
/*

f[u][0] = min{ sum{min{f[v][0], f[v][1], f[v][2], f[v][3]}|v!=k} + min{f[k][0], f[k][1]} } + 1
f[u][1] = sum{min{f[v][2], f[v][3]}} + 1
f[u][2] = min{ sum{min{f[v][0], f[v][1], f[v][2], f[v][3]}|v!=k} + min{f[k][0], f[k][1]} }
f[u][3] = sum{f[v][2]}
对于叶节点u
f[u][0] = INF
f[u][1] = 1
f[u][2] = INF
f[u][3] = 0 
*/
void dfs(int u){
	int i, v, sum1=0, sum2=0;
	f[u][0]=INF;
	f[u][1]=val[u];
	f[u][2]=0;
	f[u][3]=0;
	for(i=head[u]; i; i=pre[i]) if(far[v=to[i]]==u){
		dfs(v);
		if(sum1<INF) sum1+=min(min(f[v][0], f[v][1]), min(f[v][2], f[v][3]));
//		if(sum2<INF) sum2+=min(min(f[v][0], f[v][1]), f[v][2]);
		f[u][2]+=min(f[v][0], f[v][1]);
		if(f[u][1]<INF) f[u][1]+=min(f[v][2], f[v][3]);
		f[u][3]=INF;
	}
	for(i=head[u]; i; i=pre[i]) if(far[v=to[i]]==u)
		f[u][0]=min(f[u][0], sum1-min(min(f[v][0], f[v][1]), min(f[v][2], f[v][3]))+min(f[v][0], f[v][1]));
	f[u][0]+=val[u];
	if((u==qa and qx) or (u==qb and qy)) f[u][2]=f[u][3]=INF;
	if((u==qa and !qx) or (u==qb and !qy)) f[u][0]=f[u][1]=INF;
}
int main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	int i, ans;
	char ch;
	scanf("%d %d", &n, &m);
	do ch=getchar(); while(ch>=32);
	for(i=1; i<=n; i++) scanf("%d", &val[i]);
	for(i=1; i<n; i++){
		scanf("%d %d", &u, &v);
		add2edge(u, v);
	}
	predfs(1);
	for(i=1; i<=m; i++){
		scanf("%d %d %d %d", &qa, &qx, &qb, &qy);
		dfs(1);
		ans=min(min(f[1][0], f[1][1]), f[1][2]);
		printf("%d\n", (ans<INF)?ans:-1);
	}
	return 0;
}
