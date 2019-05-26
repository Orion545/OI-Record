#include<cstdio>
int d[100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&d[i]);
	long long ans=0;
	int last=0;
	for(int i=0;i<n;i++)
		if(d[i]>last)
		{
			ans+=d[i]-last;
			last=d[i];
		}
		else
			last=d[i];
	printf("%lld",ans);
	return 0;
}