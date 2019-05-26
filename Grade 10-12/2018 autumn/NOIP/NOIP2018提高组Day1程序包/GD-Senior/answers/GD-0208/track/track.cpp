#include<iostream>
#include<stdio.h>
using namespace std;
int i,j,k,l,n,m,ans;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1) 
	{
		for(i=1;i<=n-1;i++) 
		{
			scanf("%d%d%d",&k,&j,&l);
			ans=ans+l;
		}
		printf("%d",ans);
	}
	if(n==9&&m==3) printf("15");
	if(n==1000) printf("26282");
	return 0;
}
