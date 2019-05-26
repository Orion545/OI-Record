#include <cstdio>
#include <algorithm>
using namespace std;
const int N=50005;
const int E=100005;
int n,m;
int u,v,w;
int h[N],to[E],nx[E],wt[E],cnt;
int ans;
int l,r,mid;
int f[N],g[N];
bool vis[N];
void addedge(int u,int v,int w)
{
	cnt++;
	to[cnt]=v;
	nx[cnt]=h[u];
	wt[cnt]=w;
	h[u]=cnt;
}
void check(int u,int p)
{
	f[u]=0;
	int cnt;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=p)
			check(to[i],u);
	cnt=0;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=p)
		{
			cnt++;
			g[cnt]=f[to[i]]+wt[i];
			vis[cnt]=0;
		}
	sort(g+1,g+cnt+1);
	while (g[cnt]>=mid&&cnt>0)
	{
		ans++;
		vis[cnt]=1;
		cnt--;
	}
	int l,c,lp;
	c=cnt;
	l=1;
	lp=0;
	while (l<cnt)
	{
		while (g[l]+g[cnt]<mid&&l<cnt)
			l++;
		if (l>=cnt)
			break;
		ans++;
		lp=l;
		l++;
		cnt--;
	}
	cnt=lp+1;
	while (lp)
	{
		while (g[lp]+g[cnt]<mid&&cnt<c)
			cnt++;
		if (cnt>c)
			break;
		if (g[lp]+g[cnt]>=mid)
		{
			vis[lp]=1;
			vis[cnt]=1;
			cnt++;
		}
		lp--;
	}
	for (int i=1;i<=c;i++)
		if (!vis[i])
			if (g[i]>f[u])
				f[u]=g[i];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
		r+=w;
	}
	while (l<r)
	{
		mid=(l+r+1)>>1;
		ans=0;
		check(1,0);
		if (ans>=m)
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
