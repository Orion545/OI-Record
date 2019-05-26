#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int n,m,num[100][100],ans;

void proc()
{
	vector<pair<int,int> > unvalid;
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<m;++j)
		{
			if(num[i][j]<num[i-1][j+1])return;
			if(i<n && j<m-1)
			if(num[i][j]==num[i-1][j+1])unvalid.push_back(make_pair(i,j));
			for(int k=0;k<unvalid.size();++k)
			{
				pair<int,int> now=unvalid[k];
				if(i>now.first && j>now.second && num[i][j]>num[i-1][j+1])return;
			}
		}
	}
	++ans;
}

void dfs(int now)
{
	if(now==n*m)
	{
		proc();
		return;
	}
	int x=now/m+1,y=now%m+1;
	num[x][y]=0;
	dfs(now+1);
	num[x][y]=1;
	dfs(now+1);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	if(n<=3 && m<=3)
	{
		dfs(0);
		printf("%d\n",ans);
		return 0;
	}
	if(n==2)
	{
		int ans=4;
		for(int j=2;j<=m;++j)ans=(long long)ans*3%mod;
		printf("%d\n",ans);
		return 0;
	}
	if(n==3)
	{
		int ans=112;
		for(int j=4;j<=m;++j)ans=(long long)ans*3%mod;
		printf("%d\n",ans);
		return 0;
	}
	dfs(0);
	printf("%d\n",ans);
	//mod!
}
