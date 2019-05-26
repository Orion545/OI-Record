#include<stdio.h>
#include<stdlib.h>
int g[5001][5001]={0};
int ans[5001]={0};
int book[5001]={0};
int n=0;
int q=1;

void dfs(int k)
{
	int j=1;
	for(j=1;j<=n;j++)
	{
		if(g[k][j]==1&&book[j]==0)
		{
			book[j]=1;
			ans[q++]=j;
			dfs(j);
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i=0,m=0,x=0,y=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		g[x][y]=1;
		g[y][x]=1;
	}
	ans[q]=1;
	q++;
	book[1]=1;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
