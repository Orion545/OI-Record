#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<queue>
#include<functional>
#include<cstring>
#include<deque>
#include<map>
#include<set>
using namespace std;
long long n,a[100005],b[100005],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]>0)
		{
			ans+=b[i];
		}
	}
	cout<<ans;
	return 0;
}
