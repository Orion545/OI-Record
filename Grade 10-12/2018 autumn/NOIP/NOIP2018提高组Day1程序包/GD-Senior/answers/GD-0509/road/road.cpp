#include<bits/stdc++.h>
using namespace std;
struct nw
{
	int ad,d;
}d[100010];
bool cmp(nw x,nw y)
{
	return x.d<y.d;
}
int a[100010],n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d[i].d=a[i];
		d[i].ad=i;
	}
	long long sum=0;
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[d[i].ad]>0)
		{
			for(int j=d[i].ad+1;a[j]>=a[d[i].ad];j++)
				a[j]-=a[d[i].ad];
			for(int j=d[i].ad-1;j&&a[j]>=a[d[i].ad];j--)
				a[j]-=a[d[i].ad];
			sum+=a[d[i].ad];
			a[d[i].ad]=0;
		}
	}
	printf("%d",sum);
}
