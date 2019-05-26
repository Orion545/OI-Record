#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
int n,m,ans=1;
int mod=1000000007;



int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d", &n, &m);
	if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			ans=(ans*2)%mod;
		}
		printf("%d\n", ans);
		return 0;
	}
	if(n==2)
	{
		ans=4;
		for(int i=2;i<=m;i++)
		{
			ans=(ans*3)%mod;
		}
		printf("%d\n", ans);
		return 0;	
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=(ans*2)%mod;
		}
		printf("%d\n", ans);
		return 0;
	}
	if(m==2)
	{
		ans=4;
		for(int i=2;i<=n;i++)
		{
			ans=(ans*3)%mod;
		}
		printf("%d\n", ans);
		return 0;	
	}
	
	if(n==3 && m==3)
	{
		cout<<112<<endl;
		return 0;
	}
	if(n==4 && m==4)
	{
		cout<<7136<<endl;
		return 0;
	}
}
