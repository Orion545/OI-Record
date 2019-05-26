#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
	int d[100001];
	int n,ans;
	int rmq[100001][21];
	int loc[100001][21];
	int sum[100001];
void solve(int l,int r,int del)
{
	if (l>r||(l==r&&del==d[l])) return;
	int len=int(log2(r-l+1));
	int t=r-(1<<len)+1;
	if (rmq[l][len]==0)
	{
		solve(l,loc[l][len]-1,del);
		solve(loc[l][len]+1,r,del);
		return;
	}
	if (rmq[t][len]==0)
	{
		solve(l,loc[t][len]-1,del);
		solve(loc[t][len]+1,r,del);
		return;
	}
	if (sum[r]-sum[l]==r-l)
	{
		ans+=d[r]-del;
		return;
	}
	if (sum[r]==sum[l])
	{
		ans+=d[l]-del;
		return;
	}
	if (rmq[l][len]<rmq[t][len])
	{
		ans+=rmq[l][len]-del;
		solve(l,loc[l][len]-1,rmq[l][len]);
		solve(loc[l][len]+1,r,rmq[l][len]);
	}
	else
	{
		ans+=rmq[t][len]-del;
		solve(l,loc[t][len]-1,rmq[t][len]);
		solve(loc[t][len]+1,r,rmq[t][len]);
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		rmq[i][0]=d[i];
		loc[i][0]=i;
		if (d[i]>=d[i-1])
			sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for (int j=1;j<=int(log2(n));j++)
		for (int i=1;i<=n;i++)
			if (i+(1<<j)-1<=n)
			{
				int t=i+(1<<j-1);
				if (rmq[i][j-1]<rmq[t][j-1])
				{
					rmq[i][j]=rmq[i][j-1];
					loc[i][j]=loc[i][j-1];
				}
				else
				{
					int t=i+(1<<j-1);
					rmq[i][j]=rmq[t][j-1];
					loc[i][j]=loc[t][j-1];
				}
			}
	ans=0;
	solve(1,n,0);
	printf("%d",ans);
	return 0;
}
