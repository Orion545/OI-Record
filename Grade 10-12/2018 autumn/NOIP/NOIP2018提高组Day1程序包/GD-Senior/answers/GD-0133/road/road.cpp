#include<iostream>
#include<cstdio>
using namespace std;
int n;
int d[100005];
int ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]>d[i-1]) ans+=d[i]-d[i-1];
	}
	printf("%d\n",ans);
	return 0;
}
