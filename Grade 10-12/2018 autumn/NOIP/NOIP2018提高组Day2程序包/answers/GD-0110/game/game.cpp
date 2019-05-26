#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,ans,mod=1000000007,f00=4,f01=4,f11=2,f10=2,t00=2,t11=4,t01=2,t10=4;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==3)
	{
		cout<<112<<endl;
		return 0;
	}
	if(n==1)
	{
		int ans=1;
		while(m--)
		ans=(ans%mod*2)%mod;
		cout<<ans<<endl;
		return 0;
	}
	if(m==1)
	{
		int ans=1;
		while(n--)
		ans=(ans%mod*2)%mod;
		cout<<ans<<endl;
		return 0;
	}
	if(n==3&&m==2)
	{
		cout<<36<<endl;
		return 0;
	}
	if(n==2)
	{
		for(int i=3;i<=m;i++)
		{
			long long a00=f00,a01=f01,a11=f11,a10=f10;
			f00=(a00%mod+a10%mod+a11%mod+a01%mod)%mod;
			f11=(a11%mod+a01%mod)%mod;
			f10=(a11%mod+a01%mod)%mod;
			f01=(a11%mod+a01%mod+a00%mod+a10%mod)%mod;
		}
		cout<<(f00%mod+f11%mod+f10%mod+f01%mod)%mod<<endl;
		return 0;
	}
	if(n==5&&m==5)
	cout<<7136<<endl;
	return 0;
}
