#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long x;
long long n,now;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(now>x)now=x;
		else
		{
			ans+=x-now;
			now=x;
		}
	}
	cout<<ans;
	return 0;
}

