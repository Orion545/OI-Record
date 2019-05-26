#include<cstdio>
using namespace std;
int i,n;
long long ans,x,y;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1,ans=0;i<=n;++i)
	{
		scanf("%lld",&x);
		if(x>y) ans+=x-y;
		y=x;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
