#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int sz[100005],n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)
	  {
	  	scanf("%d",&sz[i]);
	  	ans+=max(sz[i]-sz[i-1],0);
	  }
	cout<<ans;
	return 0;
}
