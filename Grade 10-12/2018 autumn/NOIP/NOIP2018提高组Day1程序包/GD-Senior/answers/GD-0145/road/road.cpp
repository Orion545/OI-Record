#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,a[100005];
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int min1=10001;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		min1=min(min1,a[i]);
	}
	for(int i=1;i<=n;i++)
	  a[i]-=min1;
	ans+=min1;
	int i=2,max1=a[1];
	min1=10001;
	while(i<=n)
	{
		if(a[i]>=a[i-1])
		{
			max1=a[i];
			i++;
		} 
		else
		{
			while(a[i]<a[i-1])
			{
				if(a[i]==0)
				  break;
				min1=a[i];
				i++;
			}
			if(a[i]==0)
			{
				i++;
				ans+=max1;
				max1=a[i];
				continue;
			}
			for(int j=i;j<=n;j++)
			{
			    if(a[j]==0)
			      break;
			    if(a[j]-min1>=0)
			      a[j]-=min1;
			    else
			    {
			    	min1=a[j];
			    	a[j]=0;
			    }
			}
			ans+=max1;
			max1=a[i];
		}
	}
	if(max1==a[n])
	  ans+=max1;
	printf("%lld",ans);
	return 0;
}
