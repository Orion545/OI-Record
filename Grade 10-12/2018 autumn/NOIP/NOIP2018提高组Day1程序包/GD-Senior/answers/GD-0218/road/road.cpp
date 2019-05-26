#include <cstdio>
#include <algorithm>
using namespace std;
int d[100005];
int n, i, ans=0;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	for(i=1; i<=n; i++) ans+=max(0, d[i]-d[i-1]);
	printf("%d\n", ans);
	return 0;
}
