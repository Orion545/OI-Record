#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,d[100005],ans=0,syg=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		if(d[i]>syg)
		{
			ans+=d[i]-syg;
		}
		syg=d[i];
	}
	cout<<ans;
	return 0;
}
