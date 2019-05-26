#include<stdio.h>
#include<string.h>
#include<math.h>
int tu[5001][5001];
int n;
int book[5001][5001];
long int summax=0;
int dfs(int step,long long int sum)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(step!=i&&tu[step][i]!=99999999&&book[step][i]==0)
		{
			
			book[step][i]=1;
			book[i][step]=1;
			sum=sum+tu[step][i];
			dfs(i,sum);
			if(summax<sum)
			summax=sum;
			sum=sum-tu[step][i];
		}
	}
	return 0;
}
int main()
{
	int i,j;
	int a,b,w,m;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(book,0,sizeof(book));
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	tu[i][j]=99999999;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d %d %d",&a,&b,&w);
		tu[a][b]=w;
		tu[b][a]=w;
	}
	for(i=1,j=1;i<=n;i++,j++)
	{
		tu[a][b]=0;
	}
	for(i=1;i<=n;i++)
	{
		memset(book,0,sizeof(book));
		dfs(i,0);
	}
	printf("%ld",summax);	
	return 0;	
}

