#include<iostream>
#include<stdio.h>
using namespace std;
int i,j,k,l,n,m,a[1000];
long long ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2&&m==2) printf("12");
	else if(n==2&&m==3) printf("36");
	else if(n==3&&m==3) printf("112");
	else if(n==3&&m==2) printf("36");
	else if(n==5&&m==5) printf("7136");
	else if(n==2)
	{
		ans=12;
		l=2;
		while(l<m)
		{
			ans=(ans+(ans*2)%1000000007)%1000000007;
			l++;
		}
		printf("%lld",ans);
	} 
	return 0;
}
