#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
	int u,v,w,next;
};

const int maxN=50000;
int n,m,tmp=0,sum=0;
int head[maxN+5],vis[maxN+5];
node edge[2*maxN+5];

void addedge(int x,int y,int z)
{
	tmp++;
	edge[tmp].u=x;
	edge[tmp].v=y;
	edge[tmp].w=z;
	edge[tmp].next=head[x];
	head[x]=tmp;
}

bool check(int x)
{
	int i,tot=0,sum=0,x1;
	
	memset(vis,0,sizeof(vis));
	vis[1]=1;	x1=1;	i=head[x1];
	while (i)
	{
		if (vis[edge[i].v]==1)
		{
			i=edge[i].next;
			continue;
		}
		sum+=edge[i].w;
		vis[edge[i].v]=1;
		x1=edge[i].v;	i=head[x1];
		if (sum>=x)
		{
			tot++;
			sum=0;
		}
		if (tot>=m)
			return true;
	}
	if (tot<m)
		return false;
}

void erfen()
{
	int l,r,mid;
	
	l=1;r=sum;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (check(mid)==true)
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",r);
}

bool cmp(node x,node y)
{
	if (x.w==y.w)
		return x.u<y.u;
	else
		return x.w<y.w;
}

bool check1(int x)
{
	int i,tot=0,sum=0;
	
	memset(vis,0,sizeof(vis));
	for (i=1;i<=tmp;i++)
	{
		if (edge[i].u==1)
		{
			if (vis[edge[i].v]==1)
				continue;
			else
				vis[edge[i].v]=1;
		}
		else
		{
			if (vis[edge[i].u]==1)
				continue;
			else
				vis[edge[i].u]=1;
		}
			
		sum+=edge[i].w;
		if (sum>=x)
		{
			sum=0;
			tot++;
		}
		if (tot>=m)
			return true;
	}
	return false;
}

void erfen1()
{
	int l=1,r=sum,mid;
	
	sort(edge+1,edge+tmp+1,cmp);
	while (l<=r)
	{
		mid=(l+r)/2;
		if (check1(mid)==true)
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",r);
}

int main()
{
	int i,x,y,z,tai=0,tbi=0;
	
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		sum+=z;
		if (x!=1)
			tai=1;
		if (y!=x+1)
			tbi=1;
		addedge(x,y,z);
		addedge(y,x,z);
	}
	if (tbi==0)
		erfen();
	else if (tai==0)
		erfen1();
		
	
	return 0;
}
