#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxm=500000;

struct lu{
	int u,v,next;
}e[maxm];

int cnt=0,head[maxm];
void add(int u,int v)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

int cun[maxm],vis[maxm],cot=0;
void bfs(int k)
{
	printf("%d ",k);
	vis[k]=1;
	int qi=cot;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=head[k];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!vis[v]) q.push(v);
	}
	while(!q.empty())
	{
		int x=q.top();q.pop();
		bfs(x);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	bfs(1);
	return 0;
}
