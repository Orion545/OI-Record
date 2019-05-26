#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> e[5005];
int n,m;
int tot;
bool incircle[5005];
bool vis[5005];
int fa[5005];
int c1,c2,tmp;
bool flAg=false;
void dfs1(int u,int fa)
{
	register int i,v;
	tot++;
	printf("%d",u);
	if(tot==n)
	putchar('\n');
	else
	putchar(' ');
	for(i=0;i<e[u].size();i++)
	{
		v=e[u][i];
		if(v!=fa)
		dfs1(v,u);
	}
}
void dfs(int u,int father)
{
	vis[u]=1;
	fa[u]=father;
	register int i,v;
	for(i=0;i<e[u].size();i++)
	{
		v=e[u][i];
		if(vis[v]&&v!=father&&!flAg)
		{
			c1=u,c2=v;
			flAg=true;
		}
		
		if(vis[v]) continue;
		dfs(v,u);
	}
}
void dfs2(int u,int minname)
{
	vis[u]=1;
	register int i,v;
	printf("%d ",u);
	for(i=0;i<e[u].size();i++)
	{
		v=e[u][i];
		if(vis[v]) continue;
		if(incircle[u]&&incircle[v]&&v>minname&&!vis[minname]) return;
		int low;
		if(i<e[u].size()-1&&!) low=min(minname,e[u][i+1]);
		if(vis[v]) continue;
		vis[v]=1;
		dfs2(v,minname);
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	register int a,b,c,d;
	for(a=1;a<=m;a++)
	{
		scanf("%d%d",&b,&c);
		e[b].push_back(c);
		e[c].push_back(b);
	}
	for(a=1;a<=n;a++)
	sort(e[a].begin(),e[a].end());
	if(m==n-1)
	dfs1(1,0);
	else
	{
		dfs(1,0);
		int u=c1;
		while(u!=c2)
		{
			incircle[u]=true;
			u=fa[u];
		}
		incircle[u]=true;
		tmp=c1;
		memset(vis,0,sizeof vis);
		dfs2(1,1e9);
	}
	return 0;
}
/*
10 10
1 2
2 3
3 4
4 9
1 5
5 6
6 7
7 8
8 9
2 10
*/
