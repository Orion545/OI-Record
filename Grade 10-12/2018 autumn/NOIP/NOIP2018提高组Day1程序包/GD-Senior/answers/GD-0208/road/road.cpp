#include<iostream>
#include<stdio.h>
using namespace std;
int i,j,k,l,n,m,x,y,a[100050],f[100050];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]!=0)
		if(a[i]>a[i-1]) 
		{
			k++;
			f[k]=a[i]-a[i-1];
		}
	}
	for(i=1;i<=k;i++)  ans=ans+f[i];
	printf("%lld",ans);
	return 0;
}
