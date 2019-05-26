#include<bits\stdc++.h>
using namespace std;
int tmp1[10002][2],num,tot,n,m,next[10002],yy[10002],h[5002],ans[5002],rightans[5002];
bool vis[5002];
struct node{
	int xx,yy;
}	g[5002];
bool cmp(node l,node r)
{
	return ((l.xx<r.xx) || ((l.xx==r.xx) && (l.yy>r.yy)));
}
void build(int l,int r)
{
	yy[++tot]=r;
	next[tot]=h[l];
	h[l]=tot;
}
void dfs(int x)
{
	printf("%d ",x);
	vis[x]=1;
	for(int i=h[x];i;i=next[i]) 
	{
		int y=yy[i];
		if (!vis[y])
		{
			dfs(y);
		}
	}
}
void dfs1(int x)
{
	vis[x]=1;
	for(int i=h[x];i;i=next[i]) 
	{
		int y=yy[i];
		if (!vis[y])
		{
			ans[++num]=y;
			if (num==n)
			{
				bool p=0;
				for(int j=1;j<=num;j++)
				if (ans[j]>rightans[j]) 
				{
					p=0;
					break;
				}
				else if (ans[j]<rightans[j])
				{
					p=1;
					break;
				}
				if (p) for(int j=1;j<=num;j++) rightans[j]=ans[j];
			}
			dfs1(y);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==m+1)
	{
		for(int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[i].xx=x;
		g[i].yy=y;
		g[i+m].xx=y;
		g[i+m].yy=x;
	}
	sort(g+1,g+1+2*m,cmp);
	for(int i=1;i<=2*m;i++)build(g[i].xx,g[i].yy);
		dfs(1);
		return 0;
	}
	if (n<=100)
	{
			for(int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[i].xx=x;
		g[i].yy=y;
		g[i+m].xx=y;
		g[i+m].yy=x;
		tmp1[i][0]=x,tmp1[i][1]=y;
	}
	for(int j=1;j<=n;j++) rightans[j]=n;
	for(int i=1;i<=n;i++) 
	{
		if (i==2)
		{
			double tyy=12.19;
		}
		memset(yy,0,sizeof(yy));
		memset(next,0,sizeof(next));
		memset(h,0,sizeof(h));
		memset(vis,0,sizeof(vis));
		num=0;
		for(int j=1;j<=m;j++) 	g[j].xx=tmp1[j][0],g[j].yy=tmp1[j][1],g[j+m].xx=g[j].yy,g[j+m].yy=g[j].xx;
		g[i].xx=0,g[i+m].xx=0;
		sort(g+1,g+1+2*m,cmp);
	for(int j=1;j<=2*m;j++) if (g[j].xx)build(g[j].xx,g[j].yy);
	ans[++num]=1;
	dfs1(1);
	}
		for(int j=1;j<=n;j++) printf("%d ",rightans[j]);
		return 0;
	}
	for(int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[i].xx=x;
		g[i].yy=y;
		g[i+m].xx=y;
		g[i+m].yy=x;
	}
	sort(g+1,g+1+2*m,cmp);
	for(int i=1;i<=2*m;i++)build(g[i].xx,g[i].yy);
		dfs(1);
		return 0;
	
}
