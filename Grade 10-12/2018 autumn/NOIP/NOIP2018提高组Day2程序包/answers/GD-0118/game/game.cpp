#include<cstdio>
#include<cstring>
#include<iostream>

#define maxn 10
#define maxm 1000010
#define mod 1000000007
#define LL long long

using namespace std;

int n,m;
int dp[maxm][maxn];

int ans;

int qpow(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=(LL)x*x%mod)
		if (y&1) ans=(LL)ans*x%mod;
	return ans;
}

void solve2()
{
	if (n==1) ans=qpow(2,m);
	else if (n==2)
	{
		ans=qpow(3,n+m-3);
		ans=(LL)ans*4%mod;
	}else if (n==3)
	{
		ans=(LL)36*qpow(4,n+m-5)%mod;
		ans=((LL)ans-qpow(2,n+m-1)+mod)%mod;;
	}
}

void solve()
{
	int i,j,k;
	
	dp[1][0]=1;
	dp[1][1]=0;
	for(i=2;i<=n+m-1;i++)
	{
		for(j=max(i+j,0);i-j>=1&&j<=n;j++)
			for(k=0;i-1-k>=1,k<=n;k++)
				if (k<j) dp[i][j]+=dp[i-1][k];
	}
	
	ans=(dp[n+m-1][n-1]+dp[n+m-1][n])%mod;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if (n<m) swap(n,m);
	
	if (n<=3) solve2();
	else solve();
	
	printf("%d\n",ans);
	return 0;
}
