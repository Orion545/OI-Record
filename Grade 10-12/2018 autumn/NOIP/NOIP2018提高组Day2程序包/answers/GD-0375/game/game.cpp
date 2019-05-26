#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;

const ll mo=1e9+7;
int i,n,m;
ll ans;

ll fpow(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1)
	{
		if(y&1) (ans*=x)%=mo;
		(x*=x)%=mo;
	}
	return ans;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==1)
	{
		printf("%lld",fpow(2,m));
		return 0;
	}
	if(n==2)
	{
		printf("%lld",4ll*fpow(3,m-1)%mo);
		return 0;
	}
	fo(i,3,m-2) (ans+=2*fpow(3,m-i+1)*fpow(4,i-2))%=mo;
	(ans+=fpow(3,m-3)*16)%=mo;
	if(m>3) (ans+=fpow(3,m-3)*16)%=mo;
	(ans+=12)%=mo;
	printf("%lld",ans*4%mo);
}
