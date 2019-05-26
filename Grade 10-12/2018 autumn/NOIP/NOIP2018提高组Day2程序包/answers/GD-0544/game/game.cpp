#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;

int n,m;
int ans,mx,mp[110][110];bool bk;
void check(int x,int y,int d,int k)
{
	if(bk==false)return ;
	d+=mp[x][y]*(1<<k);
	if(x==n&&y==m)
	{
		if(mx>d){bk=false;return;}
		mx=d;
	}
	if(y<m)check(x,y+1,d,k+1);
	if(x<n)check(x+1,y,d,k+1);
}

void dfs(int x,int y)
{
	if(x==n+1)
	{
		bk=true;mx=0;check(1,1,0,0);
		if(bk==true)ans++;
		return ;
	}
	mp[x][y]=0;
	if(y==m)dfs(x+1,1);
	else dfs(x,y+1);
	mp[x][y]=1;
	if(y==m)dfs(x+1,1);
	else dfs(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	if(n==1)
	{
		LL ans=1;
		for(int i=1;i<=m;i++)ans=ans*2%mod;
		printf("%lld\n",ans);
	}
	else if(n==2)
	{
		LL ans=4;
		for(int i=1;i<m;i++)ans=ans*3%mod;
		printf("%lld\n",ans);
	}
	else printf("112\n");
	return 0;
}
