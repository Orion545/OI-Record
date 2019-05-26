#include <cstdio>
#include <cstring>
#define INF 0x7fffffff

int n,m,edge_tot;
struct ed{
	int next;
	int to;
} edge[200010];
int head[100010];
int price[100010];
char c[5];
int army[100010];
int ans = INF;

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

inline void addedge(int from,int to){
	edge_tot += 1;
	edge[edge_tot].next = head[from];
	edge[edge_tot].to = to;
	head[from] = edge_tot;
}

void dfs(int x,int cost){
	if(x > n){
		/*
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if(army[i]) sum += price[i];
		}
		
		if(sum < ans) ans = sum;
		*/
		if(cost < ans) ans = cost;
		return;
	}
	if(x == 1){
		if(army[x] != -1){
			if(army[x] == 1) dfs(x + 1,cost + price[x]);
			else dfs(x + 1,cost);
		}else{
			army[x] = 0;
			dfs(x + 1,cost);
			army[x] = 1;
			dfs(x + 1,cost + price[x]);
		}
	}
	else{
		if(army[x] != -1) {
			if(army[x] == 0 && army[x - 1] == 0) return;
			if(army[x] == 1) dfs(x + 1,cost + price[x]);
			else dfs(x + 1,cost);
		}else{
			if(army[x - 1] == 0) {
				army[x] = 1;
				dfs(x + 1,cost + price[x]);
			}else{
				army[x] = 0;
				dfs(x + 1,cost);
				army[x] = 1;
				dfs(x + 1,cost + price[x]);
			}
		}
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n = read();
	m = read();	
	scanf("%s",c);
	for(int i = 1;i <= n;i++){
		price[i] = read();
	}
	int tmp1,tmp2,tmp3,tmp4;
	for(int i = 1;i < n;i++){
		tmp1 = read();
		tmp2 = read();
		addedge(tmp1,tmp2);
		addedge(tmp2,tmp1);
	}
	if(c[0] == 'A'){
		for(int i = 1;i <= m;i++){
			memset(army,-1,sizeof(army));
			tmp1 = read();
			tmp2 = read();
			tmp3 = read();
			tmp4 = read();
			//if(tmp3 == 0 && tmp4 == 0 && map[tmp1][tmp3] = 1) printf("-1\n"),continue;
			army[tmp1] = tmp2;
			army[tmp3] = tmp4;
			dfs(1,0);
			if(ans == INF) printf("-1\n");
			else printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
