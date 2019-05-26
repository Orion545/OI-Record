/*
	problem:旅行 
	dfs
	基环外向树 
	
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
long long f[5010][5010];
long long g[5010][5010];
long long walk[5010];
long long father[5010];
long long ring[5010];
long long cnt;
long long ok;

void dfs(long long x) {
	long long i, j, k;
	printf("%lld ", x);
	walk[x] = 1;
	for (k = 1; k <= g[x][0]; ++ k) {
		i = g[x][k];
		if (f[x][i] && !walk[i]) {
			dfs(i);
		}
	}
}
/*
void dfsring(long long x) {
	long long i, j, k;
	printf("%lld ", x);
	walk[x] = 1;
	if (ring[x]) {
		long long l = 100000, r = 100000;
		for (i = 1; i <= n; ++ i) {
			if (f[x][i]) {
				if (ring[i]) {
					if (i < l) {
						r = l;
						l = i;
					}
					else if (i < r) {
						r = i;
					}
				}
				else if (!walk[i]){
					dfs(i);
				}
			}
		}
		long long nxt;
		while (l < r) {
			walk[l] = 1;
			printf("%lld ", l);
			for (i = 1; i <= n; ++ i) {
				if (f[l][i] && !walk[i]) {
					if (ring[i]) {
						nxt = i;
					}
					else {
						dfs(i);
					}
				}
			}
			l = nxt;
		}
		while (r != l) {
			walk[r] = 1;
			printf("%lld ", r);
			for (i = 1; i <= n; ++ i) {
				if (f[r][i]) {
					if (ring[i]) {
						nxt = i;
					}
					else {
						dfs(i);
					}
				}
			}
			r = nxt;
		}
		walk[l] = 1;
		printf("%lld ", l);
		for (i = 1; i <= n; ++ i) {
			if (f[l][i] && !walk[i]) {
				if (ring[i]) {
					nxt = i;
				}
				else {
					dfs(i);
				}
			}
		}
		
		return;
	}
	for (i = 1; i <= n; ++ i) {
		if (f[x][i] && !walk[i]) {
			dfsring(i);
		}
	}
}
*/
void cutring(long long x) {
//	cout << "$$$$$$$" << endl;
	long long i, j, k;
	long long l = 0, r = 0;
	
	for (k = 1; k <= g[x][0]; ++ k) {
		i = g[x][k];
		if (f[x][i] && ring[i]) {
			if (!l) l = i;
			else r = i;
		}
	}
	long long nxt;
	memset(walk, 0, sizeof(walk));
	walk[x] = 1;
	walk[l] = 1;
	walk[r] = 1;
	while (l < r) {
		for (k = 1; k <= g[l][0]; ++ k) {
			i = g[l][k];
			if (f[l][i] && !walk[i] && ring[i]) {
				if (i >= r) {
					f[l][i] = 0;
					f[i][l] = 0;
//					cout << endl << endl << i << ' ' << l << endl;
					return;
				}
				l = i;
				walk[l] = 1;
				break;
			}
		}
	}
}

void findring(long long x) {
	long long i, j, k;
	if (ok) return;
	walk[x] = 1;
	for (k = 1; k <= g[x][0]; ++ k) {
		i = g[x][k];
		if (ok) return;
		if (f[x][i] && !walk[i]) {
			father[i] = x;
			if (ok) return;
			findring(i);
		}
		else if (f[x][i] && walk[i] && father[x] != i) {
			ok = 1;
			ring[i] = 1;
//			cout << i << ' ';
			j = x;
			while (j != i) {
//				cout << j << ' ';
				ring[j] = 1;
				j = father[j];
			}
//			cout << endl;
			cutring(i);
			return;
		}
	}
	if (ok) return;
}

int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	long long i, j, k;
	scanf("%lld%lld", &n, &m);
	memset(f, 0, sizeof(f));
	for (i = 1; i <= m; ++ i) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		f[x][y] = 1;
		f[y][x] = 1;
	}
	for (i = 1; i <= n; ++ i) {
		for (j = 1; j <= n; ++ j) {
			if (f[i][j]) {
				g[i][++ g[i][0]] = j;
			}
		}
	}
	/*
	for (i = 1; i <= n; ++ i) {
		cout << i << " >> ";
		for (j = 1; j <= g[i][0]; ++ j) {
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	if (m == n - 1) {
		memset(walk, 0, sizeof(walk));
		dfs(1);
		return 0;
	}
	if (m == n) {
		memset(walk, 0, sizeof(walk));
		ok = 0;
		father[1] = 0;
		findring(1);
//		cout << ok << endl;
//		for (i = 1; i <= n; ++ i) cout << ring[i] << ' '; cout << endl;
//		for (i = 1; i <= n; ++ i) if (ring[i]) cout << i << ' '; cout << endl;
		memset(walk, 0, sizeof(walk));
//		dfsring(1);
//		cout << f[64][90] << ' ' << f[90][26] << endl;
		dfs(1);
		return 0;
	}
	
	
	
	return 0;
}
/*

*/
