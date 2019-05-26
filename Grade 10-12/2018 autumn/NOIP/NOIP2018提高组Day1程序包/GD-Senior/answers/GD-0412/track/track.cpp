#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int map[100][100],flag[100][100],len[100][100],ans=0,count=0,n;
void dfs(int j)
{
	int f=0,i=0;
	for(i=1;i<=n;i++)
	{
		if(map[j][i]==1)f=1;
	}
	if(f==0)ans=max(ans,count);
	else
	{
		for(i=1;i<=n;i++)
	{
		if(map[j][i]==1&&flag[j][i]==0&&flag[j][i]==0)
		{
			count+=len[j][i];
			flag[j][i]=1;
			dfs(i);
			flag[j][i]=0;
			count-=len[j][i];
		}	
	}
	}	
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	memset(flag,0,sizeof(flag));
	memset(map,0,sizeof(map));
	memset(len,0,sizeof(len));
	int a,b,m,i=0,j=0,l;
	cin>>n>>m;
	for(i=1;i<=n-1;i++)
	{
		cin>>a>>b>>l;
		map[a][b]=1;
		map[b][a]=1;
		len[a][b]=l;
		len[b][a]=l;
	}
	for(i=1;i<=n;i++)
	{
		dfs(i);	
	}
	cout<<ans;
	return 0;
}
