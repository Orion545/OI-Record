#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100005;
int n, d[N], res;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &d[i]);
	
	res = d[1];
	for (int i = 2; i <= n; i ++)
		if ( d[i]>d[i-1] ) res += d[i]-d[i-1];

	printf("%d", res);
	
	return 0;
}
