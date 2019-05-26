#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define endl '\n'
#define ll long long
using namespace std;
ll p=1e9+7;
ll n,m;
ll cf[8000052];
ll dp[80005][278];
inline bool check(ll a,ll b)
{
	register ll i,j;
	while(a&&b)
	{
		i=a%2;j=b%2;
		if(i>j) return true;
		a=a/2,b=b/2;
	}
	if(a>b) return true;
	return false;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	register ll a,b,c,d,s,ss;
	cin>>n>>m;
	ll S=(1ll<<n);
	for(a=0;a<S;a++)
	dp[0][a]=1;
	for(a=0;a<m;a++)
	{
		for(s=0;s<S;s++)
		{
			for(ss=0;ss<S;ss++)
			{
				ll tmp=s%(1<<(n-1));
				if(check(tmp,(ss/2))) continue;
				dp[a+1][ss]=(dp[a+1][ss]+dp[a][s])%p;
			}
		}
	}
	ll ans=0;
	for(a=0;a<S;a++)
	{
		ans=(ans+dp[m-1][a])%p;
	}
	cout<<ans<<endl;
	return 0;
}
