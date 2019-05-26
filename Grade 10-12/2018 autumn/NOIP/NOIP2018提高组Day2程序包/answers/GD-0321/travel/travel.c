#include<string.h>
#include<stdio.h>
#include<math.h>
int tu[5001][5001]={0};
int book[5001]={0};
int minroad[5001]={0};
int n,m;
int flag=0;
int step=1;
int dfs(int last,int point)
{
	int i=0,min=99999999,j;
	minroad[step]=point;
	book[point]=1;
	if(flag==1)
	return 0;
	if(step==n)
	{
		flag=1;
		return 0;
	}
	
	for(i=1;i<=n;i++)
	{
		if(i!=point&&tu[point][i]==1&&book[i]==0&&min>i)
		{
			min=i;
			for(j=1;j<=n;j++)
			{
			if(last!=0)
			if(last!=j&&tu[last][j]==1&&book[j]==0&&tu[j][min]==1&&min>j)
			{
			min=j;
			}
			}
			step=step+1;
			dfs(point,min);
			min=99999999;
		}	
	}
	return 0;
}
int main()
{
	int i,j;
	int a,b;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	tu[i][j]=99999999;
	memset(book,0,sizeof(book));
	for(i=1,j=1;i<=n;i++)
	{
		tu[i][j]=0;
	}
	
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		tu[a][b]=1;
		tu[b][a]=1;
	}
	dfs(0,1);	
	for(i=1;i<=n;i++)
	printf("%d ",minroad[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

