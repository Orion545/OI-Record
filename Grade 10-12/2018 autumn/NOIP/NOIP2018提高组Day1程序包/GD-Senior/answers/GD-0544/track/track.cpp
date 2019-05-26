#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

struct node
{
	int x,y,d,next;
}a[110000];int len,last[51000];
void ins(int x,int y,int d)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].d=d;
	a[len].next=last[x];last[x]=len;
}
int f[51000],g[51000];
int z,u[51000];
int fa[51000];
int findfa(int x)
{
	if(x==fa[x])return x;
	fa[x]=findfa(fa[x]);return fa[x];
}
void dfs(int x,int fr,int mid)
{
	g[x]=0;
	for(int k=last[x];k;k=a[k].next)
		if(a[k].y!=fr)dfs(a[k].y,x,mid),g[x]+=g[a[k].y];
	
	z=0;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fr)
		{
			if(f[y]+a[k].d>=mid)g[x]++;
			else u[++z]=f[y]+a[k].d,fa[z]=z;
		}
	}
	fa[z+1]=z+1;
	
	sort(u+1,u+z+1);
	for(int i=1;i<=z;i++)
	{
		if(fa[i]!=i)continue;
		int j=lower_bound(u+1,u+z+1,mid-u[i])-u;
		j=findfa(j);
		if(i==j)j=findfa(j+1);
		if(j<=z)
		{
			fa[i]=i+1;
			fa[j]=j+1;
			g[x]++;
		}
	}
	f[x]=0;
	for(int i=z;i>=1;i--)
		if(fa[i]==i){f[x]=u[i];break;}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,x,y,dd;
	scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&dd);
		ins(x,y,dd),ins(y,x,dd);
	}
	int l=0,r=1e9,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		dfs(1,0,mid);
		if(g[1]>=m)
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
