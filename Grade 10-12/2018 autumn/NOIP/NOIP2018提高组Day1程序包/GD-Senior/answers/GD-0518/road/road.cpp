#include <cstdio>
using namespace std;
const int N=100005;
int n;
int a[N],d[N];
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
		if (d[i]>=0)
			ans+=d[i];
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
