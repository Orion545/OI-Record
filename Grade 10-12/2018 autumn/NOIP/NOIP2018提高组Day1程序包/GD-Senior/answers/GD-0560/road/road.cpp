#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n,a[MAXN];
long long ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int maxn=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>maxn)
		{
			ans+=a[i]-maxn;
			maxn=a[i];
		}
		else
		{
			maxn=min(maxn,a[i]);
		}
	}
	printf("%lld\n",ans);
}
