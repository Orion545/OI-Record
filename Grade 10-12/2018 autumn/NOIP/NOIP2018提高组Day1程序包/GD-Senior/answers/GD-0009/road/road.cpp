#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000000+2000
long long n,ans;
long long d[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld\n",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	for(long long i=1;i<=n;i++)
		if(d[i]>d[i-1])
			ans+=d[i]-d[i-1];
	printf("%lld",ans);
}
 
