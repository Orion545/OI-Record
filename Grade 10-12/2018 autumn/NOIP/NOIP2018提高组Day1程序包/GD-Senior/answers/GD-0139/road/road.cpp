#include <bits/stdc++.h>
#define N 200200
using namespace std;

int n, a[N], d[N];
long long ans;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<=n+1;i++) d[i] = a[i] - a[i-1];
	for (int i=1;i<=n+1;i++) ans += ((d[i] > 0) ? d[i] : -d[i]);
	printf("%lld\n",ans/2);
}
