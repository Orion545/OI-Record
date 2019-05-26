#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int num,head[50050],out[50050],ans;
struct node
{
	int from,to,value;
	int nex;
	friend bool operator < (node a,node b)
	{
		return a.value>b.value;
	}
}edge[100050];
bool vis[50050];
int n,m;
void add(int u,int v,int w)
{
	edge[++num].from=u;
	edge[num].to=v;
	edge[num].value=w;
	edge[num].nex=head[u];
	head[u]=num;
}
void dfs(int now,int sum)
{
	if(out[now]==1)ans=max(ans,sum);
	vis[now]=1;
	for(int i=head[now];i;i=edge[i].nex)
	if(!vis[edge[i].to])
	dfs(edge[i].to,sum+edge[i].value);
	vis[now]=0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.ans","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		out[u]++;
		out[v]++;
	}
	for(int i=1;i<=n;i++)
	if(out[i]==1)dfs(i,0);
	printf("%d",ans);
	return 0;
}
