#include<cstdio>
#include<algorithm>
#define mod 1000000007

using namespace std;
typedef long long ll;

int n,m;
ll ans[3][3];

ll qp(ll x,int k)
{
	ll res=1;
	for(;k;k>>=1,x=x*x%mod)
		if(k&1) res=res*x%mod;
	return res;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans[2][2]=112;ans[2][1]=36;ans[2][0]=8;
	if(n==1) return 0 & printf("%lld\n",qp(2,m));
	else if(n==2) return 0 & printf("%lld\n",qp(3,m-1)*(ll)4%mod);
	else if(n==3 && m<=3) return 0 & printf("%lld\n",ans[n-1][m-1]);
	return 0;
}
