#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1000000000+7
using namespace std;
int n,m,sum=1;
int mo(int i)
{
	return i%MAXN;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n>m)//n是小的数 
	{
		int tump=n;
		n=m;
		m=tump;
	}
	if(n==1) cout<<mo(2*m);
	if(n==2) 
	{
		for(int i=2;i<=m;++i)
			sum*=3;
		sum*=4;
		cout<<mo(sum);
	}
	if(n==3)
	{
		sum=36;
		for(int i=3;i<=m;++i)
		sum*=4;
		cout<<mo(sum);
	}
	if(n==4)
	{
		sum=2*3*4*4*3*2;
		for(int i=4;i<=m;++i)
		sum*=5;
		cout<<mo(sum);
	}
	if(n==5)
	{
		sum=2*3*4*5*5*4*3*2;
		for(int i=5;i<=m;++i)
		sum*=6;
		cout<<mo(sum);
	}
	if(n==6)
	{
		sum=2*2*3*3*4*4*5*5*6*6;
		for(int i=6;i<=m;++i)
		sum*=7;
		cout<<mo(sum);
	}
	if(n==7)
	{
		sum=2*2*3*3*4*4*5*5*6*6*7*7;
		for(int i=7;i<=m;++i)
		sum*=8;
		cout<<mo(sum);
	}
	if(n==8)
	{
		sum=2*2*3*3*4*4*5*5*6*6*7*7*8*8;
		for(int i=8;i<=m;++i)
		sum*=9;
		cout<<mo(sum);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
