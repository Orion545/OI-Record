#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int a[110000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])ans+=a[i-1]-a[i];
	}
	printf("%d\n",ans+a[n]);
	return 0;
}
