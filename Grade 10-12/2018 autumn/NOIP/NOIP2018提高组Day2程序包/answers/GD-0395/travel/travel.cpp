#include<cstdio>
#include<cstring>
using namespace std;
int n,m,num,front[5005],ans[5005],path[5005];
bool vis1[5005],vis2[5005],ok;
struct node
{
	int v,nxt;
}p[5005];
void add(int u,int v)
{
	p[++num].v=v;
	p[num].nxt=front[u];
	front[u]=num;
}
void minn()
{
	for(int i=1;i<=n;i++)
	{
		if(ans[i]<path[i])break;
		if(ans[i]>path[i])
		{
			for(int j=1;j<=n;j++)
			ans[j]=path[j];
			break;
		}
	}
}
void dfs(int u,int d)
{
	if(d==n)
	{
		ok=1;minn();return;
	}
	for(int i=front[u];i;i=p[i].nxt)
	{
		if(!vis1[p[i].v])
		{
			vis1[p[i].v]=1;
			path[d+1]=p[i].v;
			dfs(p[i].v,d+1);
			vis1[p[i].v]=0;
			path[d+1]=0;
			continue;
		}
		if(vis1[p[i].v]&&!vis2[p[i].v])
		{
			vis2[p[i].v]=1;
			dfs(p[i].v,d);
			vis2[p[i].v]=0;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)ans[i]=5000;
	for(int i=1;i<=n;i++)
	{
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		memset(path,0,sizeof(path));
		if(ok)break;
		vis1[i]=1;
		path[1]=i;
		dfs(i,1);
	}
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}
