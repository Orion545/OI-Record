#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105];
int diosa[105];
int tot,n,t;
bool flag;
void dfs(int aj)
{
	if(aj==0)
	{
		flag=0;
		return;
	}
	for(int i=1;i<=tot;i++)
	{
		if(aj==diosa[i])
		{
			flag=0;
			return;
		}
	}
	for(int i=1;i<=tot;i++)
	{
		if(aj>=diosa[i])dfs(aj-diosa[i]);
		if(!flag)return;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		memset(diosa,0,sizeof(diosa));
		memset(a,0,sizeof(a));
		tot=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		sort(a+1,a+n+1);
		if(a[1]==1)
		{
			printf("%d\n",1);
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			flag=1;
			dfs(a[j]);
			if(flag)diosa[++tot]=a[j];
		}
		printf("%d\n",tot);
		}
	return 0;
}
