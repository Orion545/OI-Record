#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=1e9;
int n,m,tot=1;
char sp[2];
int next[100001],to[100001],head[100001],cost[100001],zt[100001],dis[100001],fa[100001];
void add(int x,int y)
{
	next[tot]=head[x];
	head[x]=tot;
	to[tot++]=y;
}
void dfs(int u,int f)
{
	dis[u]=dis[f]+1;
	fa[u]=f;
	for(int x=head[u],v;x;x=next[x])
	{
		v=to[x];
		if(v==f)continue;
		dfs(v,u);
	}
}
int dfs1(int u,int f,int q)
{
	int sum=0;	
	if(zt[u])
	{
		if(zt[u]==2&&q==0)return inf;
		if(zt[u]==1&&q==1)return inf;
	}
	for(int x=head[u],v;x;x=next[x])
	{
		v=to[x];
		if(v==f)continue;
		int cnt1,cnt2;
		if(q==1)
		{
			cnt1=dfs1(v,u,1),cnt2=dfs1(v,u,0);
			if(zt[v]==2)
			{
				if(cnt1>=inf)return inf;
				else sum+=cnt1;
				continue;
			}
			else if(zt[v]==1)
			{
				if(cnt2>=inf)return inf;
				else sum+=cnt2;
				continue;
			}
			else 
			{
				if(cnt1>=inf&&cnt2>=inf)return inf;
				sum+=min(cnt1,cnt2);
				continue;
			}
		}
		else if(q==0)
		{
			cnt1=dfs1(v,u,1);
			if(cnt1==inf)return inf;
			else
			{
				if(zt[v]==1)return inf;
				sum+=cnt1;
				continue;
			}
		}
	}
	if(q==1)sum+=cost[u];
	return sum;
}
int main()
{
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);scanf("%s",sp);
	for(int i=1;i<=n;i++)scanf("%d",&cost[i]);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,0);
	for(int i=1,a,b,x,y;i<=m;i++)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		if(dis[a]<dis[b]){swap(a,b);swap(x,y);}
		if(x==0&&y==0&&fa[a]==b)
		{
			
			printf("-1\n");continue;
		}
		zt[a]=x+1,zt[b]=y+1;
		printf("%d\n",min(dfs1(1,0,1),dfs1(1,0,0)));
		zt[a]=zt[b]=0;
	}
	fclose(stdin);fclose(stdout);
}
