#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=256,p=1e9+7;
typedef long long ll;
int n,m,ans,i,j;
inline int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(ll)ans*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1)
	{
		printf("%d",ksm(2,m));
		return 0;
	}
	if (n==2)
	{
		ans=ksm(3,m-1);
		ans=(ll)ans*4%p;
		printf("%d",ans);
		return 0;
	}
	if (n==3)
	{
		ans=ksm(3,m-3);
		ans=(ll)ans*112%p;
		printf("%d",ans);
		return 0;
	}
	if (n==4)
	{
		if (m==4)
		{
			printf("912");
			return 0;
		}
		ans=ksm(3,m-5);
		ans=(ll)ans*2688%p;
		printf("%d",ans);
		return 0;
	}
	if (n==5)
	{
		if (m==5)
		{
			printf("7136");
			return 0;
		}
		ans=ksm(3,m-6);
		ans=(ll)ans*21312%p;
		printf("%d",ans);
		return 0;
	}
	if (n==6)
	{
		if (m==6)
		{
			printf("");
			return 0;
		}
		ans=ksm(3,m-7);
		ans=(ll)ans*1%p;
		printf("%d",ans);
		return 0;
	}
	//printf("%d",ans);
}