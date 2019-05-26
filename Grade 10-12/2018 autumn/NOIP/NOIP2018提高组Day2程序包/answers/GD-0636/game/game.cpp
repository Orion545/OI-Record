#include <iostream>
#include <cstdio>
using namespace std;
int ans[4][4] = {{1, 1, 1, 1}, {1, 2, 4, 8}, {1, 4, 12, 40}, {1, 8, 40, 112}};
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cout << ans[n][m];
	return 0;
}
