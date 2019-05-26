#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int n20 = 30002;
int vis[n20];
int n, m, tweight;
struct tree {
	vector<int> nxt, w;
}t[n20];

int search(int pos, int val) {
	int value = val;
	for (int i=0; i<t[pos].nxt.size(); i++) if (vis[t[pos].nxt[i]] == 0){
		vis[t[pos].nxt[i]] = 1;
		value = max(value, search(t[pos].nxt[i], val+t[pos].w[i]));
		vis[t[pos].nxt[i]] = 0;
	}
	return value;
};

int main () {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	//Spe. when m = 1 20%Getty
	
	cin >>n >>m;
	//so m useless
	//oof

	for (int i=1; i<=n; i++) {
		int p1 = 0; 
		int p2 = 0; 
		int weight = 0;
		cin >>p1 >>p2 >>weight;
		
		t[p1].nxt.push_back(p2);
		t[p1].w.push_back(weight);
		
		t[p2].nxt.push_back(p1);
		t[p2].w.push_back(weight);
	}

	int ans = -1;
	for (int i=1; i<=n; i++) {
		tweight = 0;
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		tweight = search(i, 0);
		ans = max(ans, tweight);
	}
	cout <<ans;
	
	return 0;
}
