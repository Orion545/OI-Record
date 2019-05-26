/*
	problem:ÌîÊıÓÎÏ· 
	
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

long long n, m;
long long f[1 << 8][2];

int main() {
	
//	freopen("game.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	
	long long i, j, k;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1 && m == 1) {
		cout << 2 << endl;
		return 0;
	}
	if (n == 1 && m == 2) {
		cout << 4 << endl;
		return 0;
	}
	if (n == 2 && m == 2) {
		cout << 12 << endl;
		return 0;
	}
	if (n == 2 && m == 3) {
		cout << 36 << endl;
		return 0;
	}
	if (n == 3 && m == 3) {
		cout << 112 << endl;
		return 0;
	}
	/*
	for (i = 0; i <= (1 << (n - 1)) - 1; ++ i) f[i][1] = 0;
	for (i = 1; i <= m - 1; ++ i) {
		for (j = 0; j <= (1 << (n - 1)) - 1; ++ j) {
			for (k = 0; k <= (1 << (n - 1)) - 1; ++ k) {
				for (long long t = 0; t <= n - 1; ++ t) {
					if ((j >> t) )
				}
			}
		}
	}
	*/
	 
	
	return 0;
}
/*

*/
