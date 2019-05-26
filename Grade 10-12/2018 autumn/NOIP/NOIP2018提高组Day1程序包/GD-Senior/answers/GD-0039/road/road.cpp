#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0;
	int n,m,zhongzhuang=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&m);
		if(m>zhongzhuang)
		{
			ans+=m-zhongzhuang;
		}
		zhongzhuang=m;
	}
	printf("%lld",ans);
	return 0;
}
