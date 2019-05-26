#include <bits/stdc++.h>

using namespace std;
long long ans;
int n,las,a;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	ans=0;las=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if (a>las) ans+=a-las;
		las=a;
	}
	cout<<ans;
	return 0;
}
