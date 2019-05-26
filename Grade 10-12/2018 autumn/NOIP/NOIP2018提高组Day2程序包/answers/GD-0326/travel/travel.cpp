#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=15000;
const int INF=15000;

struct arr{
	int x,y;
	int next;
}edge[maxn];
int ls[maxn];
int edge_m;
int n,m;

int v[maxn];

void add(int x,int y)
{
	edge[++edge_m]=(arr){x,y,ls[x]},ls[x]=edge_m;
	return;
}

int ans[maxn];
int a[maxn];
int num=0;

void pan()
{
	int f=0;
	for (int i=1;i<=n;i++)
	{
		if (ans[i]>a[i])
		{
			f=1;
			break;
		} 
		if (ans[i]<a[i]) break;
	}
	if (f)
		for (int i=1;i<=n;i++)
			ans[i]=a[i];
}

int dfs(int x,int r)
{
	num++;
	a[num]=x;
	for (int i=ls[x];i;i=edge[i].next)
	{
		if (((v[1]==x)&&(v[2]==edge[i].y))||((v[1]==edge[i].y)&&(v[2]==x))) continue;
		if (edge[i].y==r) continue;
		dfs(edge[i].y,x);
	}
	return 0;
}

struct brr{
	int x,y;
}b[maxn],g[maxn];
int t=0,s=0;

bool cmp(brr c,brr d)
{
	if (c.x>d.x) return 1;
		else if ((c.x==d.x)&&(c.y>d.y)) return 1;
	return 0;
}

int vv[maxn];
int ff=0;

int origami(int x,int r)
{
	t++;
	g[t].x=r;g[t].y=x;
	vv[x]=1;
	for (int i=ls[x];i;i=edge[i].next)
	{
		if (edge[i].y==r) continue;
		if (vv[edge[i].y])
		{
			s=t;
			while (g[s].y!=edge[i].y) s--;
			g[s].x=x;
			ff=1;
			return 0;
		}
		origami(edge[i].y,x);
		if (ff) return 0;
	}
	t--;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		b[i+m].x=b[i].y;
		b[i+m].y=b[i].x;
	}
	sort(b+1,b+2*m+1,cmp);
	for (int i=1;i<=2*m;i++)
		add(b[i].x,b[i].y);
	if ((n-1)==m)
	{
		dfs(1,0);
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
	}
	else
	{
		memset(vv,0,sizeof(vv));
		for (int i=1;i<=n;i++) ans[i]=INF;
		origami(1,0);
		for (int i=s;i<=t;i++)
		{
			v[1]=g[i].x; v[2]=g[i].y;
			num=0;
			dfs(1,0);
			if (num==n)
				pan();
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
