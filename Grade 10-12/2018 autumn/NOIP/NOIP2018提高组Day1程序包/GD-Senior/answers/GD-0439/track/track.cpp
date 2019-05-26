#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{int to,next,w;}e[100010];
int head[50010],cnt,L,tot,n,m,a[50010],vis[50010];
void add(int u,int v,int w)
{
	e[++cnt]=(edge){v,head[u],w};
	head[u]=cnt;
}
int dfs(int u,int fa)
{
	int max1=0,max2=0,max3=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		int t=dfs(v,u)+e[i].w;
		if(t>=L){tot++;continue;}
		if(t>max1)
		{
			max3=max2;
			max2=max1;
			max1=t;
		}
		else if(t>max2)
		{
			max3=max2;
			max2=t;
		}
		else if(t>max3)max3=t;
	}
	if(max3+max2>L) {tot++;return max1;}
	if(max3+max1>L) {tot++;return max2;}
	if(max1+max2>L) {tot++;return max3;}
	return max1;
}
bool check(int t)
{
	tot=0;
	L=t;
	dfs(1,-1);
	return tot>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	int l=0,r=500000000,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	if(check(mid))printf("%d\n",mid);
	else printf("%d\n",mid-1);
	return 0;
}
