#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;
int n,m,a,x,b,y;
int p[100010],f[100010];
long long dp[100010][3];
bool flag;
string st;

long long pmin(long long x,long long y) 
{
	if (x>y) return y; else return x;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>st;
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n-1;i++) scanf("%d%d",&x,&y);
	if (st[0]=='A') 
	{
		for (int i=1;i<=m;i++) 
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			flag=true;
			for (int i=0;i<=n;i++) for (int j=0;j<=1;j++) dp[i][j]=10000000010;
			dp[0][0]=0;
			dp[0][1]=0;
			if (x==0) f[a]=-1; else f[a]=1;
			if (y==0) f[b]=-1; else f[b]=1;
			if (f[1]==1) 
			{
				dp[1][1]=p[1];
			} else 
			if (f[1]==-1) 
			{
				dp[1][1]=-1;
			} else 
			{
				dp[1][1]=p[1];dp[1][0]=0;
			}
			for (int i=2;i<=n;i++)
			{
				if (f[i]==1 && f[i-1]==1) 
				{
					dp[i][1]=dp[i-1][1]+p[i];
				} else if (f[i]==1 && f[i-1]==-1) 
				{
					dp[i][1]=dp[i-2][1]+p[i];
				} else if (f[i]==1 && f[i-1]==0) 
				{
					dp[i][1]=pmin(dp[i-1][0],dp[i-1][1])+p[i];
				} else 
				if (f[i]==-1 && f[i-1]==1) 
				{
					dp[i][0]=dp[i-1][1];
				} else 
				if (f[i]==-1 && f[i-1]==-1) 
				{
					flag=false;
				} else 
				if (f[i]==-1 && f[i-1]==0) 
				{
					dp[i][0]=dp[i-1][1];
				} else 
				if (f[i]==0 && f[i-1]==0) 
				{
					dp[i][1]=pmin(dp[i-1][0],dp[i-1][1])+p[i];
					dp[i][0]=dp[i-1][1];
				} else 
				if (f[i]==0 && f[i-1]==1) 
				{
					dp[i][1]=dp[i-1][1]+p[i];
					dp[i][0]=dp[i-1][1];
				} else 
				if (f[i]==0 && f[i-1]==-1) 
				{
					dp[i][1]=dp[i-1][0]+p[i];
				}
			}
			f[a]=0;f[b]=0;
			if (!flag) printf("-1\n"); else printf("%lld\n",pmin(dp[n][1],dp[n][0]));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
