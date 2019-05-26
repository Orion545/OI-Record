#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int n,m;
int cnt,ans[5005],p,cntt;
int head[5005],next[5005],to[5005],fst[5005];
bool vis[5005];


void add(int u,int v)
{
	to[++cnt]=v;
	next[cnt]=head[u];
	head[u]=cnt;
}

void dfs(int u)
{
	vis[u]=1;
	ans[++p]=u;
	priority_queue <int> q;
	for(int j=head[u];j;j=next[j])
	{
		int v=to[j];
		if(!vis[v])q.push(-v);
	}
	while(!q.empty())
	{
		int v=-q.top();
		q.pop();
		dfs(v);
	}
	
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(m==n)
	{
	
		priority_queue <int> q;
		q.push(-1);
		while(q.empty())
		{
			int u=-q.top();
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			ans[++cntt]=u;
			for(int j=head[u];j;j=next[j])
			{
				int v=to[j];
				if(!vis[v])q.push(-v);
			}
		}
	}
	else dfs(1);
	for(i=1;i<=n;i++)printf("%d ",ans[i]);
	
}
