#include<bits/stdc++.h>
using namespace std;
int cc,to[100100],net[100100],fr[100100],fa[100100],son[100100];
int n,m,u,v,h;
bool vis[100100];
void addedge(int u,int v)
{
	cc++;
	to[cc]=v;net[cc]=fr[u];fr[u]=cc;//huan[cc]=false;
}
/*void dfs1(int x)
{
	vis1[x]=true;vis[x]=true;
	while (flag)
	{
	    int minn=2147483647;
		for (int i=fr[x];i;i=net[i])
		{
			int y=to[i];
			if (!vis[y]) 
		    {
		    	if (y<minn) minn=y;
		    }
		}
		if (minn==2147483647) return ;
		dfs1(minn);
    }
	vis1[x]=false;
}*/
void dfs(int x)
{
	vis[x]=true;
	cout<<x<<" ";bool flag=true;
	while (flag)
	{
	    int minn=2147483647;
		for (int i=fr[x];i;i=net[i])
		{
			int y=to[i];
			if (!vis[y]) 
		    {
		    	if (y<minn) minn=y;
		    }
		}
	//	cout<<x<<" "<<minn<<"G\n";
		if (minn==2147483647) return ;
		dfs(minn);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	if (m==n) 
	{
	//	dfs1(1);
	}
/*	if (m==n-1) */dfs(1);
	return 0;
}
