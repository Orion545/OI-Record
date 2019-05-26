#include <iostream>
#include <cstdio>
using namespace std;
int n,a[1000008];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%lld",ans);
	return 0;
}
