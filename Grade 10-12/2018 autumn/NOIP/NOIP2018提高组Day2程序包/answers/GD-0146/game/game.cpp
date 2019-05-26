#include<cstdio>
using namespace std;
const int mod=1000000007;
int n,m,ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.ans","w",stdout);
	scanf("%d%d",&n,&m);
	int sum=1;
	for(int i=3;i<=n+1;i++)
	sum=((sum%mod)*(i%mod))%mod;
	ans=(ans%mod+sum%mod)%mod;
	for(int j=n-1;j>=2;j--)
	{
		sum=1;
		for(int i=3;i<=n+1;i++)
		if(i==j+1)
		sum=((sum%mod)*(j%mod))%mod;
		else
		sum=((sum%mod)*(i%mod))%mod;
		sum=((sum%mod)*(j%mod))%mod;
		ans=(ans%mod+sum%mod)%mod;
	}
	ans=(ans*4)%mod;
	printf("%d",ans);
	return 0;
}
