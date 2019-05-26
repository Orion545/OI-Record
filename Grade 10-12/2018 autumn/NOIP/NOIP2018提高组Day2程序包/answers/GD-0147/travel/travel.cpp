#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int tp[1000000];
int map[200][200];
int k=2;
int v[1000000];
int u,v1;
int v2[1000000];
int d[10000000];
int t;
int k2=1;
int now;
int tp2[1000000];
int vis[1000000];
int buer;
/*int work(int x)
{
	now=k2-1;
	for(int i=now;tp2[i]!=x&&i>=1;i--)
	for(int j=i-1;tp2[j]!=x&&j>=1;j--)
	{
		cout<<tp2[i];
	map[tp2[i]][tp2[j]]=map[tp2[j]][tp2[i]]=1;
}
	return 0;
}
int circle(int x)
{
	int buer=0;
	for(int i=1;i<=n;i++)
	if(!vis[i])
	buer=1;
	if(buer==0)
	return 0;
	for(int i=1;i<=n;i++)
	{
		if(v2[i]==1&&map[x][i])
		work(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(v2[i]==0&&map[x][i])
		{
			tp2[k2]=i;
			k2++;
			v2[i]=1;
			vis[i]++;
			circle(i);
			v2[i]=0;
			k2--;
			tp2[k2]=0;
		}
	}
	return 0;
}*/

int dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0&&map[x][i])
		{
			tp[k]=i;
			k++;
			v[i]=1;
			dfs(i);
		}
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v1;
		map[u][v1]=1;
		map[v1][u]=1;
	}
/*	tp2[1]=1;
	v2[1]=1;
	vis[1]=1;
	circle(1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(v2[i]==v2[j])
		{
			map[i][j]=map[j][i]=1;
		}
	}*/
	v[1]=1;
	dfs(1);
	tp[1]=1;
	for(int i=1;i<=n;i++)
	cout<<tp[i]<<" ";
	return 0;
}
