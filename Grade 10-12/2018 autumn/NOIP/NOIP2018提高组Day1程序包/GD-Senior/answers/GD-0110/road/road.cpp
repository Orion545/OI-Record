#include<iostream>
#include<cstdio>
using namespace std;
int st,n,a[100010],check[100010];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	st=a[1];
	ans=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=st)
		st=a[i];
		else
		{
			ans+=a[i]-st;
			st=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
