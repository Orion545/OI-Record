#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,bool> pib;
const int MAX_N = 100005, MAX_M = 100005, MAX_p = 100005;
int n,m;
int cost[MAX_N];
int q[MAX_N][6];
char type[5];
bool visited[MAX_N],status[MAX_N];
vector<int> G[MAX_N];
queue<pib> que;

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&type);
	for (int i = 1; i <= n; i++) scanf("%d",&cost[i]);
	int from,to;
	for (int i = 1; i <= n-1; i++){
		scanf("%d%d",&from,&to);
		G[from].push_back(to);
		G[to].push_back(from);
	}
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d%d",&q[i][1],&q[i][2],&q[i][3],&q[i][4]);
	}
	if (type[0] == 'A'){
		for (int i = 1; i <= m; i++){
			int a = q[i][1], x = q[i][2], b = q[i][3], y = q[i][4];
			//printf("a = %d, x = %d, b = %d, y = %d\n",a,x,b,y);
			if (((b-a)%2 == 1 && x == y) || ((b-a)%2 == 0) && x != y){
				printf("-1\n");
				continue;
			}
			if (x == 1 && y == 1){
				int start = 0,ans = 0;
				if (a % 2 == 0) start = 2;
				else start = 1;
				for (int i = start; i <= n; i += 2){
					ans += cost[i];
				}
				printf("%d\n",ans);
			} else if (x == 0 && y == 0){
				int start = 0,ans = 0;
				if (a % 2 == 0) start = 1;
				else start = 2;
				for (int i = start; i <= n; i += 2){
					ans += cost[i];
					//printf("cost[%d] = %d, ans = %d\n",i,cost[i],ans);
				}
				printf("%d\n",ans);
			} else{
				int start = 0,ans = 0;
				if (x == 1){
					if (a % 2 == 0) start = 2;
					else start = 1;
				} else {
					if (b % 2 == 0) start = 2;
					else start = 1;
				}
				for (int i = start; i <= n; i += 2){
					ans += cost[i];
				}
				printf("%d\n",ans);
			}
		}
	} else if (type[1] == '1'){
		for (int i = 1; i <= m; i++){
			while(!que.empty()) que.pop();
			memset(visited,0,sizeof(visited));
			memset(status,0,sizeof(status));
			int a = q[i][1], x = q[i][2], b = q[i][3], y = q[i][4];
			visited[a] = true; status[a] = true;
			que.push(make_pair(1,true));
			while(!que.empty()){
				pib p = que.front(); que.pop();
				int dp = p.first; int ds = p.second;
				for (int i = 0; i < G[dp].size(); i++){
					if (!visited[G[dp][i]]){
						status[G[dp][i]] = !ds;
						visited[G[dp][i]] = true;
						que.push(make_pair(G[dp][i],!ds));
					}
				}
			}
			int ans = 0;
			if (status[b] != y){
				printf("-1\n");
			} else{
				for (int i = 1; i <= n; i++){
					if (status[i]) ans += cost[i];
				}
				printf("%d\n",ans);
			}
			
		}
	} else{
		for (int i = 1; i <= m; i++){
			while(!que.empty()) que.pop();
			memset(visited,0,sizeof(visited));
			memset(status,0,sizeof(status));
			int a = q[i][1], x = q[i][2], b = q[i][3], y = q[i][4];
			visited[a] = true; status[a] = x;
			que.push(make_pair(a,x));
			while(!que.empty()){
				pib p = que.front(); que.pop();
				int dp = p.first; int ds = p.second;
				for (int i = 0; i < G[dp].size(); i++){
					if (!visited[G[dp][i]]){
						status[G[dp][i]] = !ds;
						visited[G[dp][i]] = true;
						que.push(make_pair(G[dp][i],!ds));
					}
				}
			}
			int ans = 0;
			if (status[b] != y){
				printf("-1\n");
			} else{
				for (int i = 1; i <= n; i++){
					if (status[i]) ans += cost[i];
				}
				printf("%d\n",ans);
			}
			
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
