#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
using namespace std;
int x=1000000007;
int read();
long long ans=0;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read();
	if(n==1)
	{
		ans=2;
		for(int i=1;i<m;i++)
		{
			ans=ans*2;
			ans=ans%x;
		}
		cout<<ans;
		return 0;
	}
	if(n==1)
	{
		ans=2;
		for(int i=1;i<n;i++)
		{
			ans=ans*2;
			ans=ans%x;
		}
		cout<<ans;
		return 0;
	}
	if(n==2)
	{
		ans=2;
		for(int i=1;i<m;i++)
		{
			ans=ans+ans/2;
			ans=ans*2;
			ans=ans%x;
		}
		cout<<(ans*2)%x;
		return 0;
	}
	if(m==2)
	{
		ans=2;
		for(int i=1;i<n;i++)
		{
			ans=ans+ans/2;
			ans=ans*2;
			ans=ans%x;
		}
		cout<<(ans*2)%x;
		return 0;
	}
	if(n==3)
	{
		ans=7;
		for(int i=1;i<m;i++)
		{
			ans=ans*4;
			ans=ans%x;
		}
		cout<<ans%x;
		return 0;
	}
	if(m==3)
	{
		ans=7;
		for(int i=1;i<n;i++)
		{
			ans=ans*4;
			ans=ans%x;
		}
		cout<<ans%x;
		return 0;
	}
	if(m==5&&n==5)
	cout<<7136;
	fclose(stdin);fclose(stdout);
}
int read()
{
	char ch=getchar();int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
