#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, d[100005];
long long ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (register int i=1; i<=n; ++i) scanf("%d", &d[i]);
	d[0]=0;
	for (register int i=1; i<=n; ++i)
		if (d[i] > d[i-1]) ans+=d[i]-d[i-1];
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

