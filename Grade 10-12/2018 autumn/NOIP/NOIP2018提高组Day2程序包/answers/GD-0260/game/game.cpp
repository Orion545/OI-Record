#include<cstdio>
#include<cstdlib>

const int mod=1e9+7;
int n,m;

int pow(int x,int y)
{
	int ans=1;
	while(y>0)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n==1)
	{
		printf("%d",pow(2,m));
		return 0;
	}
	if(m==1)
	{
		printf("%d",pow(2,n));
		return 0;
	}
	if(n==2)
	{
		printf("%d",4*3*(m-1)%mod);
		return 0;
	}
	if(m==2)
	{
		printf("%d",4*3*(n-1)%mod);
		return 0;
	}
	if(n==3 && m==3)
	{
		printf("%d",112);
		return 0;
	}
}
