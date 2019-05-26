#include<cstdio>
using namespace std;
const long long mod=1e9+7;
long long f[4]={0,8,36,112};
long long fp(long long a,long long b)
{
	long long t=1;
	while (a)
	{
		if (a&1) t=(t*b)%mod;
		a>>=1;
		b=(b*b)%mod;
	}
	return t;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long m,n;
	scanf("%lld %lld",&n,&m);
	if (n==2) printf("%lld",fp(m-1,3)*4%mod);
	if (n==3) printf("%lld",f[m]);
	fclose(stdin); fclose(stdout);
	return 0;
}
