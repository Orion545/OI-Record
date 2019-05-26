#include <iostream>
#include <cstdio>
#include <vector>
#define INF 2000000
using namespace std;
const int maxn  = 5002;
int n, m, h, t, lastt;
bool vis[maxn];
vector<int> rd[maxn];
vector<int> q;

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >>n >>m;
	for (int i=1; i<=m; i++) {
		int p1; 
		int p2;
		cin >>p1 >>p2;
		rd[p2].push_back(p1);
		rd[p1].push_back(p2);
	}
	
	q.push_back(1);
	vis[1] = true;
	h = 0; t = 0;
	lastt = 0;
	while (h<=t) {
		lastt = t-1;
		int mini = INF;
		
		for (int j=0; j<rd[q[t]].size(); j++) if (!vis[rd[q[t]][j]]){
			mini = min(rd[q[t]][j], mini);
		}
		if (mini != INF) {
			q.push_back(mini);
			vis[mini] = true;
			t = q.size()-1;
		} else {
			t = lastt;
		}
		if (q.size() == n) break;

	}
	for (int i=0; i<n; i++) cout <<q[i]<<" ";
	
	return 0;
}
