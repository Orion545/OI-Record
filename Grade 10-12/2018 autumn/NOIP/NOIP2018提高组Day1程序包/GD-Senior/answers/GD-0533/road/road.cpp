#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, a[100005], f[100005], g[100005];
long long ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	g[0] = a[0];
	for (int i = 1; i < n; i++) {
		f[i] = min(a[i], f[i - 1] + g[i - 1]);
		g[i] = a[i] - f[i];		
	}
	
	for (int i = 0; i < n; i++) ans += (long long)g[i];
	
	printf("%lld", ans);
	
	return 0;
}
