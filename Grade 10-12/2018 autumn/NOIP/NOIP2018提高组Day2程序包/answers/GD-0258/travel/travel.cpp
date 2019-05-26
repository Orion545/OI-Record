#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,m,k;
int ans[5050],vis[5050];
vector<int>G[50100],G2[50100];
struct node
{
	int from;
	int To;
}edge[5010];
void addline(int a,int b)
{
	G[a].push_back(b);
}
void addline2(int a,int b)
{
	G[a].push_back(b);
}
bool cmp(node x,node y)
{
	return x.from<y.from||(x.from==y.from)&&x.To<y.To;
}
void find(int now)
{
	ans[++k]=now;
	vis[now]=1;
	for(int i=0;i<G[now].size();i++)
	{
		if(vis[G[now][i]]==0)
		find(G[now][i]);
	}
}
/*void find2(int now,int p)
{
	nowans[p]=now;
	vis2[now]=1;
	for(int i=0;i<G2[now].size();i++)
	{
		if(vis2[G2[now][i]]==0)
		find2[G2[now][i],p+1];
	}
}*/
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&edge[i].from,&edge[i].To);
		if(edge[i].from>edge[i].To) swap(edge[i].from,edge[i].To);
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		addline(edge[i].from,edge[i].To);
		addline(edge[i].To,edge[i].from);
	}
	ans[1]=edge[1].from;
	find(1);
	
	for(int i=1;i<=k;i++)
	cout<<ans[i]<<" ";
	
	/*if(n<1000&&m==n)
	{
		for(int i=1;i<=m;i++)
	{
		addline2(edge[i].from,edge[i].To);
		addline2(edge[i].To,edge[i].from);
	}
		for(int i=1;i<=n;i++)
		find2(i,1);
	}*/
	return 0;
}

