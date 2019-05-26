#include<cstdio>
using namespace std;
long long n,x[100100];
int main()
{
	freopen("road.in","r",stdin);                               
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
	long long ans=x[1];
	for (int i=2;i<=n;i++) if (x[i]>x[i-1]) ans+=x[i]-x[i-1];
	printf("%lld",ans);
	return 0;
}
