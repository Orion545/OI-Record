#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,next[100001],head[100001],to[100001],dfn[100001],xiao[100001],x;
int gg[100001],g;
bool pan[10001],huan[10001];
int dui[100001],top;
int tanx[3],ge;
void tarjan(int root)
{
	dfn[root]=xiao[root]=++x;
	gg[++g]=root;
	for(int i=head[root];i;i=next[i])
	{
		if(dfn[to[i]])
		xiao[root]=min(xiao[root],dfn[to[i]]);
		else
		{
		tarjan(to[i]);
		xiao[root]=min(xiao[root],xiao[to[i]]);
		}
	}
	if(dfn[root]==xiao[root])
	{
		int l=1;
		while(gg[g]!=root)
		{
		l++;huan[gg[g]]=1;g--;	
		}if(l>=2)gg[root]=1;
		g--;
	}return;
}
void dfs(int root)
{
	pan[root]=1;cout<<root<<" ";
	int minn=1000000;
	int begin=top;
	for(int i=head[root];i;i=next[i])
	{
		if(!pan[to[i]])
		{
		dui[++top]=to[i];
		}
	}int end=top;
	sort(dui+begin+1,dui+end+1);
	for(int i=begin+1;i<=end;i++)
	{
		dfs(dui[i]);
	}
	return;
}
void dfs2(int root,bool zai)
{
	pan[root]=1;cout<<root<<" ";
	int minn=1000000;
	int begin=top;
	for(int i=head[root];i;i=next[i])
	{
		if(!pan[to[i]])
		{
		dui[++top]=to[i];
		if(huan[to[i]]) 
		 {
		 zai=1;	tanx[++ge]=to[i];
		 }
		}
	}
	if(tanx[2]>tanx[1])swap(tanx[2],tanx[1]);
	int end=top;
	sort(dui+begin+1,dui+end+1);
	
	for(int i=begin+1;i<=end;i++)
	{
		if(zai==1&&tanx[2]<dui[i]&&ge!=0)
		{
		ge--;if(tanx[1]==tanx[2])ge--;
		dfs2(tanx[2],zai);
		}
		dfs2(dui[i],zai);
	}
		if(zai==1&&ge!=0)
		{
		ge--;if(tanx[1]==tanx[2])ge--;
		dfs2(tanx[2],zai);
		}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		next[i]=head[x];head[x]=i;to[i]=y;
		next[i+m]=head[y];head[y]=i+m;to[i+m]=x;
	}
	if(m==n-1)
	dfs(1);
	else
	{
		tarjan(1);
		dfs2(1,0);
	}
	cout<<endl;return 0;
}
