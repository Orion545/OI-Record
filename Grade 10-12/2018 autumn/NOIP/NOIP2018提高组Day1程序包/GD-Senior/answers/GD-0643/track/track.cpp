#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct edge{
	int to,d;
};

typedef long long ll;
const int MAX_N = 50005;
int n,m,edgeCnt,sumCnt, mx = -0x3f3f3f3f;
bool allA1 = true, allAB = true;
bool reached[MAX_N];
edge Ga1[MAX_N];
vector<edge> G[MAX_N];
priority_queue<int> sums;
int sum[MAX_N];

bool a1comp(edge a, edge b){
	return a.d>b.d;
}

void dfs(int now, int dist){
	reached[now] = true;
	bool noWay = true;
	for (int i = 0; i < G[now].size(); i++){
		if (!reached[G[now][i].to]){
			noWay = false;
			break;
		}
	}
	if (noWay){
		mx = max(mx,dist);
		return;
	}
	for (int i = 0; i < G[now].size(); i++){
		if (!reached[G[now][i].to]){
			reached[G[now][i].to] = true;
			dfs(G[now][i].to, dist + G[now][i].d);
			reached[G[now][i].to] = false;
		}
	}
}


int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int from,to; edge e;
	for (int i = 1; i <= n-1; i++){
		scanf("%d%d%d",&from,&to,&e.d);
		if (from != 1) allA1 = false;
		if (from != to - 1) allAB = false;
		e.to = to;
		Ga1[++edgeCnt] = e;
		G[from].push_back(e);
		e.to = from;
		G[to].push_back(e);
	}
	if (allA1){
		sort(Ga1+1,Ga1+1+edgeCnt,a1comp);
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				if (i == j) continue;
				sums.push(Ga1[i].d+Ga1[j].d);
			}
		}
		int ans;
		while (m){
			m--;
			ans = sums.top(); sums.pop();
		}
		printf("%d",ans);
	} else if (allAB){
		sum[0] = sum[1] = 0;
		for (int i = 1; i <= n; i++){
			if (G[i][0].to = i+1)
			sum[i] = G[i][0].d + sum[i-1];
			else
			sum[i] = G[i][1].d + sum[i-1];
			//printf("G[%d][0] = %d\n",i-1,G[i-1][1].d);
		}
		long long mx233 = ll(-0x3f3f3f3f);
		//for (int i = 1; i <= n+1; i++){
			//cout<<"sum["<<i<<"] = "<<sum[i]<<endl;
		//}
		for (int i = 1; i <= n; i++){
			int a = sum[i], b = sum[n] - sum[i+1];
			ll temp = ll(min(a,b));
			mx233 = max(mx233,temp);
		}
		cout<<mx233<<endl;
	} else{
		for (int i = 1; i <= n; i++){
			dfs(i,0);
		}
		printf("%d",mx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
