#include<bits/stdc++.h>
using namespace std;
int n,a[100010],i,j;
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) if(a[i]-a[i-1]>0) ans+=a[i]-a[i-1];
	printf("%lld\n",ans);
	return 0;
}
