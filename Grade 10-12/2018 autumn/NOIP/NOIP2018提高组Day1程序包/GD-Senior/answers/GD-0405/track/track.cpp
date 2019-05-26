#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int t;
int dp[5000][5000],G[5000][5000],ans[5000][5000],vis[5000][5000];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);	
	 int n,m,u,v,w;
	  cin>>n>>m;
	  for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	dp[i][j]=0;G[i][j]=1e9;ans[i][j]=0;
	  }
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;i<=n;j++)
	{
		if(i==j)dp[i][j]=0;
		else dp[i][j]=G[i][j];
	}
	
	for(int k=1;k<=n;k++)
   {   
    int c=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	vis[i][j]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(!vis[i][k]&&!vis[k][j]&&dp[i][k]+dp[k][j]<G[i][j])
	{
	  dp[i][j]=dp[i][k]+dp[k][j];
	  vis[i][k]=1;
	  vis[k][j]=1;
	  ans[k][c]=dp[i][j];
	  c++;	  
    }
    }
	for(int i=1;i<=n;i++)
	sort(ans[i]+1,ans[i]+n+1);
	int tmp[50005];
	for(int i=1;i<=n;i++)
	tmp[i]=ans[i][1];
	sort(tmp+1,tmp+n+1);
	printf("%d",tmp[n]);
    
    fclose(stdin);
	fclose(stdout);
	return 0;
}
