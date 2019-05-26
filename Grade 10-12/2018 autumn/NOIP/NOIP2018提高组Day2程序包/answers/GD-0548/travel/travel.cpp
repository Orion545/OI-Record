#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5010;
int head[maxn],cnt=0,ans[maxn],tot=1,vis[maxn],f[maxn][maxn];

struct node{
	int to;
	int next;
	int flag;
}edge[maxn];

void add(int a,int b)
{
	edge[++cnt].next=head[a];
	edge[cnt].to=b;
	head[a]=cnt;
	edge[cnt].flag=1;
}

void dfs(int a)
{
	
	for(int j=1;j<=vis[a];j++)
	{
	tot++;
	int minn=99999,o,p,x;
	for(int i=head[a];i;i=edge[i].next)
	{
		if(f[a][edge[i].to])
		{
			int o=minn;
	        minn=min(minn,edge[i].to);
	        if(minn!=o)
	        x=edge[i].to;
		}	
	}
    ans[tot]=minn;
    vis[x]--;
	f[a][x]=f[x][a]=0;
	dfs(x);
	f[a][x]=f[x][a]=0;
	}
	return ;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(vis,0,sizeof(vis));
	memset(f,0,sizeof(f));
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		ans[i]=6000;
	ans[1]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		f[u][v]=f[v][u]=1;
		vis[u]++;
		vis[v]++;
	}
	if(n!=m)
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
