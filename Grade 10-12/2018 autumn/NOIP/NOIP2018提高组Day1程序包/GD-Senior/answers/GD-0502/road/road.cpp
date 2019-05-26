#include<iostream>
#include<cstdio>
using namespace std;
int cd[100007],n,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&cd[i]);
	cd[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(cd[i]>cd[i-1])
			ans+=cd[i]-cd[i-1];	
	}
	cout<<ans;
}
