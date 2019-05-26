#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[10000001];
int  b;
unsigned long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>b;
	for(int  i=1;i<=b;i++) 
	{
		cin>>a[i];
	}
	ans=0;
	for(int i=1;i<=b;i++)
	{
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	cout<<ans<<endl;
	return 0;
}
