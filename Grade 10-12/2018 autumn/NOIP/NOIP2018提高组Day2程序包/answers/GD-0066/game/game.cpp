#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=300,maxm=100010;
long long a,b,i,j,k,p,tot,ans,num[maxn];
long long dp[maxm][maxn];
void getnum()
{
	int kk;
	for (kk=0;kk<=tot;kk++)
	 if (a-1>=0) num[kk]=kk&((1<<(a-1))-1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	tot=(1<<a)-1;
	for (i=0;i<=tot;i++)
	 dp[1][i]=1;
	p=1000000007;
	getnum();
	for (i=1;i<b;i++)
	 for (j=0;j<=tot;j++)
	  for (k=0;k<=tot;k++)
	   if (num[j]>=(k>>1)) dp[i+1][k]=(dp[i+1][k]+dp[i][j])%p;
	for (i=0;i<=tot;i++)
	 ans=(ans+dp[b][i])%p;
	printf("%lld",ans);
	return 0;
}
