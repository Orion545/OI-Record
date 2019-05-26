#include<bits/stdc++.h>

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))

using namespace std;

typedef long long ll;

const int N=10;
const int M=1000005;
const ll mods=1e9+7;
int n,m;
ll sum;

ll find(int n,int m)
{
	int yu=imin(n,m); ll ans=1ll;
	for(int i=1;i<yu;++i)
	{
		if(i+1!=3) ans=(ans*((i+1)%mods))%mods;
		ans=(ans*((i+1)%mods))%mods;
	}
	int yc=imax(n,m);
	for(int i=1;i<=yc-yu+1;++i) ans=(ans*((yu+1)%mods))%mods;
	return ans;
}

ll Pow(ll a,int b)
{
	ll s=1ll,x=2ll;
	for(;b;b>>=1,x=x<<1)
	if(b&1) s=s*x%mods;
	return s;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	sum=find(n,m);
	if(n>=3 && m>=3)
	{
		sum=4ll*(Pow(2,(n-1)*(m-1))-Pow(2,imin(n-1,m-1)*2+1))%mods;
		sum=(sum+find(n,m))%mods;
	}
	printf("%lld\n",sum);
	return 0;
}
