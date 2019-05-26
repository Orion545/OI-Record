#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 5050

struct note
{
	int x,y,next,t;
};

struct note2
{
	int u,v;
};

note side[N*2];
note2 a[N*2];
int last[N],ans[N],b[N],t[N],c[N][N];
int n,m,l=0,tot;

void add(int x,int y)
{
	l++; c[x][y]=l;
	side[l].x=x;
	side[l].y=y; side[l].t=0;
	side[l].next=last[x];
	last[x]=l;
}

bool comp(note2 x,note2 y)
{
	return x.v>y.v;
}

void init()
{
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[i*2-1].u=x; a[i*2-1].v=y;
		a[i*2].u=y;   a[i*2].v=x;
	}
	sort(a+1,a+m*2+1,comp);
	memset(last,0,sizeof(last));
	for (int i=1;i<=2*m;i++)
	  add(a[i].u,a[i].v);
}

void dfs(int x,int fa)
{
	b[++tot]=x; t[x]=1;
	for (int i=last[x];i!=0;i=side[i].next)
	{
		int j=side[i].y;
		if (j==fa || side[i].t==1 || t[j]==1) continue;
		dfs(j,x);
	}
}

void pd()
{
	for (int i=1;i<=n;i++)
	{
		if (ans[i]<b[i]) return;
	  if (b[i]<ans[i]) 
	  {
	  	for (int j=i;j<=n;j++)
	  	  ans[j]=b[j];
	  	return;
	  }
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	if (m==n-1) 
	{
		tot=0;
		memset(t,0,sizeof(t));
		dfs(1,0);
		for (int i=1;i<=n;i++)
		  printf("%d ",b[i]);
		printf("\n");
	}
	else
	{
		ans[1]=n;
		for (int i=1;i<=2*m;i++)
		{
		  if (side[i].x>side[i].y) continue;
		  side[i].t=side[c[side[i].y][side[i].x]].t=1;
		  tot=0;
		  memset(t,0,sizeof(t));
		  dfs(1,0);
		  side[i].t=side[c[side[i].y][side[i].x]].t=0;
		  if (tot!=n) continue;
		  pd();
		}
		for (int i=1;i<=n;i++)
		  printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}

