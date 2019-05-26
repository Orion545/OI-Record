#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=200,maxm=50000;
int a,b,i,j,ans,x[maxn],dp[maxm];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&a);
	while (a!=0)
	{
		memset(dp,false,sizeof(dp));
		memset(x,0,sizeof(x));
		scanf("%d",&b);
		ans=b;
		for (i=1;i<=b;i++)
		 scanf("%d",&x[i]);
		dp[0]=true;
		for (i=1;i<=b;i++)
		 for (j=0;j<=30000;j++)
		  if (dp[j]) dp[j+x[i]]++;
		for (i=1;i<=b;i++)
		 if (dp[x[i]]>1) ans--;
		printf("%d\n",ans); 
		a--;
	}
	return 0;
}
