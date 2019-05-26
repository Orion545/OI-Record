/*
	problem:铺设道路
	单调上升序列 
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

long long n;
long long d[100100]; 

int main () {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	long long i, j, k;
	scanf("%lld", &n);
	memset(d, 0, sizeof(d));
	for (i = 1; i <= n; ++ i) scanf("%lld", &d[i]);
	long long low = 0;
	long long high = 0;
	long long ans = 0;
	for (i = 1; i <= n; ++ i) {
		while (d[i + 1] >= d[i]) ++ i;
		ans += d[i] - low;
		low = d[i + 1];
	}
	
	printf("%lld", ans);
	
	
		
	return 0;
}
/*
6
4 3 2 5 3 5

*/
