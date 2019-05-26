#include<cstdio>
#define N 100012
using namespace std;
int f[N],a[N];
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int p=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=-a[i]-p;
		p=-a[i];
	}
	f[n+1]=-p;
	int ans=0;
	for (int i=1;i<=n+1;i++)
	{
		if (f[i]>0) ans+=f[i];
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
