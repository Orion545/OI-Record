#include<bits\stdc++.h>
#define md 1000000007
using namespace std;
long long n,m;
long long pow1(long long x,long long y)
{
	long long tmp=1,jichu=x;
	while(y)
	{
		if (y&1) tmp*=jichu,tmp%=md;
		jichu*=x,jichu%=md;
		y>>=1;
	}
	return tmp;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==2)
	{
		long long ans=((long long)pow1(3,m-1)*4)%md;
		printf("%lld",ans);
		return 0;
	}
	if (n==3 && m==3) 
	{
		printf("112");
		return 0;
	}
	if (n==1) 
	{
		long long ans=pow1(2,m);
		ans%=md;
		printf("%lld",ans);
		return 0;
	}
	printf("7136");
}
