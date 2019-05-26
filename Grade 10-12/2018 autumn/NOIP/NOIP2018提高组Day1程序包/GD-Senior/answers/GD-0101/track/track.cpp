#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int cur,n,m,Max,OK=1,OK2=1,
	head[50005],l[50005],l2[50005],
	f[1005][100005],g[1005][100005];
struct EDGE{
	int t,next,l;
}e[50005];
void add(int a,int b,int c)
{
	cur++;
	e[cur].t=b;
	e[cur].next=head[a];
	e[cur].l=c;
	head[a]=cur;
}
bool Check(int x)
{
	int sum=0,ans=0;
	for (int i=1;i<n;i++)
	{
		sum+=l[i];
		if (sum>=x)
		{
			ans++;sum=0;
		}
	}
	return ans>=m;
}
bool cmp(int a,int b)
{
	return a>b;
}
void DFS(int u,int fa,int mid)
{
	int leaf=1;
	g[u][0]=1;
	for (int h=head[u];h!=-1;h=e[h].next)
	{
		int v=e[h].t,l=e[h].l;
		if (v==fa) continue;
		leaf=0;
		DFS(v,u,mid);
		for (int i=0;i<=mid;i++)
		{
			if (i+l>=mid&&g[v][i])
				f[u][0]=max(f[u][0],f[v][i]+1);
			else
			{
				g[u][i+l]|=g[u][i];
				f[u][i+l]=max(f[v][i],f[u][i+l]);
			}
		}
	}
}
bool Check1(int x)
{
	for (int i=1;i<=n;i++)
		for (int j=0;j<=x;j++)
			f[i][j]=0;
	DFS(1,0,x);
	int ans=0;
	for (int i=0;i<=x;i++)
	{
		ans=max(f[1][i],ans);
	}
//	printf("%d %d %d\n",x,f[1][19],f[1][12]);
	return ans>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof head);
	int MIN=2000000000;
	for (int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
		Max+=c;
		MIN=min(MIN,c);
		if (b!=a+1&&a!=b+1)
			OK=false;
		if (a!=1)
		{
			OK2=false;
		}
		l[a]=c;
		l2[b]=c;
	}
	if (OK)
	{
		int lo=1,hi=Max;
		while (lo+1<hi)
		{
			int mid=(lo+hi)/2;
			if (Check(mid))
				lo=mid;
			else
				hi=mid;
		}
		printf("%d",lo);
	}
	else
	if (OK2)
	{
		sort(l2+1,l2+n+1,cmp);
		int Min=2000000000;
		for (int i=1;i<=m;i++)
			if (l2[i]+l2[2*m-i+1]<Min)
				Min=l2[i]+l2[2*m-i+1];
		printf("%d\n",Min);
	}
	else
	if (m==n-1)
		printf("%d",MIN);
	else
	{
		int lo=1,hi=Max;
		while (lo+1<hi)
		{
			int mid=(lo+hi)/2;
			if (Check1(mid))
				lo=mid;
			else
				hi=mid;
		}
		printf("%d",lo);
	}
	return 0;
}
