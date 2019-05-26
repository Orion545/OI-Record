#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,uu,vv;
string a;
int p[100001];
int map[5001][5001];
int dp[11][4];
int x,y,u,v,ans=0;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(map,0,sizeof(map));
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n-1;i++) cin>>uu>>vv;
	while(m>=1)
	{
		m--;
		cin>>u>>x>>v>>y;
		if((u==v+1 && x==0 && y==0) || (v==u+1 && x==0 && y==0)) cout<<-1;
		else if(n<=100000 && a[0]=='A')
		{
			memset(dp,127/3,sizeof(dp));
			dp[0][0]=dp[0][1]=dp[0][2]=0;
			ans=0;
			for(int j=1;j<=n;j++)
			{
				if(j==u && x==1)
				{
					dp[j][2]=dp[j][0]=dp[j][1]=dp[j-1][2]+p[j];
					ans=0;
				} 
				else if(j==u && x==0) 
				{
					dp[j][2]=dp[j][0]=dp[j][0]=dp[j-1][2];
					ans++;
				}
				if(j==v && y==1)
				{
					dp[j][2]=dp[j][0]=dp[j][1]=dp[j-1][2]+p[j];
					ans=0;
				}
				else if(j==v && y==0) 
				{
					dp[j][2]=dp[j][0]=dp[j][0]=dp[j-1][2];
					ans++;
				}
				else
				{
					if(ans==1)
					{
						dp[j][2]=dp[j][0]=dp[j][1]=dp[j-1][2]+p[j];
						ans=0;
					}
					else
					{
						dp[j][0]=min(dp[j-1][2],dp[j][0]);
						dp[j][1]=min(dp[j-1][2]+p[j],dp[j][1]);
						dp[j][2]=min(dp[j][0],dp[j][1]);
						if(dp[j][0]<=dp[j][1]) ans++;
					}
				}
			}
			cout<<dp[n][2];
		}
		else if(a[1]=='1')
		{
			long long ans=p[1];
			if((v%2==0 && y==0) || (v%2==1 && y==1))
				for(int j=2;j<=n;j=j+2) ans=ans+min(p[j],p[j+1]);
			else 
			{
				ans=p[2];
				for(int j=3;j<=n;j=j+2) ans=ans+min(p[j],p[j+1]);
			}
			cout<<ans;
		}
		else cout<<-1;
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
