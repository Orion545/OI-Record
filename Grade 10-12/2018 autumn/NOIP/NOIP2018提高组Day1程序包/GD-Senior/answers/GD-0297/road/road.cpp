#include<cstdio>
#include<iostream>
using namespace std;
int n,a[1000050];
long long ans;
int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	cout<<ans<<"\n";
}
