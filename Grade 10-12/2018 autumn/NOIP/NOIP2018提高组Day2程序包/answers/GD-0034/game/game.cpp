#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
inline int readin()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
int n,m;
ll mo=1e9+7,ans=0;
ll pow1(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%mo;
		x=x*x%mo;
		y>>=1;
	}
	return ret;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=readin(),m=readin();
	if(n==1)
	{
		ans=pow1(2,m);
	}
	else if(n==2)
	{
		ans=pow1(3,m-1);
		ans=ans*4%mo;
	}
	else if(n==3)
	{
		for(int i=2;i<=m-1;i++)
		{
			if(i==2) ans=(ans+4*4*pow1(3,m-i-1)*2*2)%mo;
			else ans=(ans+4*4*pow1(3,m-i)*2)%mo;
		}
		ans=(ans+4*4*3)%mo;//all not forced
	}
	printf("%lld\n",ans);
}
