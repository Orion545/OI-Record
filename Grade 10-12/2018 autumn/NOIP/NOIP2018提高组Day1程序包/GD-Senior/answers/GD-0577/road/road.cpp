#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
	int n,ans=0;
int main()
{
	int x,y=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>y) ans+=x-y;
		y=x;
	}
	printf("%d",ans);
	return 0;
}
