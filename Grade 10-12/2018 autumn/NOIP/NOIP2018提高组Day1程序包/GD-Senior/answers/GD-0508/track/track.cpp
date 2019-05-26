#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
int n,m,inf;
struct node
{
	int x,y,z;
}e[50005];
int head[N],next[N],val[N],go[N];
int q[N],tot,dis[50005],vis[50005];
int a[N],sum[N];
inline void add(int x,int y,int z)
{
	go[++tot]=y;
	val[tot]=z;
	next[tot]=head[x];
	head[x]=tot;
}
inline bool cmpz(node a,node b)
{
	return a.z<b.z;
}
inline bool cmpx(node a,node b)
{
	return a.x<b.x;
}
inline void spfa(int s)
{
	memset(dis,127/3,sizeof(dis));inf=dis[0];
	vis[s]=1;
	dis[s]=0;int t=0,w=1;
	q[1]=s;
	while (t<w)
	{
		int x=q[++t];
		for(int i=head[x];i;i=next[i])
		{
			int v=go[i];
			if (dis[x]+val[i]<dis[v])
			{
				dis[v]=dis[x]+val[i];
				if (!vis[v])
				{
					vis[v]=1;
					q[++w]=v;
				}
			}
		}
		vis[x]=0;
	}
}
inline bool pd(int x)
{
	int i=1,j=0,num=0;
	while (i<n)
	{
		j=i+1;
		while(j<n&&sum[j]-sum[i]<x)j++;
		if (sum[j]-sum[i]>=x)num++;
		i=j;
	}
	if (num>=m)return 1;
	else return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=1,flag1=1;
	fo(i,1,n-1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x>y)swap(x,y);
		e[i].x=x,e[i].y=y,e[i].z=z;
		add(x,y,z),
		add(y,x,z);	
		if (x+1!=y)flag=0;
		if (x!=1)flag1=0;
	}
	if (m==1)
	{
		spfa(1);
		int mx=0,id=0;
		fo(i,1,n)
		if (dis[i]>mx&&dis[i]!=inf)mx=dis[i],id=i;
		spfa(id);
		mx=0;
		fo(i,1,n)
		if (dis[i]>mx&&dis[i]!=inf)mx=dis[i];
		printf("%d\n",mx);
		return 0;
	}
	else if(m==n-1)
	{
		sort(e+1,e+1+n-1,cmpz);
		printf("%d\n",e[n-1].z);
		return 0;
	}
	else if (flag)//a[i]+1=b[i]
	{
		a[1]=0;sort(e+1,e+1+n-1,cmpx);
		fo(i,2,n)a[i]=e[i-1].z,sum[i]=sum[i-1]+a[i];
		int l=1,r=1e9,ans=0;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (pd(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	else if (flag1)//a[i]=1
	{
		sort(e+1,e+1+n-1,cmpz);
		int ans=1e9;
		if (m*2>n)
		{
			int i=n-1;
			while (i>=1)
			{
				m--;
				if (m*2<=i)
				{
					int j=i-m*2+1;
					while (m>0&&i>j)
					{
						ans=min(ans,e[i].z+e[j].z);
						j++,i--,m--;
					}
					printf("%d\n",ans);
					return 0;
				}
				ans=min(ans,e[i].z);
				i--;
			}
		}
		else
		{
			int i=n-1;
			int j=i-m*2+1;
			while (m>0&&i>j)
			{
				ans=min(ans,e[i].z+e[j].z);
				i--,j++,m--;
			}
			printf("%d\n",ans);
			return 0;
		}
	}
	return 0;
} 
