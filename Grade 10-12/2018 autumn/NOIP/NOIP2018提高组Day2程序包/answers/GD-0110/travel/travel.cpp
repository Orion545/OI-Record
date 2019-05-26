#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ton[5010][5010],js[5010],check[5010];
int lj;
void dfs(int le)
{
	if(lj>=n)
	return;
	for(int i=1;i<=js[le];i++)
	if(!check[ton[le][i]])
	{
	lj++;
	check[ton[le][i]]=1;
	cout<<ton[le][i]<<" ";
		dfs(ton[le][i]);
	}	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		js[a]++;
		ton[a][js[a]]=b;
		js[b]++;
		ton[b][js[b]]=a;
	}
	for(int i=1;i<=n;i++)
	{
		sort(ton[i]+1,ton[i]+js[i]+1);
	}
	check[1]=1;
	cout<<1<<" ";
	dfs(1);
	return 0;
}
