#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
const int N=5500;
struct Travel{
	int Id;
	friend bool operator < (const Travel i,const Travel j)
	{
		return i.Id>j.Id;
	}
};
stack<int> S;
vector<int> ma[5005];
priority_queue<Travel> q;
int n,m,o,O;
int pi=1,p[N];
int low[N],pre[N],w[N],dfs_time,cnt;
bool vis[N];

void read();
void read_into(int u,int v);
void work();
void doit();
void Tarjan(int u,int fa);
void dfs(int u);
void out_o();

int main()
{
	read();
	work();
	return 0;
}

void work()
{
	Tarjan(1,0);
	//doit();
/*	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<ma[i].size();j++)
		  cout<<ma[i][j]<<' ';
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	  cout<<w[i]<<endl;
	cout<<endl;*/
	vis[1]=true;
	dfs(1);
	for(int i=1;i<=n;i++)
	  if(!vis[i])
	    dfs(i);
}

void dfs(int u)
{	
	if(w[u]==w[o])
	{
		out_o();
	}
	else
	  printf("%d ",u);
	for(int i=0;i<ma[u].size();i++)
	{
		int v=ma[u][i];
		if(!vis[v])
		{
			/*if(!q.empty() && w[u]==w[o])
			{
				Travel NoW=q.top();
				while(!q.empty() && v>NoW.Id)
				{
					vis[NoW.Id]=true;
					q.pop();
					dfs(NoW.Id);
					NoW=q.top();
				}
			}*/
			vis[v]=true;
			dfs(v);	
		}
	}
}

void out_o()
{
	Travel D;D.Id=o;q.push(D);
	vis[o]=true;
	while(!q.empty())
	{
		Travel now=q.top();q.pop();
		int u=now.Id;
		printf("%d ",u);
		for(int i=0;i<ma[u].size();i++)
		{
			int v=ma[u][i];
			if(!vis[v] && w[v]==w[o])
			{
				vis[v]=true;
				Travel V;
				V.Id =v;
				q.push(V); 
			}
		}
	} 
}

void Tarjan(int u,int fa)
{
	low[u]=pre[u]=++dfs_time;S.push(u); 
	for(int i=0;i<ma[u].size();i++)
	{
		int v=ma[u][i];
		if(v!=fa)
		{
			if(!pre[v])
			{
				Tarjan(v,u);
				low[u]=min(low[u],low[v]);
			}
			else
			if(!w[v])
		  	  low[u]=min(low[u],pre[v]);
		}
	}
	if(low[u]==pre[u])
	{
		cnt++;
		int now=0,num=0;
		while(now!=u)
		{
			now=S.top();
			S.pop();
			w[now]=cnt;
			num++;
		}
		if(num>1)
		  o=u;
	}
}

void doit()
{
	for(int i=1;i<=n;i++)
	  if(w[i]==w[o] && i!=o)
	  {
	  	for(int j=0;j<ma[i].size();j++)
	  	{
	  		int v=ma[i][j];
	  		if(w[v]!=w[o])
	  	  	{
	  	  		read_into(o,v);
	  	  		read_into(v,o);
	  	  	}
	  	}
	  }
}

void read()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		read_into(u,v);
		read_into(v,u);
	}
}
void read_into(int u,int v)
{
	ma[u].push_back(v);
	for(int i=0;i<ma[u].size();i++)
	{
		if(v<ma[u][i])
		{
			for(int j=ma[u].size()-1;j>i;j--)
			  ma[u][j]=ma[u][j-1];
			ma[u][i]=v;
			return ;
		}
	}
}
