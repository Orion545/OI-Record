#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#define N 5005

using namespace std;
int head[N],tail[N],now[N],line[5*N];
int t[N];
int n,m,xx,yy,cnt,tot;
bool check[N];
int ans[N];
int p[N];

struct E
{
	int x,y;	
}; E e[2*N];

bool cmp(E a,E b)
{
	if (a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}

void dfs_Tree (int xx)
{
	printf("%d ",xx);
	check[xx]=true;
	for (int i=head[xx];i<=tail[xx];i++)
	if (not(check[e[i].y])) dfs_Tree(e[i].y);
}

void work()
{
	for (int i=1;i<=n;i++)
	if (ans[i]<p[i]) return;
	for (int i=1;i<=n;i++)
	ans[i]=p[i];
}

void dfs(int xx, int dep)
{
	check[xx]=true;
	now[++cnt]=xx;
	printf("%d ",xx);
	memset(line,0,sizeof(line));
	tot=0;
	for (int i=1;i<=cnt;i++)
	{
		for (int j=head[now[i]];j<=tail[now[i]];j++)
		if (check[e[j].y]==false) line[++tot]=e[j].y;
	}
	sort(line+1,line+tot+1);
	for (int i=1;i<=tot;i++)
	dfs(line[i],dep+1);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(ans,127/3,sizeof(ans));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&xx,&yy);
		e[++cnt].x=xx; e[cnt].y=yy;
		e[++cnt].x=yy; e[cnt].y=xx;
	}
	sort(e+1,e+2*m+1,cmp);
	head[1]=1;
	int tot=1;
	for (int i=2;i<=2*m;i++) 
	if (tot!=e[i].x) tail[tot]=i-1,head[++tot]=i;
	tail[tot]=2*m;
	memset(check,false,sizeof(check));
	tot=0;
	cnt=0;
	if (m==n-1) dfs_Tree(1);
	else dfs(1,1);
}




