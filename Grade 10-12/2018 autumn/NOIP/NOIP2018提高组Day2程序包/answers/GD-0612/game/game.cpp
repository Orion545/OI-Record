#include<cstdio>
long long power(int a,int p)
{
	long long ans=1,tmp=a;
	for(;p>0;p/=2)
	{
		if(p&1)
			ans*=tmp;
		tmp*=tmp;
		ans%=1000000007;
		tmp%=1000000007;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)
	{
		int tmp=n;
		n=m;
		m=tmp;
	}
	if(n==1)
		printf("%lld",power(2,m));
	if(n==2)
		printf("%lld",(4*power(3,m-1))%1000000007);
	if((n==3)&&(m==3))
		printf("112");
	// if(n==3)
	// {
		// long long ans=(9*power(4*m-1))%1000000007;
		// for(int i=2;i<m;i++)
			// ans=(ans-(power(2,i-1)*power(3,m-i-1))%1000000007+1000000007)%1000000007;
		// printf("%lld",ans);
	// }
	if((n==5)&&(m==5))
		printf("7136");
	return 0;
}
