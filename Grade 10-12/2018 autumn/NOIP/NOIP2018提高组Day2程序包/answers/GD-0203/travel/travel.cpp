#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;
struct CC
{
	int x,y;
}a[2*5010];
struct node
{
	int to,next;
}edge[2*5010];
bool visit[5010],f[5010];
bool flag;
int head[5010],p[5010],fat[5010],b[5010][5010],ans[5010];
int n,m,cnt,m1,cnt1,cnt2,sum;

void addedge(int x,int y) 
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}

bool rmp(CC x,CC y) 
{
	if (x.x==y.x) return x.y>y.y;
	return x.x<y.x;
}

void dfs(int u,int fa) 
{
	if (!visit[u]) 
	{
		visit[u]=true;
		printf("%d ",u);
	}
	int now=head[u];
	while (now!=0) 
	{
		int v=edge[now].to;
		now=edge[now].next;
		if (v==fa) continue;
		dfs(v,u);
	}
}

void dfs1(int u,int fa) 
{
	if (flag) return;
	if (!visit[u]) visit[u]=true;
	int now=head[u];
	while (now!=0 && !flag) 
	{
		int v=edge[now].to;
		now=edge[now].next;
		if (v==fa) continue;
		if (v!=fa && visit[v]) 
		{
			flag=true;
			int now1=u;
			while (now1!=v) 
			{
				p[++cnt1]=now1;
				now1=fat[now1];
			}
			p[++cnt1]=v;
			continue;
		}
		fat[v]=u;
		dfs1(v,u);
	}
}

void dfs2(int u,int fa,int x,int y) 
{
	if (!visit[u]) 
	{
		visit[u]=true;
		b[sum][++cnt2]=u;
	}
	int now=head[u];
	while (now!=0) 
	{
		int v=edge[now].to;
		now=edge[now].next;
		if ((u==x && v==y) || (u==y && v==x)) continue;
		if (v==fa) continue;
		dfs2(v,u,x,y);
	}
}

void judge() 
{
	for (int i=1;i<=n;i++) 
	{
		int smin=5010;
		for (int j=1;j<=cnt1;j++) 
		if (f[j])	smin=min(smin,b[j][i]);
		for (int j=1;j<=cnt1;j++) if (b[j][i]>smin) f[j]=false;
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		m1++;
		scanf("%d%d",&a[m1].x,&a[m1].y);
		m1++;a[m1].x=a[m1-1].y;a[m1].y=a[m1-1].x;
	}
	sort(a+1,a+m1+1,rmp);
	for (int i=1;i<=m1;i++) addedge(a[i].x,a[i].y);
	for (int i=1;i<=n;i++) visit[i]=false;
	if (m==n-1) 
	{
		dfs(1,0);
	} else 
	{
		fat[1]=0;
		flag=false;
		dfs1(1,0);
		for (int i=1;i<=cnt1-1;i++) 
		{
			for (int j=1;j<=n;j++) visit[j]=false;
			sum++;cnt2=0;
			dfs2(1,0,p[i],p[i+1]);
		}
		for (int j=1;j<=n;j++) visit[j]=false;
		sum++;cnt2=0;
		dfs2(1,0,p[cnt1],p[1]);
		for (int i=1;i<=cnt1;i++) f[i]=true;
		judge();
		for (int i=1;i<=cnt1;i++) if (f[i]) for (int j=1;j<=n;j++) ans[j]=b[i][j];
		for (int j=1;j<=n;j++) printf("%d ",ans[j]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
