#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int Inf=10000000;
int sum=0;
int z=1;
int n;
int a[10000000]={};
int check()
{
	int haha=0;
	for(int i=2;i<=n+1;i++)
	{
		if(a[i-1]!=0&&a[i]==0)
		haha++;
	}
	cout<<haha;
	return haha;
}
int minn()
{
	int minnn=Inf,tp;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=minnn&&a[i]!=0)
		minnn=a[i];
	} 
	return minnn;
}
int zro()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	if(a[i]==0)
	ans++;
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(zro()!=n)
	{
		int y=minn();
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
		a[i]-=y;
	}
	   int z=check();
		sum+=y*z;	
	}
	cout<<sum;
	return 0;
}
