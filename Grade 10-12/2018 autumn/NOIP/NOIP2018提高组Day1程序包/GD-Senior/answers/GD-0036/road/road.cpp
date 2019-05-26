#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int Maxn = 100010;
void read(int &x) {
	char ch = getchar(); x = 0;
	for(; ch < '0' || ch > '9'; ch = getchar());
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x*10+ch-'0';
}
int a[Maxn], n;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int i, j, k;
	read(n);
	for(i = 1; i <= n; i++) read(a[i]);
	for(i = n+1; i >= 2; i--) a[i] -= a[i-1];
	int ans = 0;
	for(i = 1; i <= n+1; i++) if(a[i] > 0) ans += a[i];
	printf("%d\n", ans);
	return 0;
}
