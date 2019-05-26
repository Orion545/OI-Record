#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int n,m;
bool e[5005][5005],f[5005];
vector<int>r[5005];
void dfs(int u,int fa)
{
	printf("%d ",u);
	for(int i=1;i<=n;i++)
	{
		if(f[i]) continue;
		if(e[u][i])
		{
			f[i]=true;
			dfs(i,u);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=true;
		//r[u].push_back(v);
		//r[v].push_back(u);
	}
	f[1]=true;
	dfs(1,0);
	return 0;
}
