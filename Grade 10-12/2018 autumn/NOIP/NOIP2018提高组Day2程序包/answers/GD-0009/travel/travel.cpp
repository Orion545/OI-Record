#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 5000+200
int n,m,tot,dt;
int last[N],pre[2*N],link[2*N],ans[N];
int cl[N],dfn[N],low[N],st[N],clt,clk[N],lt;
bool vis[N],bf,bw,br;
void mlink(int x,int y)
{
	pre[++tot]=last[x],last[x]=tot,link[tot]=y;
}
void dfs(int x,int las)
{
	dfn[x]=++dt,low[x]=dt;
	st[++st[0]]=x;
	for(int i=last[x];i;i=pre[i])
	{
		if(link[i]==las)
			continue;
		if(!vis[link[i]])
		{
			vis[link[i]]=1;
			dfs(link[i],x);
			low[x]=min(low[x],low[link[i]]);
		}
		else
			low[x]=min(low[x],dfn[link[i]]);
	}
	if(low[x]<=dfn[x]&&!cl[x])
	{
		clt++;
		while(dfn[st[st[0]]]!=low[x])
			cl[st[st[0]--]]=clt,clk[clt]++;
		cl[st[st[0]--]]=clt,clk[clt]++;
	}
}
void dfs1(int x)
{
	if(!vis[x])ans[++ans[0]]=x,vis[x]=1;
	else return;
	int tmp[N],ti=0;
	for(int i=last[x];i;i=pre[i])
	{
		if(!vis[link[i]])
			tmp[++ti]=link[i];
	}
	sort(tmp+1,tmp+ti+1);
	if(clk[cl[x]]>1)
	{
		if(ti==1&&tmp[ti]>lt&&!br)
		{
			br=1;
			return;
		}
		if(!bf)
		{
			bf=1;
			bool bw=0;
			for(int i=1;i<=ti;i++)
			{
				if(clk[cl[tmp[i]]]>1&&bw)
				{
					lt=tmp[i];
					break;
				}
				if(clk[cl[tmp[i]]]>1&&!bw)
					bw=1;
			}
			for(int i=1;i<=ti;i++)
				dfs1(tmp[i]);
		}
		else
		{
			for(int i=1;i<=ti;i++)
				dfs1(tmp[i]);
		}
		
	}
	else
		for(int i=1;i<=ti;i++)
			dfs1(tmp[i]);
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
		mlink(x,y),mlink(y,x);
	}
	vis[1]=1;
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	dfs1(1);
	for(int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
}
