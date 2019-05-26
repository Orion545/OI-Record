#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=150000;
const int INF=2000000000;

struct arr{
	int x,y;
	int next;
}edge[maxn*2];
int ls[maxn];
int edge_m;
int n,m;

int v[maxn];

void add(int x,int y)
{
	edge[++edge_m]=(arr){x,y,ls[x]},ls[x]=edge_m;
	edge[++edge_m]=(arr){y,x,ls[x]},ls[y]=edge_m;
	return;
}

int f[maxn][3];

int a,b;
int aa,bb;
int dfs(int x,int r)
{
	int small=INF;
	int wz=0;
	for (int i=ls[x];i;i=edge[i].next)
	{
		if (edge[i].y==r) continue;
		dfs(edge[i].y,x);
		int y=edge[i].y;
		f[x][0]+=min(min(f[y][0],f[y][1]),f[y][2]);
		if (small>f[y][1]) wz=y;
		small=min(small,f[y][1]);
		f[x][2]+=min(f[y][0],f[y][1]);
	}
	for (int i=ls[x];i;i=edge[i].next)
	{
		if (edge[i].y==r) continue;
		if (edge[i].y==wz)
			f[x][1]+=small;
		else f[x][1]+=min(f[x][1],f[x][0]);
	}
	if (x==a)
		if (aa)
			f[x][0]=INF;
		else f[x][1]=INF,f[x][2]=INF;
	if (x==b)
		if (bb)
			f[x][0]=INF;
		else f[x][1]=INF,f[x][2]=INF;
}


char c;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>c;
	cin>>c;
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&aa,&b,&bb);
		memset(f,0,sizeof(f));
		dfs(1,0);
		printf("%d\n",min(f[1][0],f[1][1]));	
	}
	
}
