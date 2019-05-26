#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,a[100005];
long long ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	a[n+1]=0;
	for (i=1; i<=n; i++) 	
		scanf("%d",&a[i]);
	for (i=2; i<=n+1; i++)
		if (a[i]<a[i-1]) ans+=(a[i-1]-a[i]);
	printf("%d\n",ans);
	return 0;
}
