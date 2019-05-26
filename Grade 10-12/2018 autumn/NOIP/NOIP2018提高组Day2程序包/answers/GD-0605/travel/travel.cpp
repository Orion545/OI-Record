#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#define N 5005
using namespace std;
int n,tot,last[N],next[N*2],tov[N*2],m,x,y,ans[N],bz[N],ll[N],h[N],t[N],ii,pp;
int ins(int x,int y){tov[++tot]=y,next[tot]=last[x],last[x]=tot;}
int dg(int x)
{
	ans[++ans[0]]=x,bz[x]=1;
	int g[N],tt=0;
	for (int i=last[x];i;i=next[i])
		if (!bz[tov[i]])
			g[++tt]=tov[i];
	sort(g+1,g+1+tt);
	for (int i=1;i<=tt;i++)
		if (!bz[g[i]])
			dg(g[i]);
}
int de(int x,int l,int u,int v)
{
	if (pp)
		return 0;
	t[++t[0]]=x,bz[x]=1;
	if (t[t[0]]>ans[t[0]]&&!ii)
	{
		pp=1;
		return 0;
	}
	if (t[t[0]]<ans[t[0]]||ii)
		ii=1,ans[t[0]]=t[t[0]];
	int g[N],tt=0;
	for (int i=last[x];i;i=next[i])
		if (l!=tov[i]&&(x!=u||tov[i]!=v)&&(x!=v||tov[i]!=u))
			g[++tt]=tov[i];
	sort(g+1,g+1+tt);
	for (int i=1;i<=tt;i++)
		if (!bz[g[i]])
			de(g[i],x,u,v);
}
int find(int x,int l)
{
	if (h[0])
		return 0;
	ll[++ll[0]]=x,bz[x]=1;
	for (int i=last[x];i;i=next[i])
	{
		if (h[0])
			break;
		int y=tov[i];
		if (bz[y])
		{
			if (y!=l)
			{
				for (int j=ll[0];j;j--)
					if (ll[j]!=y)
						h[++h[0]]=ll[j];
					else
						break;
				h[++h[0]]=y;
				return 0;
			}
			continue;
		}
		find(y,x);
	}
	--ll[0];
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
	if (n==m+1)
	{
		dg(1);
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	for (int i=1;i<=n;i++)
		ans[i]=n;
	find(1,0);
	for (int j=1;j<=n;j++)
			bz[j]=0;
	pp=0,ii=0,t[0]=0,de(1,0,h[1],h[h[0]]);
	for (int i=1;i<=h[0]-1;i++)
	{
		for (int j=1;j<=n;j++)
			bz[j]=0;
		pp=0,ii=0,t[0]=0,de(1,0,h[i],h[i+1]);
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
