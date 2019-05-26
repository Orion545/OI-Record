#include<iostream>
#include<cstdio>
using namespace std;
long long n;
long long ans=0;
long long a[1000001];
int minn=123456789;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=minn) minn=a[i];
	}
	ans+=minn;
	for(int i=1;i<=n;i++)
	{
		a[i]-=minn;
	}
	int k=1;
	while(a[k]==0) k++;
	do
	{
		int m=n;
		minn==123456789;
		for(int i=k;i<=n;i++)
		{
			if(a[i]<=minn&&a[i]!=0) minn=a[i];
			if(a[i]==0) 
			{
               m=i-1;
               break;
		    }
		    else continue;
		}
		ans+=minn;
		for(int i=k;i<=m;i++)
		{
			a[i]=a[i]-minn;
		}
		while(a[k]==0) k++;
	}while(k<=n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
