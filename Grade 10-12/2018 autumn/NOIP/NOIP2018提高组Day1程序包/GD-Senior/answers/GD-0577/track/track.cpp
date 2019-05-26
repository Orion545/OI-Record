#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
	int n,m,len=0,ans,mi;
	struct node1{int x,y,z,next;} a[100010];
	int last[100010],dep[100010],dis[100010],d[100010],f[50010][20];
void ins(int x,int y,int z)
{
	a[++len]=(node1){x,y,z,last[x]}; last[x]=len;
}
bool check1(int x)
{
	mi=2147483647;
	int tot=d[1],k=1;
	for(int i=2;i<n;i++)
		if(tot+d[i]>x)
		{
			mi=min(tot,mi);
			tot=d[i];
			k++;
		} else tot+=d[i];
	mi=min(mi,tot);
	return k<=m;
}
void dfs(int x)
{
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(dep[y]) continue;
		dis[y]=dis[x]+a[i].z;
		dep[y]=dep[x]+1;
		f[y][0]=x;
		dfs(y);
	}
}
void init()
{
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--)
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int DIS(int x,int y)
{
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int x,y,z;
	int l=0,r=0,mid;
	bool flag1=true,flag2=true;
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		r+=z;
		d[i]=z;
		ins(x,y,z),ins(y,x,z);
		if(x!=1) flag1=false;
		if(y!=x+1) flag2=false;
	}
	if(flag2)
	{
		ans=2147483647;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check1(mid)) ans=min(ans,mi),r=mid-1; else l=mid+1;
		}
		printf("%d",ans);
		return 0;
	}
	if(m==1)
	{
		dfs(1);
		init();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,DIS(i,j));
		printf("%d",ans);
		return 0;
	}
	if(flag1)
	{
		sort(d+1,d+n-1+1,cmp);
		printf("%d",d[m]+d[2*m]);
		return 0;
	}
	printf("%d\n",r/m);
	return 0;
}
