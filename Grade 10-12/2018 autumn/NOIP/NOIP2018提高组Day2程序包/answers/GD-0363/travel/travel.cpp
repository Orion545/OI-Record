#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=5005;
int n,m;
vector<int> vec[N];
int fa[N],dep[N];
bool vis[N];
int gg=0;
void dfs (int x)
{
	vis[x]=true;
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (vis[y]&&dep[x]>dep[y]+1)
		{
		//	printf("YES:%d %d\n",x,y);
			int now=x;
			while (now!=y)	
			{
				if (now>x) 
				{
					int ff=fa[now],siz1=vec[ff].size();
					if (vec[ff][siz1-1]==now)	gg=now;
				}
				now=fa[now];
			}
		}
		if (vis[y]) continue;
		dep[y]=dep[x]+1;fa[y]=x;
		dfs(y);
	}
}
int ans[N],tot=0;
void solve (int x)
{
	ans[++tot]=x;vis[x]=true;
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (dep[y]>dep[x]&&y==gg) continue;
		if (vis[y]) continue;
		solve(y);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	for (int u=1;u<=n;u++) sort(vec[u].begin(),vec[u].end());
	memset(vis,false,sizeof(vis));
	fa[1]=0;dep[1]=1;dfs(1);
	memset(vis,false,sizeof(vis));
//	printf("%d\n",gg);
	solve(1);
	for (int u=1;u<=tot;u++) printf("%d ",ans[u]);
	return 0;
}
