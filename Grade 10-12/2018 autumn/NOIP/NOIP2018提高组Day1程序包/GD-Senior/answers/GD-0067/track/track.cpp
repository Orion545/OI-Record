#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int to,next,w;
}e[620000];
queue<int> q;
int n,m,i,j,k,l,dis[310000],cnt,h[310000],x,y,z,ans,fa[310000];
bool vis[310000];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].to=y;
	e[cnt].next=h[x];
	e[cnt].w=z;
	h[x]=cnt;
}
void spfa(int x)
{
	vis[x]=true;
	q.push(x);
	while (!q.empty())
	{
		int u;
		u=q.front();
		for (int i=h[u]; i ;i = e[i].next)
		{
			if (dis[e[i].to]<dis[u]+e[i].w&&e[i].to!=fa[u])
			{
				dis[e[i].to]=dis[u]+e[i].w;
				fa[e[i].to]=u;
				if (vis[e[i].to]==false)
				{
					vis[e[i].to]=true;
					q.push(e[i].to);
				}
			}
		}
		vis[u]=false;
		q.pop();
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(dis,0,sizeof(dis));
	for (int i=1; i<=n-1; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for (int i=1; i<=n; i++)
	add(0,i,0),dis[i]=-1,fa[i]=i;
	dis[0]=0;
	spfa(0);
	for (int i=1; i<=n; i++)
	ans=max(ans,dis[i]);
	printf("%d",ans);
	return 0;
}
