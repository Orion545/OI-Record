#include<bits/stdc++.h>
using namespace std;

int n,m,tot=0;
int len=0;
struct edge
{
	int x,y,next;
}e[10010];
bool tf=false,swapp=false;
bool v[10010];
bool vis[5010];
int first[5010];
int temp[5010],ans[5010];

inline int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if (c=='-') f=0;c=getchar();}
	while (c>='0' && c<='9') x=x*10+(c^48),c=getchar();
	return f?x:-x;
}

void ins(int x,int y)
{
	e[++len].x=x;e[len].y=y;
	e[len].next=first[x];first[x]=len;
}

void dfs1(int x,int fa)
{
	printf("%d ",x);
	priority_queue<int,vector<int>,greater<int> >q;
	for (int i=first[x];i;i=e[i].next)
		if (!vis[e[i].y]) 
			q.push(e[i].y),vis[e[i].y]=true;
	while (!q.empty())
	{
		int y=q.top();q.pop();
		if (y==fa) continue;
		dfs1(y,x);
	}
}

void dfs(int x,int fa)
{
	if (tf) return;
	temp[++tot]=x;
	if (!swapp && temp[tot]<ans[tot]) swapp=true;
	if (ans[tot]<temp[tot] && ans[tot]!=0 && !swapp) {tf=true;return;}
	priority_queue<int,vector<int>,greater<int> >q;
	for (int i=first[x];i;i=e[i].next)
		if (!vis[e[i].y] && !v[i]) 
			q.push(e[i].y),vis[e[i].y]=true;
	while (!q.empty())
	{
		int y=q.top();q.pop();
		if (y==fa) continue;
		dfs(y,x);if (tf) return;
	}
}

void init()
{
	tf=false;tot=0;swapp=false;
	for (int i=1;i<=n;i++) vis[i]=false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x,y;
		x=read(),y=read();
		ins(x,y);ins(y,x);
	}
	if (m==n-1)	{dfs1(1,0);return 0;}
	else
	{
		for (int i=1;i<=2*m;i+=2)
		{
			init();
			v[i]=v[i+1]=true;
			dfs(1,0);v[i]=v[i+1]=false;
			if (!tf && tot==n) 
			{
				for (int i=1;i<=n;i++) ans[i]=temp[i];
			}
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	return 0;
}
