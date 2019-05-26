#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,last=0,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int c;scanf("%d",&c);
		if(last<c) ans+=c-last;
		last=c;
	}
	printf("%d",ans);
}
