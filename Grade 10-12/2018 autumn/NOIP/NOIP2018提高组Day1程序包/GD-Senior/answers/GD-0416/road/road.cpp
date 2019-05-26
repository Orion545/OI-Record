#include<cstdio>
#define LL long long
using namespace std;
int n,x=0;
LL ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,a;i<=n;i++)
	{
		scanf("%d",&a);
		if(a>x) ans+=a-x;
		x=a;
	}
	printf("%lld",ans);
	return 0;
}
