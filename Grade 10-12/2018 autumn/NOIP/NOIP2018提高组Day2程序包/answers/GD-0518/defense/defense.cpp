#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
const int M=200005;
const long long inf=0x3fffffffffffffffll;
int n,m;
char type[255];
int a[N],u,v,x,y;
int h[N],to[M],nx[M],cnt;
int lim[N];
long long f[N][2];
long long pre[N],suf[N];
long long ans;
void addedge(int u,int v)
{
	cnt++;
	to[cnt]=v;
	nx[cnt]=h[u];
	h[u]=cnt;
}
void dp(int u,int p)
{
	f[u][0]=f[u][1]=0;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=p)
		{
			dp(to[i],u);
			f[u][0]+=f[to[i]][1];
			f[u][1]+=min(f[to[i]][0],f[to[i]][1]);
			if (f[u][0]>inf)
				f[u][0]=inf;
			if (f[u][1]>inf)
				f[u][1]=inf;
		}
	f[u][1]+=a[u];
	if (f[u][1]>inf)
		f[u][1]=inf;
	if (lim[u]==0)
		f[u][1]=inf;
	if (lim[u]==1)
		f[u][0]=inf;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",type+1);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	if (n<=2000&&m<=2000)
	{
		for (int i=1;i<=n;i++)
			lim[i]=-1;
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&u,&x,&v,&y);
			lim[u]=x;
			lim[v]=y;
			dp(1,0);
			if (min(f[1][0],f[1][1])!=inf)
				printf("%lld\n",min(f[1][0],f[1][1]));
			else
				printf("-1\n");
			lim[u]=lim[v]=-1;
		}
	}
	else
		if (type[1]=='A'&&type[2]=='2')
		{
			for (int i=1;i<=n;i++)
				if (i==1)
					pre[i]=a[i];
				else
					pre[i]=min(pre[i-2],pre[i-1])+a[i];
			for (int i=n;i;i--)
				if (i==n)
					suf[i]=a[i];
				else
					suf[i]=min(suf[i+2],suf[i+1])+a[i];
			for (int i=1;i<=m;i++)
			{
				ans=0;
				scanf("%d%d%d%d",&u,&x,&v,&y);
				if (u>v)
				{
					swap(u,v);
					swap(x,y);
				}
				if (x==0)
					ans+=pre[u-1];
				else
					ans+=pre[u];
				if (y==0)
					ans+=suf[v+1];
				else
					ans+=suf[v];
				if (x==0&&y==0)
					ans=-1;
				printf("%lld\n",ans);
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
