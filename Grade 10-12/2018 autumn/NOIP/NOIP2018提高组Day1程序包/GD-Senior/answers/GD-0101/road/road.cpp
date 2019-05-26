#include<cstdio>
int n,ans,
	x[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (x[i]>x[i-1])
			ans+=x[i]-x[i-1];
	}
	printf("%d",ans);
	return 0;
}
