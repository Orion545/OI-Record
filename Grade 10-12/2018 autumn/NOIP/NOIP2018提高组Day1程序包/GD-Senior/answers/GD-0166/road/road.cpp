#include<cstdio>
using namespace std;
int n,a[100005],sum,min;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	sum=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>a[i-1]) sum+=a[i]-a[i-1];
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
