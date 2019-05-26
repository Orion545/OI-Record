#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct edge{
	int from,to;
};

const int MAX_N = 5005, MAX_M = 5005, INF = 0x3f3f3f3f;
bool visited[MAX_N],reachable[MAX_N],noWay;
int from[MAX_N],next;
int n,m,cnt,edgeCnt;
vector<edge> G[MAX_N];
edge Gsort[MAX_M*2];
vector<int> Gint[MAX_N];
priority_queue<int, vector<int>, greater<int> > pq;

bool comp(edge a, edge b){
	if (a.from == b.from) return a.to < b.to;
	else return a.from < b.from;
}

//void print(){
//	int printCnt = 1, now = 1;
//	printf("1 ");
//	while(printCnt < n){
//		if (path[now] != 0){
//			printf("%d ",path[now]);
//			printCnt++;
//			now = path[now];
//		} else{
//			if (from[now] != 0) now = from[now];
//		}
//	}
//}

void solve (int now){
//	if (cnt == n){
//		print();
//		return;
//	}
	//printf("now = %d\n",now);
	//printf("path[%d] = %d\n",now,path[now]);
	//printf("from[%d] = %d\n",now,from[now]);
	next = INF; noWay = true;
	//visited[now] = true;
	for (int i = 0; i < G[now].size(); i++){
		if (!visited[G[now][i].to]){
			//if (path[now] == 0){
			//path[now] = G[now][i].to;
			from[G[now][i].to] = now;
		//}
			printf("%d ",G[now][i].to);
			visited[G[now][i].to] = true;
			//cnt++;
			noWay = false;
			solve(G[now][i].to);
		}
	}
	
//	for (int i = 0; i < G[now].size(); i++){
//		
//	}
	if (noWay){
		if (from[now] != 0) solve(from[now]);
	}
//	if (next != INF){
//		printf("path[%d] = %d\n",now,next);
//		if (!visited[next]){
//			path[now] = next;
//			from[next] = now;
//			visited[next] = true;
//			cnt++;
//		}
//		solve(next);
//	} else{
//		solve(from[now]);
//	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	edge e; int a,b;
	for (int i = 1; i <= m; i++){
		scanf("%d%d",&a,&b);
		e.from = a; e.to = b;
		Gsort[++edgeCnt] = e;
		e.from = b; e.to = a;
		Gsort[++edgeCnt] = e;
		Gint[a].push_back(b);
		Gint[b].push_back(a);
	}
	if (m == n-1)	{
	
	sort(Gsort+1,Gsort+1+edgeCnt,comp);
	for (int i = 1; i <= edgeCnt; i++){
		G[Gsort[i].from].push_back(Gsort[i]);
	}
//	for (int i = 1; i <= edgeCnt; i ++){
//		printf("Gsort[%d].from = %d, Gsort[%d].to = %d\n",i,Gsort[i].from,i,Gsort[i].to);
//	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 0; j < G[i].size(); j++){
//			printf("G[%d][%d].to = %d\n",i,j,G[i][j].to);
//		}
//	}
	visited[1] = true;
	printf("1 ");
	solve(1);
	} else{
		reachable[1] = true;
	for (int i = 1; i <= n; i++) pq.push(i);
	while (!pq.empty()) {
		int t = pq.top(); pq.pop();
		if (reachable[t] && !visited[t]){
			for (int j = 0; j < Gint[t].size(); j++){
				reachable[Gint[t][j]] = true;
				pq.push(Gint[t][j]);
			}
			visited[t] = true;
			printf("%d ",t);
		}
	}
	}
	//for (int i = 1; i <= n; i++){
		//printf("path[%d] = %d\n",i,path[i]);
		//printf("from[%d] = %d\n",i,from[i]);
	//}
	//print();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
