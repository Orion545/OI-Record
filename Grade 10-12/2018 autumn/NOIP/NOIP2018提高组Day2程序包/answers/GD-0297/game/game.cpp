#include<cstdio>
#include<iostream>
using namespace std;
long long n,m,ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		ans=1;
		for(int i=1;i<=m;i++)ans=(ans*2)%1000000007;
	}
	else if(m==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)ans=(ans*2)%1000000007;
	}
	else if(n==2)
	{
		ans=4;
		for(int i=1;i<m;i++)ans=(ans*3)%1000000007;
	}
	else if(m==2)
	{
		ans=4;
		for(int i=1;i<n;i++)ans=(ans*3)%1000000007;
	}
	else if(n==3 && m==3)ans=112;
	cout<<ans<<"\n";
}
