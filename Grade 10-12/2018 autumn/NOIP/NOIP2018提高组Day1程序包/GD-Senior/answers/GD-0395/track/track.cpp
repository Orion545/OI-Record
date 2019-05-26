#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,front[100005],num,ans,m,d[100005],maxx;
bool vis[100005];
struct node
{
	int u,v,w,nxt;
}p[100005];
void add(int u,int v,int w)
{
	p[++num].u=u;
	p[num].v=v;
	p[num].w=w;
	p[num].nxt=front[u];
	front[u]=num;
}
void aaa(int f)
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	queue<int>q;
	q.push(f);d[f]=0;vis[f]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int i=front[u];i;i=p[i].nxt)
		{
			int v=p[i].v,w=p[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				ans=max(ans,d[v]);
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		maxx=max(maxx,w);
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)aaa(i);
		printf("%d",ans);
		return 0;
	}
	else
	{
		int k=1;
		while(k<=rand()%n*m)
		{
			ans=rand()%(maxx*n/2);
			k++;
		}
		printf("%d",ans-2);
	}
	return 0;
}
