#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],sum[100005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=n+1;++i) sum[i]=a[i]-a[i-1];
	for (int i=1;i<=n;++i) if (sum[i]>0) ans+=sum[i];
	printf("%d\n",ans);
	return 0;
}
