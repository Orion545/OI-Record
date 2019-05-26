#include<list>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n,m,fa[5005],da[5005],num,now,last;
vector<int>v1[5005];
vector<int>v2[5005];
vector<int>v3;
bool vis[5005];
void dfs1(int rt)
{
	vis[rt]=true;
	da[++num]=rt;
	for(int i=0;i<v1[rt].size();i++)
	{
		v2[rt].push_back(v1[rt][i]);
	}
	sort(v2[rt].begin(),v2[rt].end());
	for(int i=0;i<v2[rt].size();i++)
	{
		if(!vis[v2[rt][i]])
		{
			dfs1(v2[rt][i]);
		}
	}
}
void dfs2(int rt)
{
	vis[rt]=true;
	da[++num]=rt;
	for(int i=0;i<v1[rt].size();i++)
	{
		v3.push_back(v1[rt][i]);
	}
	sort(v3.begin(),v3.end());
	for(int i=0;i<v3.size();i++)
	{
		if(!vis[v3[i]])
		{
			dfs2(v3[i]);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	if(m==n-1)
	{
		dfs1(1);
		for(int i=1;i<=n;i++)
		{
			printf("%d ",da[i]);
		}
	}
	else
	{
		dfs2(1);
		for(int i=1;i<=n;i++)
		{
			printf("%d ",da[i]);
		}
	}
	return 0;
}
