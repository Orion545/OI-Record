#include<list>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define int long long
using namespace std;
const int mod=1000000007;
int f[10][1000005],n,m;
int qpow(int a,int b,int c)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%c;
		}
		a=a*a%c;
		b>>=1;
	}
	return ans;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		printf("%lld",qpow(2,m,mod));
	}
	else if(n==2)
	{
		printf("%lld",((4%mod)*qpow(3,m-1,mod)));
	}
	return 0; 
}
