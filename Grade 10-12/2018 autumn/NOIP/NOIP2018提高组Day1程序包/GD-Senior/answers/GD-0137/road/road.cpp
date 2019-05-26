#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define inf 2147483647
#define N 100003
using namespace std;
int a[N];
int read(){
	int x, f = 1;
	char ch;
	while(ch = getchar(), ch < '0' || ch > '9') if(ch == '-') f = - 1;
	x = ch - 48;
	while(ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - 48;
	return x * f;
}
int work(int l, int r){
	int i, p, minn = inf, ans = 0;
	if(l > r) return 0;
	for(i = l; i <= r; i++){
		if(minn > a[i]) minn = a[i], p = i;
	}
	if(minn == inf) return 0;
	for(i = l; i <= r; i++) a[i] -= minn;
	ans = minn + work(l, p - 1) + work(p + 1, r);
	return ans;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int i, j, n, m;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%d", work(1, n));
	return 0;
}
