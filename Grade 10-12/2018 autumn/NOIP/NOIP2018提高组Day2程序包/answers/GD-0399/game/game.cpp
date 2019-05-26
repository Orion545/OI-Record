#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;

int n,m;

inline ll qpow(ll a,ll x){ll ans=1;for(;x>0;x>>=1,a=a*a%mod) if(x&1) ans=ans*a%mod;return ans;}

ll f[maxn],g[maxn];

void dp()
{
	int i;
	
	f[1]=4;
	for(i=2;i<=n-2;i++)
	{
		f[i]=(f[i-1]+3*qpow(4,i-1))%mod;
	}
	
	g[1]=3;
	for(i=2;i<=m-2;i++)
	{
		if(m-2-i+4<=n) g[i]=(g[i-1]+3*qpow(4,i-m-2-n+4)%mod*qpow(3,m-2-n+4-1))%mod;
		else           g[i]=(g[i-1]+2*qpow(3,i-1))%mod;
	}
}

void solve2()
{
	int i;
	
	f[1]=2;
	for(i=2;i<=m;i++)
	{
		f[i]=(f[i-1]+4*qpow(3,i-2))%mod;
	}
	printf("%lld\n",f[m]*2%mod);
	exit(0);
}

void solve()
{
	ll fans=0;
	
	if(n==1) {cout<<qpow(2,m);exit(0);}
	if(n==2) solve2();
	
	dp();
	
	fans+=2*2*qpow(4,n-2)%mod*qpow(3,m-n)%mod*qpow(2,n-1)%mod;//nodif at first two
	fans+=2*f[n-2]*qpow(3,m-n)%mod*qpow(2,n-2)%mod;//100
	fans+=2*g[m-2]*qpow(2,n-2)%mod;//110
	if(n!=3) fans+=2*2*5*qpow(4,n-4)%mod*qpow(3,m-n)%mod*qpow(2,n-1)%mod;
	else     fans+=2*2*(m==3?2:4*qpow(3,m-n-1))*4%mod;
	
	printf("%lld\n",fans%mod);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	dp();
	solve();
	
	return 0;
}
