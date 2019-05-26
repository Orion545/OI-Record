#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int n=0;
int m=0;
char type[2];

long long p[100005];
int deep[100005];
vector<int> road[100005];
queue<int> q;

long long dp[100005][2];

int mustbe[100005]; // 0 = any, 1 = mustbe, 2 = mustnot

long long inf = 1e12;

int par[100005];

void setdeep(){
	while (!q.empty())q.pop();
	q.push(1);
	deep[1] = 1;
	while (!q.empty()){
		int inow = q.front();
		for (int i = 0; i < road[inow].size(); i++){
			int nxt = road[inow][i];
			if (deep[nxt] > 0)continue;
			deep[nxt] = deep[inow] + 1;
			par[nxt] = inow;
			q.push (nxt);
		}
		q.pop();
	}
}

long long work (int inow, int state){
	long long tota = p[inow]; //inow you
	long long totb = 0; // inow meiyou
	for (int i = 0; i < road[inow].size(); i++){
		int nxt = road[inow][i];
		if (deep[nxt] < deep[inow])continue;
		
		long long x = 0; // nxt you
		long long y = 0; // nxt meiyou
		if (dp[nxt][1] == -1){
			x = work (nxt, 1);
		}else{
			x = dp[nxt][1];
		}
		
		if (dp[nxt][0] == -1){
			y = work (nxt, 0);
		}else{
			y = dp[nxt][0];
		}
		
//		if (mustbe[nxt] == 0){
			tota += min (x, y);
			totb += x;
//		}else if (mustbe[nxt] == 1){
//			tota += x;
//			totb += x;
//		}else if (mustbe[nxt] == 2){
//			tota += y;
//			totb = inf;
		//}
	}
	if (state == 1){
		//if (inow == 3)printf ("%d", mustbe[3]);
		if (mustbe[inow] == 2){
			dp[inow][1] = inf;
			//if (inow == 3)printf ("fuck2\n");
			return inf;
		}else{
			dp[inow][1] = tota;
			//if (inow == 3)printf ("fuck\n");
			return dp[inow][1];
			
		}
	}else{
		if (mustbe[inow] == 1){
			dp[inow][0] = inf;
			return inf;
		}else{
			dp[inow][0] = totb;
			return dp[inow][0];
		}
	}
}

void killpar (int inow){
	//printf ("%d ", inow);
	dp[inow][0] = -1;
	dp[inow][1] = -1;
	if (par[inow] != -1)killpar (par[inow]);
}

int main (){
	freopen ("defense.in", "r", stdin);
	freopen ("defense.out", "w", stdout);
	
	scanf ("%d %d", &n, &m);
	char ccc = 'a';
	scanf ("%s", type);
	
	for (int i = 0; i <= n; i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
		mustbe[i] = 0;
		par[i] = -1;
	} 
	
	for (int i = 1; i <= n; i++){
		scanf ("%lld", &p[i]);
	}
	
	for (int i = 0; i < n-1; i++){
		int a=0;
		int b=0;
		scanf ("%d %d", &a, &b);
		road[a].push_back(b);
		road[b].push_back(a);
	}
	
	for (int i = 0; i <= n; i++){
		deep[i] = -1;
	}
	
	setdeep();
	par[1] = -1;
	//printf ("%d &&", par[4]);
	long long ans = min (work(1, 1), work (1, 0));
	for (int i = 0; i < m; i++){
		int a=0,x=0,b=0,y=0;
		scanf ("%d %d %d %d", &a, &x, &b, &y);	
		
		if (x==0)mustbe[a] = 2;
		else mustbe[a] = 1;
		if (y==0)mustbe[b] = 2;
		else mustbe[b] = 1;
		
		//killpar (a);
		//killpar (b);
		for (int i = 0; i <= n; i++){
			dp[i][0] = -1;
			dp[i][1] = -1;
		}
		
		if (mustbe[1] == 0){
			ans = min (work(1, 1), work (1, 0));
		}else if (mustbe[1] == 1){
			ans = work (1,1);
		}else {
			ans = work (1, 0);
		}
		
		if (ans >= inf){
			printf ("-1\n");
		}else{
			printf ("%lld\n", ans);
		}
		
		mustbe[a] = 0;
		mustbe[b] = 0;
		
		//for (int i = 0; i <= n; i++){
	//		printf ("%d %lld %lld\n", i, dp[i][0], dp[i][1]);
		//}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
