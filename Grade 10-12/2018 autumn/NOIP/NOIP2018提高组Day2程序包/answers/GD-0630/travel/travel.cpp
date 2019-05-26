#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
int n,m;
struct DR
{
	int a,b;
}dr[20000],yb[20000];
bool cmp(const DR&a,const DR&b)
{
	if(a.a!=b.a)return a.a<b.a;
	return a.b>b.b;
}
struct Edge
{
	int t,nexty;
}edge[20000];
int head[20000]={0},cnt=0;
void add(int a,int b)
{
	cnt++;
	edge[cnt].t=b;
	edge[cnt].nexty=head[a];
	head[a]=cnt;
}
int sz[20000],gs=0;
int zy[20000];int visit[20000]={0},vishu=1;
void dfs(int node,int fa,int a,int b)
{
	if(visit[node]==vishu)return;
	visit[node]=vishu;
	sz[++gs]=node;
	for(int i=head[node];i;i=edge[i].nexty)
	{
		if(edge[i].t==fa)continue;
		if(node==a&&edge[i].t==b)continue;
		if(node==b&&edge[i].t==a)continue;
		dfs(edge[i].t,node,a,b);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool tf=true;if(m==n)tf=false;
	for(int i=1;i<=m;i++)scanf("%d%d",&dr[i].a,&dr[i].b);
	for(int i=1;i<=m;i++)yb[i]=dr[i];
	for(int i=m+1;i<=2*m;i++)dr[i].a=dr[i-m].b,dr[i].b=dr[i-m].a;
	m*=2;
	sort(dr+1,dr+m+1,cmp);
	for(int i=1;i<=m;i++)add(dr[i].a,dr[i].b);
	if(tf)
	{
		gs=0;dfs(1,0,0,0);
		for(int i=1;i<=gs;i++)printf("%d ",sz[i]);
		printf("\n");
	}
	else
	{
		zy[1]=2e9;
		for(int i=1;i<=m/2;i++)
		{
			gs=0;dfs(1,0,yb[i].a,yb[i].b);
			vishu++;
			if(gs!=n)continue;
			for(int j=1;j<=n;j++)
			{
				if(zy[j]<sz[j])break;
				if(sz[j]<zy[j])
				{
					for(int k=1;k<=n;k++)zy[k]=sz[k];
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",zy[i]);
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
