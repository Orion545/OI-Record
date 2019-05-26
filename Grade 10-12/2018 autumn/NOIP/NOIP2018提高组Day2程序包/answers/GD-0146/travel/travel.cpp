#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int vis[5050];
bool g[5050][5050];
int a[5050];
void dfs(int before,int now)
{
	printf("%d ",now);
	for(int i=1;i<=n;i++)
	{
		if(g[now][i])
		{
			if(vis[i]==0)
			{
				vis[i]++;
				dfs(now,i);
			}
		}
		else if(n==m)
		{
			if(g[before][i])
			{
				if(vis[before]==1&&vis[i]==0)
				{
					vis[before]++;
					vis[i]++;
					dfs(before,i);
				}
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=1;
		g[v][u]=1;
	}
	vis[1]=1;
	dfs(1,1);
	return 0;
}
