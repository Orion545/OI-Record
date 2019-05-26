#include<cstdio>
int a[100010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long ans=0;
	for (int i=1;i<=n+1;i++)
		if (a[i]-a[i-1]>=0) ans+=a[i]-a[i-1]; 
	printf("%lld\n",ans);
	return 0;
}

