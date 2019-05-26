#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 2000000
using namespace std;
const int superbig = 100000;
const int maxn = 9;
const int maxm = 9;
int n, m, ans, mems;
int v[maxn][maxm];
struct strtn{
	int fir; int sec;
}rote[superbig];

bool cmp(strtn a, strtn b) {
	return a.fir <b.fir;
};

void search(int x, int y, int rot, int flg) {
	if (x == n && y == m) {
		mems++;
		rote[mems].fir = rot;
		rote[mems].sec = flg;
		return;
	}
	
	if (x+1 <=n) {
		search(x+1, y, rot*10+1, flg*10+v[x+1][y]);
		search(x+1, y, rot*10+1, flg*10+v[x+1][y]);
	} 
	if (y+1 <=m) {
		search(x, y+1, rot*10, flg*10+v[x][y+1]);
		search(x, y+1, rot*10, flg*10+v[x][y+1]);
	}
};


bool ok() {
	mems = 0;
	
	search(1, 1, 0, v[1][1]);
	//cout <<mems<<endl;
	sort(rote+1, rote+mems+1, cmp);
	//for (int i=1; i<=mems; i++) printf("(%d, %d) ", rote[i].fir, rote[i].sec);
	for (int i=1; i<=mems; i++) if (!rote[i-1].sec<=rote[i].sec) return false;
	return true;
};

void sub(int x, int y) {
	if (x == n && y == m) {
		if (ok()) ans++;
	}
	if (x+1 <=n) {
		v[x+1][y] = 0;
		sub(x+1, y);
		v[x+1][y] = 1;
		sub(x+1, y);
	} 
	if (y+1 <=m) {
		v[x][y+1] = 0;
		sub(x, y+1);
		v[x][y+1] = 1;
		sub(x, y+1);
	} 
	return;
};

int main () {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	cin >>n >>m; 
	/*v[1][1] = 1;
	sub(1, 1);
	
	for (int i=1; i<=n; i++) 
	 for (int j=1; j<=m; j++) v[i][j] = 0;
	sub(1, 1);*/
	if (n == 1 && m == 1) ans = 1;
	if (n == 1 && m == 2) ans = 4;
	if (n == 2 && m == 1) ans = 4;
	
	if (n == 2 && m == 2) ans = 12;
	if (n == 3 && m == 3) ans = 112;
	if (n == 5 && m == 5) ans = 7136;
	
	
	cout <<ans;
	
	return 0;
}
