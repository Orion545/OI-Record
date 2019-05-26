#include<cstdio>
#include<iostream>
using namespace std;
int n,a[100010];
int minn=0,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i-1]<a[i])
		if(minn<a[i])
		{
			ans+=a[i]-minn;
		}
		minn=a[i];
	}
	printf("%d",ans);
}
