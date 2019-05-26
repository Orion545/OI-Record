#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,x,d=0,ans=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		if(x>d)ans+=x-d;
		d=x;
	}
	printf("%d\n",ans);
	return 0;
}
