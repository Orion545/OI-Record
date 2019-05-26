#include<stdio.h>
#include<string.h>
#include<math.h>
int n;
int d[100000]={0};
int book[100000]={0};
long int sum=0;
int i;
int flag=0;
int dfs(int step)
{
	
	if(book[step]==d[step])
	{
		sum++;
		flag=1;
		return 0;
	}
	
	while(step<n)
	{
		if(flag==1)
		return 0;
		book[step]++;
		dfs(step+1);
	}
	return 0;	
}
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&d[i]);
	memset(book,0,sizeof(book));
	for(i=0;i<n;i++)
	{
		while(book[i]<d[i])
		{
			if(book[i+1]!=d[i+1])
			dfs(i);
			else
			{
				sum+=d[i]-book[i];
				book[i]=d[i];
			}
			flag=0;
		}
		
	}
	printf("%ld",sum);
	return 0;
	
}
