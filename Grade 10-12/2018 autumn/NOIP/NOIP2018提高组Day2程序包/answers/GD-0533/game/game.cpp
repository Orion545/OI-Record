#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, ans, mo = 1e9 + 7;
bool mz[10][10];
int la = 0;

bool Check (int ux, int uy, int sum) {
	if (ux == n && uy == m) {
		sum += mz[ux][uy];
		if (sum <= la) { 
			la = sum;
			return true;
		} else return false;
	}
	int dx, dy;
	dx = ux + 1; dy = uy;
	if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) if (!Check(dx, dy, sum + mz[dx][dy])) return false;
	dx = ux; dy = uy + 1;
	if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) if (!Check(dx, dy, sum + mz[dx][dy])) return false;
	return true;
}

void Dfs (int ux, int uy) {
	if (ux > n) {
		la = 2e9;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) printf("%d ", mz[i][j]);
//			cerr<<endl;
//		}
//		cerr<<endl;
		if (Check(1, 1, 0)) ans = (ans + 1) % mo;
		return;	
	}
	if (uy > m) {
		Dfs(ux + 1, 1);
		return;
	}
	mz[ux][uy] = 0;
	Dfs(ux, uy + 1);
	mz[ux][uy] = 1;
	Dfs(ux, uy + 1);
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	Dfs(1, 1);
	printf("%d", ans % mo);
	
	return 0;
}
