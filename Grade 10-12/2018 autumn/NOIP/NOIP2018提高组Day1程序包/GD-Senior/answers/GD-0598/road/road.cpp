#include<cstdio>
#include<cstdlib>
#include<cstring>
int n;
int a[111010];
long long ans=0;
int t;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (t<a[i]) ans=ans+a[i]-t;
		t=a[i];
	}
	printf("%lld\n",ans);
}
/*
6
4 3 2 5 3 5
*/
