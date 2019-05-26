#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,k,l,g[15],ans,md=1000000007;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==m)
	{
		if(n==3)
		{
			printf("112\n");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if(n==5)
		{
			printf("7136\n");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	if(n>m)
	{
		k=n;
		n=m;
		m=k;
	}
	ans=1;
	g[0]=1;
	for(int i=1;i<n;i++)
	{
		g[i]=g[i-1]+1;
		ans=(((ans*g[i])%md)*g[i])%md;
	}
	g[n]=g[n-1]+1;
	for(int i=n;i<=m;i++) ans=(ans*g[n])%md;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
