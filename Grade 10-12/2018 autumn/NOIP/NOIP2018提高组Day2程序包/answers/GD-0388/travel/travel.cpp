#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int N=5005,M=10005;
int toit[M],next[M],head[N],tot,n,m;
bool vis[N],see[N],go[N],cut[N];
int low[N],dfn[N],cnt,fa[N];

void add(int x,int y)
{
	toit[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}

void dfs(int now)
{
	
	priority_queue<int , vector<int>,greater<int> >q;
	while (!q.empty()) q.pop();
	for (int a=head[now];a;a=next[a])
	{
		int v=toit[a];
		if (!vis[v]) q.push(v);
	}
	
	while (!q.empty())
	{
		int u=q.top();
		q.pop();
		cout<<u<<" ";
		vis[u]=true;
		dfs(u);
	}
}

void work1()
{
	vis[1]=true;
	cout<<"1 ";
	dfs(1);
}



int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int a=1;a<=m;++a)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	
	work1();
	
	
	fclose(stdin);fclose(stdout);return 0;
}
