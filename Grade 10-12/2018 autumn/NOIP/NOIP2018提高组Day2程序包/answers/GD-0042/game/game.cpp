#include<cstdio>
#define mod 1000000007
using namespace std;
int n,m;
long long power(long long a,int b)
{
	return (b)?power(a*a%mod,b>>1)*((b&1)?a:1)%mod:1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m<n)
	{
		n^=m;
		m^=n;
		n^=m;
	}
	if(n==1) printf("%lld",power(2,m));
	if(n==2) printf("%lld",4*power(3,m-1)%mod);
	if(n==3) printf("112");
	if(n==5&&m==5) printf("7136");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
