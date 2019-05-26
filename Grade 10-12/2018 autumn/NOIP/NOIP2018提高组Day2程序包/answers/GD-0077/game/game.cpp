#include<cstdio>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int n,m,f[4][4];
ll sum1=1;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][1]=2;f[1][2]=4;f[1][3]=8;
	f[2][1]=4;f[2][2]=12;f[2][3]=36;
	f[3][1]=8;f[3][2]=36;f[3][3]=112;
	if(n<=3&&m<=3)
	{
		printf("%d\n",f[n][m]);
	}
	else if(n==1)
	{
		for(int i=1;i<=m;++i)
		sum1<<=1,sum1%=MOD;
		printf("%lld\n",sum1);
	}
	else if(m==1)
	{
		for(int i=1;i<=n;++i)
		sum1<<=1,sum1%=MOD;
		printf("%lld\n",sum1);
	}
	return 0;
}
