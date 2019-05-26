#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int n =0, m=0;
struct road{
	int tar;
	long long val;
};
vector <road> rd[50005];

int deep[50005];

road r;

long long dp[50005][2];
long long emm[50005];

queue<int> q;

bool comp (long long a, long long b){
	return a > b;
}

long long work (int inow){
	long long maxof = 0;
	long long smax = 0;
	
	bool did = false;

	for (int i = 0; i < rd[inow].size(); i++){
		int nxt = rd[inow][i].tar;
		if (deep[nxt] <= deep[inow])continue;
		did = true;
		//if (inow == 2)printf ("%lld %lld %d\n", smax, maxof, nxt);
		if (dp[nxt][0] != -1){
			//printf ("%lld ", rd[inow][nxt].tar);
			if (dp[nxt][0] + rd[inow][i].val > maxof){
				smax = maxof;
				maxof = dp[nxt][0] + rd[inow][i].val;
			}else{
				smax = dp[nxt][0] + rd[inow][i].val;
			}
		}else{
			long long summ = 0;
			summ = work(nxt) + rd[inow][i].val;
			if (summ > maxof){
				smax = maxof;
				maxof = summ;
			}else{
				smax = summ;
			}
		}
	}
	
	if (!did){
		dp[inow][0] = 0;
		dp[inow][1] = 0;
		return 0;
	}
	dp[inow][0] = maxof;
	dp[inow][1] = maxof + smax;
	//printf ("%lld %lld\n", maxof, smax);
	return maxof;
}

int main (){
	freopen ("track.in", "r", stdin);
	freopen ("track.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	
	bool allone = true;
	for (int i = 0; i < n-1; i++){
		int a=0,b=0;
		long long c=0;
		scanf ("%d %d %lld", &a, &b, &c);
		if (a != 1)allone = false;
		r.tar = b;
		r.val = c;
		rd[a].push_back(r);
		
		r.tar = a;
		rd[b].push_back(r);
		//printf ("%lld ", rd[b][rd[b].size() - 1].val);
	}
	
	while (!q.empty()){
		q.pop();
	}

	deep[1] = 0;
	q.push(1);

	while (!q.empty()){
		int inow = q.front();
		for (int i = 0; i < rd[inow].size(); i++){
			//printf ("!");
			if (deep[rd[inow][i].tar] != 0 || rd[inow][i].tar == 1)continue;
			//printf ("@");
			deep[rd[inow][i].tar] = deep[inow]+1;
			q.push(rd[inow][i].tar);
		}
		q.pop();
	}
	
	if (m == 1){
		long long ans = work (1);
		for (int i = 1; i <= n; i++){
			ans = max (ans, dp[i][1]);
			emm[i] = dp[i][1];
		}
		printf ("%lld", ans);
	}else{
		long long ans = work(1);
		for (int i = 1; i <= n; i++){
			emm[i] = dp[i][1];			
		}
		sort (emm, emm + n + 1, comp);
		for (int i = 1; i <= n; i++){
			//printf ("%lld", emm[i]);			
		}
		printf ("%lld", emm[m-1]); 
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
