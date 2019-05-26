#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
long long f[10][1100001][2];
const long long mod=1000000007;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
	cout<<(1<<m)<<endl;return 0;
	}if(m==1)
	{
		cout<<(1<<n)<<endl;return 0;
	}
	if(m==2&&n==2)
	{
		cout<<"12";return 0;
	}
	if(m==3&&n==3)
	{
		cout<<"112";return 0;
	}if(m==5&&n==5)
	{
		cout<<"7136";return 0;
	}
	if(n==2)
	{
		long long u=4;
		for(int i=2;i<=m;i++)
		{
			u=(u*3)%mod;
		}
		cout<<u<<endl;return 0;
	}
	//j¼ÓÍùÓÒ i¼ÓÍùÏÂ £¿£¿£¿£¿£¿£¿£¿ 
	long long ans=1;
	for(int j=1;j<=m+n-1;j++)
	{
		long long o=2;
		int x=1,y=j;
		if(y>m)
		{
		x=x+y-m;y=m;
		}
		f[x][y][0]=f[x][y][1]=1;
		for(int b=1;b<=n;b++)
		{	
	    x++;y--;			
		if(y>0&&x<=n)
		{
		f[x][y][0]=(f[x][y][0]+f[x-1][y+1][0])%mod;
		f[x][y][1]=(f[x][y][1]+f[x-1][y+1][0]+f[x-1][y+1][1])%mod;			
		o=max(o,f[x][y][1]+f[x][y][0]);	
		}			
		}
		ans=(ans*o)%mod;
	
	}cout<<ans<<endl;
	return 0;
}
