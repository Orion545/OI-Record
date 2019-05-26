#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 50086
int head[maxn],next[maxn*2],to[maxn*2];
int tot=0,n,m;
bool v[maxn];
queue<int> que;
void add(int x,int y)
{
	next[++tot]=head[x];
	to[tot]=y;head[x]=tot;
}
void dfs(int x)
{
	que.push(x);
	priority_queue<int> que2;
	for(int i=head[x];i;i=next[i])
	{
		int y=to[i];
		if(v[y])continue;
		que2.push(-y);
	}
	while(que2.size())
	{
		int k=que2.top();
		que2.pop();
		v[-k]=1;
		dfs(-k);
	}
	
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y);add(y,x);
	}
	v[1]=1;
	dfs(1);
	while(!que.empty())
	{
		printf("%d ",que.front());
		que.pop();
	}
	return 0;
}
