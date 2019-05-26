#include<cstdio>
#include<iostream>
using namespace std;
int n,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int u = 0,v;
	for (int i = 1;i <= n;i ++)
	{
		scanf("%d",&v);
		if (v > u) ans = ans + (v - u);
		//printf("%d\n",ans);
		u = v;
	}
	printf("%d",ans);
	return 0;
}
