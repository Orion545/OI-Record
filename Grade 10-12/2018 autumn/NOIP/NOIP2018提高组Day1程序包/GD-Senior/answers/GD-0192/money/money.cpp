#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,t,anum;
int a[150];
bool dela[105];
bool dfs(int x,int nowzhi)
{
	if(nowzhi==a[x])return 1;
	for(int i=1;i<x;i++)if(!dela[i])
	{
		if(nowzhi+a[i]<=a[x])if(dfs(x,nowzhi+a[i]))return 1;
	}
	return 0;
}
void huzhi()
{
	for(int i=1;i<n;i++)if(!dela[i])
	for(int j=i+1;j<=n;j++)
	if(a[j]%a[i]==0)dela[j]=1;
	for(int i=3;i<=n;i++)if(!dela[i])
	for(int j=1;j<i;j++)if(!dela[j])
	for(int k=j+1;k<i;k++)if(!dela[k])
	{
		if(k==j)continue;
		if(a[i]>a[j]*a[k]-a[j]-a[k])dela[i]=1;
	}
	for(int i=3;i<=n;i++)if(!dela[i])
	if(dfs(i,0))dela[i]=1;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("1");
			cout<<endl;
			continue;
		}
		anum=0;memset(dela,0,sizeof(dela));
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
		sort(a+1,a+1+n);
		huzhi();
		for(int i=1;i<=n;i++)
		if(!dela[i])anum++;
		printf("%d",anum);cout<<endl;
	}
	return 0;
}
