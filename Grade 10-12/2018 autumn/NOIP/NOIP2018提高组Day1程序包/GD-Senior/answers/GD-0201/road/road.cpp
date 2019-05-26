#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 200005
#define LL long long
using namespace std;
LL n, a[N], d[N], ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]), d[i] = a[i] - a[i-1];
	for(int i = 1; i <= n; i ++) if(d[i] > 0) ans += d[i];
	printf("%lld", ans);
	return 0;
}
