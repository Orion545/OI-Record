#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,ans=0,now;
int a[100086];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	now=a[1];ans+=now;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>now)
		{
			ans+=a[i]-now;
			now=a[i];
		}
		else now=a[i];
	}
	printf("%d",ans);
	return 0;
}
