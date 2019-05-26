#include <cstdio>
#include <iostream>
#include <algorithm>
#define INF 20009
using namespace std;
const int maxn = 100002;
long long ans;
int n, d[maxn];
bool ok;

void search (int l, int r) {
	//printf("searching: %d~%d\n", l, r);///////
	ok = 1;
	int lef = l;
	while (lef<=r) {
		if (d[lef] != 0) {
			ok = 0;
			int strt = lef, ending = lef;
			for (int ed=lef; ed<=r+1; ed++) {
				if (d[ed] == 0) {
					ending = ed-1;
					break;
				}
			}
			lef = ending;
			ending;
			
			//for (int i=1; i<=n; i++) cout <<d[i]<<" ";
			//cout <<endl;//////////////
			
			int mini = INF;
			for (int i=strt; i<=ending; i++) mini = min(mini, d[i]);
			ans +=mini;
			//printf("l=%d, r=%d, min=%d\n", strt, ending, mini);///////
			for (int i=strt; i<=ending; i++) d[i] -= mini;
			//SegTree better?
			search(strt, ending);
		}
		lef++;
	}
	
	return;
};

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >>n; 
	for (int i=1; i<=n; i++) cin >>d[i];
	
	int lpos = 1;
	ans = 0;
	for (int i=1; i<=n+1; i++) {
		if (d[i] == 0) {
			search(lpos, i-1);
			lpos = i+1;
			
		}
	}
	cout <<ans;
	
	return 0;
}
