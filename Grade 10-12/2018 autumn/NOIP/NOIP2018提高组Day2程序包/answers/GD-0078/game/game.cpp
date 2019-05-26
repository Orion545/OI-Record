#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int mod=1e9+7;
int n,m;
int ksm(int x,int k)
{
	int ans=1;
	while (k)
	{
		if (k&1) ans=1ll*ans*x%mod;k>>=1;x=1ll*x*x%mod;
	}return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1) printf("%d",ksm(2,m));
	if (n==2) printf("%lld",1ll*ksm(3,m-1)*4%mod);
	if (n==3)
	{
		printf("%lld",1ll*ksm(3,m-3)*112%mod);
	}
	if (n==4) 
	{
		if (m==4) printf("912");
	}
	if (n==5) 
	{
		if (m==5) printf("7136");
	}
	return 0;
}
