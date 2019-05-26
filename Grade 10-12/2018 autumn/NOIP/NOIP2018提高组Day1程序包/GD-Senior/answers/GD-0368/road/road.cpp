#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

int st[100001],n,g,ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	
	ans=0;g=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		ans+=a>st[g]?a-st[g]:0;
		
		for(;a<st[g];g--);
		st[++g]=a;
	}
	
	printf("%d\n",ans);
}
