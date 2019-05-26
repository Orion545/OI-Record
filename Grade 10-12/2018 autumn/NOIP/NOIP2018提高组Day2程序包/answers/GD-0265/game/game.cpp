#include<cstdio>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,m;
inline ll qp(ll p,ll q)
{
	ll ans=1ll;
	while(q)
	{
		if(q&1) ans=ans*p%MOD;
		p=p*p%MOD;
		q>>=1;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	switch(n)
	{
		case 1:printf("%lld",qp(2,m));break;
		case 2:printf("%lld",qp(3,m-1)*4%MOD);break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
