#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int read();
int vis[30001];int ru[30001];
short bod[30000][30000];
int sum=0,ans=0;
int n,m;
int dfs(int i);
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
    n=read();m=read();
    int minn=100000;
    for(int i=0;i<n-1;i++)
    {
    	int x=read(),y=read(),w=read();
    	bod[x][y]=w;
    	bod[y][x]=w;
    	ru[y]++;ru[x]++;
    	minn=min(minn,w);
    }
    if(m==n-1)
    {
    	cout<<minn<<endl;
    	return 0;
    }
    for(int i=1;i<=n;i++)
    {
    	sum=0;
    	if(ru[i]==1)dfs(i);
    }
    cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int read()
{	
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int dfs(int i)
{
	vis[i]=1;
	for(int j=0;j<n;j++)
	{
		if(bod[i][j]!=0&&vis[j]==0)
		{
			sum+=bod[i][j];
			ans=max(ans,sum);
			dfs(j);
			sum-=bod[i][j];
		}
	}
	vis[i]=0;
	return 0;
};
