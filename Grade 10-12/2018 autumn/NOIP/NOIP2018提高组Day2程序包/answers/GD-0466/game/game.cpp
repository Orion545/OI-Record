#include"cstdio"
#include"algorithm"
#define ll long long
#define p 1000000007
#define ni 500000004
#define MAXN 1000000+10

using namespace std;

ll dp[9][MAXN];

inline ll getmi(ll x,ll y)
{
	ll f=x,ans=1;
	while(y)
	{
		int k=y&1;
		if(k) ans=ans*f%p;
		f=f*f%p;
		y>>=1;
	}
	return ans;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	ll k1=getmi((ll)2,(ll)(n+m-1));
	k1=(k1+p-1)%p;
	for(int i=1; i<=m; i++)
		dp[1][i]=1;
	for(int i=1; i<=n; i++)
		dp[i][1]=1;
	for(int i=2; i<=n; i++)
		for(int j=2; j<=m; j++)
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%p;
	ll num1=dp[n][m]-1;
	ll sum1=1;
	if(num1!=1)
	sum1=(1+num1)%p*num1%p*ni%p;
	sum1=sum1*(k1*((k1+p-1)%p)%p*ni%p)%p;
	printf("%lld\n",sum1);
	return 0;
}
