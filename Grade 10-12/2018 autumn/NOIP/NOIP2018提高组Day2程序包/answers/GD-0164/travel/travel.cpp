#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct data{
	int f,t;
}bian[10010];
struct node{
	int n,t;
}e[10010];
int n,m,h[5010],tot,d[5010];

bool cmp1(data a,data b)
{
	return a.f == b.f ? a.t > b.t : a.f < b.f;
}


void add(int u,int v)
{
	e[++ tot].n = h[u];
	e[tot].t = v;
	h[u] = tot;
}

void dfs1(int x,int dep)
{
	d[x] = dep;
	printf("%d ",x);
	for (int i = h[x];i;i = e[i].n)
	{
		int y = e[i].t;
		if (d[y]) continue;
		dfs1(y,dep + 1);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i ++)
	{
		scanf("%d%d",&bian[i].f,&bian[i].t);
		bian[m + i].t = bian[i].f;
		bian[m + i].f = bian[i].t;
	}
		
	sort(bian + 1,bian + 1 + 2 * m,cmp1);
	for (int i = 1;i <= 2 * m;i ++) add(bian[i].f,bian[i].t);
		dfs1(1,1);
	
	return 0;
}
