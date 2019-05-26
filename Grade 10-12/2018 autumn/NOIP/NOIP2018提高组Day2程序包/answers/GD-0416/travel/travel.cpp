#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=5000;
int n,m,degree[N+10],del[N+10];
priority_queue<int,vector<int>,greater<int> >q[N+10];
vector<int>g[N+10];
bool vis[N+10];
void dfs(int node)
{
	if(!vis[node]) printf("%d ",node);
	vis[node]=1;
	while(q[node].size())
	{
		int s=q[node].top();
		q[node].pop();
		while(vis[s]&&q[node].size()) s=q[node].top(),q[node].pop();
		if(!vis[s]) dfs(s);
	}
}
void solve(int node)
{
	bool flag=0;
	int left=q[node].top();q[node].pop();
	while(vis[left]&&q[node].size()) left=q[node].top(),q[node].pop();
	int right=q[node].top();q[node].pop();
	while(vis[right]&&q[node].size()) right=q[node].top(),q[node].pop();
	vis[node]=1;
	printf("%d ",node);
	while(left<right)
	{
		if(!vis[left]) printf("%d ",left);
		vis[left]=1;
		int s=q[left].top();q[left].pop();
		while(vis[s]&&q[left].size()) s=q[left].top(),q[left].pop();
		left=s;
	}
	dfs(right);
}
void dfs2(int node)
{
	if(!vis[node]) printf("%d ",node);
	vis[node]=1;
	while(q[node].size())
	{
		int s=q[node].top();
		q[node].pop();
		while(vis[s]&&q[node].size()) s=q[node].top(),q[node].pop();
		if(!vis[s]&&del[s]) dfs2(s);
		if(!vis[s]&&!del[s]) solve(s);
	}
}
void tp(int node)
{
	del[node]=1;
	degree[node]--;
	for(int i=0;i<g[node].size();i++)
	{
		int s=g[node][i];
		if(del[s]) continue;
		degree[s]--;
		if(degree[s]==1||!degree[s]) del[s]=1,tp(s);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=1;
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		q[u].push(v);
		q[v].push(u);
		degree[v]++;degree[u]++;
		if(degree[v]>2||degree[u]>2) flag=0;
	}
	if(m==n-1){dfs(1); return 0;}
	if(flag){solve(1); return 0;}
	for(int i=1;i<=n;i++)
		if(degree[i]==1&&!del[i]) tp(i);
	dfs2(1);
	return 0;
}
