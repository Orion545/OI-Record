#include <cstdio>
using namespace std;
#define N 100050
int n,i,a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for (i=1;i<=n;i++) if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	printf("%d\n",ans);
	return 0;
}
