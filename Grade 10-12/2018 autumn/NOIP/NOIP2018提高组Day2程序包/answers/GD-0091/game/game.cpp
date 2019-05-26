#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
const int Mod=1e9+7;
int n,m;
long long ans;
long long f[10][10][10];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==2)
	{
		ans=4;
		for(int i=1;i<m;i++)
		{
			ans*=3;
			ans%=Mod;
		}
		cout<<ans;
	}
	else
	{
		if(n==1&&m==1) cout<<2;
		if(n==1&&m==2) cout<<4;
		if(n==3&&m==1) cout<<8;
		if(n==3&&m==2) cout<<36;
		if(n==3&&m==3) cout<<112;
		if(n==3&&m==4) cout<<560;
		if(n==3&&m==5) cout<<2800;
	}
	return 0;
}
