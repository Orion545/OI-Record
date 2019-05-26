#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	a[n]=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			ans+=a[i]-a[i+1];
		}
	}
	cout<<ans<<endl;
	return 0;
}
