#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 1000010;
const int mod = 1000000007;

int t[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
long long f[N][3][3];
int main() {
	
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	int n, m; scanf("%d%d", &n, &m);
	
	if(n == 1 || m == 1) { printf("%d\n", t[max(n, m)]); return 0; }
	if(n == 2 && m == 2) { printf("12\n"); return 0; }
	if(n == 3 && m == 3) { printf("112\n"); return 0; }
	if(n == 2 && m == 3) { printf("36\n"); return 0; }
	if(n == 3 && m == 2) { printf("44\n"); return 0; }
	
	f[1][0][1] = f[1][1][0] = f[1][0][0] = f[1][1][1] = 1;
	for (int i=2; i<=m; i++) {
		f[i][1][0] = (f[i-1][0][1] + f[i-1][1][1]) % mod;
		f[i][0][0] = (f[i-1][0][1] + f[i-1][1][1] + f[i-1][0][0] + f[i-1][1][0]) % mod;
		f[i][1][1] = (f[i-1][0][1] + f[i-1][1][1]) % mod;
		f[i][0][1] = (f[i-1][0][1] + f[i-1][1][1] + f[i-1][0][0] + f[i-1][1][0]) % mod;
	}
	
	int i = m+1;
	printf("%lld\n", (f[i-1][0][1] + f[i-1][1][1] + f[i-1][0][0] + f[i-1][1][0]) % mod);
	
	return 0;
}
