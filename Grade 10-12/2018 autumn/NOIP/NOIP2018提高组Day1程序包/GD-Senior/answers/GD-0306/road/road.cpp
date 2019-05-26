#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 100010

int d[N],n,ans,h;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  scanf("%d",&d[i]);
	ans=0; h=0;
	for (int i=1;i<=n;i++)
	{
		ans+=max(0,d[i]-h);
		h=d[i];
	}
	printf("%d\n",ans);
	return 0;
}


