#include <cstdio>
#define INF 0x7fffffff

int n,m,edge_tot;
struct ed{
	int next;
	int to;
} edge[10010];
int head[5010];
int ans[5010];
int vis[5010];

inline int read(){
	int res = 0;
	int sym = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') sym = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res * sym;
}

inline int addedge(int from,int to){
	edge_tot += 1;
	edge[edge_tot].next = head[from];
	edge[edge_tot].to  =to;
	head[from] = edge_tot;
}

void dfs(int node){
	for(int i = 1;i <= n;i++){
		if(ans[i] == 0) {
			ans[i] = node;
			break;
		}
	}
	int x = 0;
	int t = 0;
	while(x != INF){
		x = INF;
		for(int i = head[node];i;i = edge[i].next){
			int u = edge[i].to;
			if(vis[u] == 0 && u < x) x = u;
		}
		//printf("%d ",x);
		if(x != INF){
			vis[x] = 1;
			dfs(x);
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read();
	m = read();
	int tmp1,tmp2;
	for(int i = 1;i <= m;i++){
		tmp1 = read();
		tmp2 = read();
		addedge(tmp1,tmp2);
		addedge(tmp2,tmp1);
	}
	vis[1] = 1;
	dfs(1);
	for(int i = 1;i <= n;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
