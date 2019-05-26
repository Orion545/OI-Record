#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n,d[300010],maxx,minn,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		if(d[i]>d[i-1]) ans+=d[i]-d[i-1];
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;	
}
