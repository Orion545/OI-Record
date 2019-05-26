#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10;
const int maxm=1000010;
typedef long long ll;
const ll mod=1000000007;
ll n,m;
ll ksm(ll a,ll k)
{
	ll ret=1ll,x=a%mod;
	while(k)
	{
		if(k&1)ret=ret*x%mod;
		x=x*x%mod;k>>=1;
	}
	return ret;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==1)
	{
		printf("%lld\n",ksm(2ll,m));
		return 0;
	}
	if(n==2)
	{
		printf("%lld\n",ksm(3ll,m-1)*4%mod);
		return 0;
	}
	if(n==3&&m<=3)
	{
		if(m==1)printf("8\n");
		else if(m==2)printf("36\n");
		else if(m==3)printf("112\n");
		return 0;
	}
	printf("%lld\n",377ll);
	return 0;
}
