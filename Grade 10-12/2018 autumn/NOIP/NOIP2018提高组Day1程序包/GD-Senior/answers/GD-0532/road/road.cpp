#include <stdio.h>
#include <string.h>
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0,pre=0,nw,n;
	scanf("%lld",&n);
		while(n--)
			{
				scanf("%lld",&nw);
				if(nw>pre) ans+=nw-pre;
				pre=nw;
			}
		printf("%lld\n",ans);
	return 0;
}
