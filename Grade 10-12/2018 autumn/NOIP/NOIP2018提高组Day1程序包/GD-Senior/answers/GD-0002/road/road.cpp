#include <cstdio>
#include <cstring>
#define ll long long

ll ans=0;
int n,a[100010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	a[0]=0;
	for(int i=1;i<=n;i++)
	if(a[i]>a[i-1])ans+=(ll)(a[i]-a[i-1]);
	printf("%lld",ans);
}
