#include<cstdio>
#include<cstring>
#include<vector> 
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5005;
int n,m,num1=0,g[maxn][maxn],ans[maxn],tmp[maxn],f[maxn],cur[maxn];
bool vis[maxn];
void dfs(int x,int fa)
{
	++num1;
	printf("%d",x);
	if (num1!=n)printf(" ");
		else printf("\n");
	for (int i=1;i<=g[x][0];i++)
		if (g[x][i]!=fa)dfs(g[x][i],x);
}

void check()
{
	for (int i=1;i<=n;i++)
		if (tmp[i]>ans[i])return;
	for (int i=1;i<=n;i++)ans[i]=tmp[i];
}
void dfs1(int x,int fa,int num)
{
	if (f[x]==-1)f[x]=fa;	
	if (tmp[num]==0)tmp[num]=x;
	if (num==n)
	{
		check();
		return;
	}
	for (int& i=cur[x];i<g[x][0];i++)
	{
		if (g[x][i+1]!=fa && f[g[x][i+1]]==-1)dfs1(g[x][i+1],x,num+1);
		if (g[x][i+1]==f[x])dfs1(g[x][i+1],x,num);
	}
	if (tmp[num]==x)
	{
		tmp[num]=0;
		f[x]=-1;
		cur[x]=0;
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(cur,0,sizeof(cur));
	memset(vis,false,sizeof(vis));
	memset(f,-1,sizeof(f));
	memset(ans,0x3f,sizeof(ans));
	memset(g,0,sizeof(g));
	for (int i=1;i<=m;i++)
	{
		int j,l;
		scanf("%d%d",&j,&l);
		g[j][++g[j][0]]=l;
		for (int k=g[j][0]-1;k>=1;k--)
			if (g[j][k]>g[j][k+1])swap(g[j][k],g[j][k+1]);
		g[l][++g[l][0]]=j;
		for (int k=g[l][0]-1;k>=1;k--)
			if (g[l][k]>g[l][k+1])swap(g[l][k],g[l][k+1]);
	}
	if (m==n-1)dfs(1,0);
	if (m==n)
	{
		dfs1(1,0,1);
		for (int i=1;i<=n-1;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}
