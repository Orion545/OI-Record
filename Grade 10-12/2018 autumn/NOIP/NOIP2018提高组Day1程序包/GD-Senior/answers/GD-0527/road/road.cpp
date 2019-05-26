#include<cstdio>
using namespace std;
int n,i,a[200001],f[200001];
int main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	f[1]=a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])f[i]=f[i-1];else f[i]=f[i-1]+a[i]-a[i-1];
	}
	printf("%d\n",f[n]);
}
