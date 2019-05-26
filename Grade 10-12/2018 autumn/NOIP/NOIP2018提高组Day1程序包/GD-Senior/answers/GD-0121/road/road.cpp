#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int ls=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>ls)
		{
			ans+=a[i]-ls;
		}
		ls=a[i];
	}
	printf("%lld",ans);
	return 0;
}
