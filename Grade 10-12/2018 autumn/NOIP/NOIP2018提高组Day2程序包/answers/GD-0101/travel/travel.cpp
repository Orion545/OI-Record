#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int cur,n,m,Ans,
	head[100005],ans[100005];
struct EDGE{
	int t,next;
}e[100005];
void add(int a,int b)
{
	cur++;
	e[cur].t=b;
	e[cur].next=head[a];
	head[a]=cur;
}
void DFS_t(int u,int fa)
{
	ans[++Ans]=u;
	priority_queue < int > nxt;
	for (int h=head[u];h!=-1;h=e[h].next)
	{
		int v=e[h].t;
		if (v==fa) continue;
		nxt.push(-v);
	}
	while (!nxt.empty())
	{
		int t=nxt.top();
		DFS_t(-t,u);
		nxt.pop();
	}
}
bool vis[5005];
void DFS_g(int u,int fa)
{
	vis[u]=1;
	ans[++Ans]=u;
	priority_queue < int > nxt;
	for (int h=head[u];h!=-1;h=e[h].next)
	{
		int v=e[h].t;
		if (v==fa) continue;
		if (vis[v]) continue;
		nxt.push(-v);
	}
	while (!nxt.empty())
	{
		int t=nxt.top();
		DFS_g(-t,u);
		nxt.pop();
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof head);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	if (m==n-1)
	{
		DFS_t(1,-1);
		for (int i=1;i<=Ans;i++)
			printf("%d ",ans[i]);
	}
	else
	{
		DFS_g(1,-1);
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}
