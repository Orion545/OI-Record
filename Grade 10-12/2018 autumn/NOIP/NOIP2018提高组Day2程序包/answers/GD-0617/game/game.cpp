#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans=0,f[10][1000050]={0},map[10][1000050]={0};
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	f[2][1]=2;
	f[2][2]=12;
	f[1][1]=2;
	if(n==2)
	{
		for(int i=3;i<=m;i++)
			f[2][i]=(f[2][i-1]/2)*2+(f[2][i-1]/2)*4;
		cout<<f[2][m];
		
	}
	if(n==1)
	{
		for(int i=2;i<=m;i++)
			f[1][i]=f[1][i-1]*2;
		cout<<f[1][m];
	}
	return 0;
}
