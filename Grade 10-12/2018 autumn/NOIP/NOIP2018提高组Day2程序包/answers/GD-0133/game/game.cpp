#include<iostream>
#include<cstdio>
using namespace std;
int ans=0;
int n,m;
int a[105][105];
void dfs(int x,int y)
{
	if(y==m+1) 
	{
		dfs(x+1,1);
		return;
	}
	if(x==n+1)
	{
		bool ok=true;
		for(int i=1;i<=n-2;i++)
			for(int j=2;j<=m-1;j++)
			if(a[i][j]==a[i+1][j-1]&&a[i+1][j+1]!=a[i+2][j])
			{
				ok=false;
				break;
			}
		if(ok) ans++;
		return ;
	}
	if(a[x-1][y+1]==1)
	{
		a[x][y]=1;
		dfs(x,y+1);
		a[x][y]=0;
		return;
	}
	dfs(x,y+1);
	a[x][y]=1;
	dfs(x,y+1);
	a[x][y]=0;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}
