#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=5005;

int n,m,cur;
int ans[maxn],oup[maxn];
vector<int> g[maxn];

void dfs(int u,int father)
{
	ans[++cur]=u;
	int v;
	for (int i=0; i<g[u].size(); i++)
	{
		v=g[u][i];
		if (v!=father)
			dfs(v,u);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
	}
	
	for (int i=1; i<=n; i++)
	{
		sort(g[i].begin(),g[i].end());
	}
	
	dfs(1,1);
	
	printf("%d",ans[1]);
	for (int i=2; i<=n; i++)
		printf(" %d",ans[i]);
	
	return 0;
}
