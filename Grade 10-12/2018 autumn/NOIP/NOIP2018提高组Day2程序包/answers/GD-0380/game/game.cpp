#include<cstdio>
#include<iostream>
#include<algorithm>
#define mod 1e9+7
using namespace std;
int n,m;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-48;
		ch=getchar();
	}
	return s*w;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	long long ans1=1,ans2=0;
	for(int i=1;i<=n-1;i++)
	{
		ans*=2;
		ans%=mod;
	}
}
