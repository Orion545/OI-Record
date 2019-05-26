#include<iostream>
#include<cstdio>
using namespace std;
long long ans,a[12],n,m;
void dfs(int x)
{
	if(x==n*m+1)
	{
		ans++;
		return ;
	}
	a[x]=1;
	dfs(x+1);
	a[x]=0;
	if(x%m==0)
	dfs(x+1);
	else
	if(x<=m)
	dfs(x+1);
	else
	if(!a[x-m+1])
	dfs(x+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n<=3&&m<=3)
	{
		dfs(1);
	}
	if(n==2)
	{
		ans=3;
		for(int i=1;i<=m;i++)
		ans=ans*2%1000000007;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
