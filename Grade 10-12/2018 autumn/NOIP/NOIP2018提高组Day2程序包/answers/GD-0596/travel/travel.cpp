#include<map>
#include<list>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int>a[5005];
bool vis[5005];
bool d[5005];
int c[5005];
int s[5005];
int b[5005];
int cnt=0,n,m,cnt_=0,p=0,fg=1;
void dfs(int u)
{
	vis[u]=1;
	s[++cnt]=u;
	sort(a[u].begin(),a[u].end());
	for(int i=0;i<a[u].size();i++)if(!vis[a[u][i]])dfs(a[u][i]);
}
void dfs(int u,int fa)
{
	c[u]=1;
	for(int i=0;i<a[u].size();i++)if(c[a[u][i]]==0)dfs(a[u][i],u);
	else if(c[a[u][i]]==1&&a[u][i]^fa)
	{
		p=a[u][i];
		break;
	}
	if(p)d[u]=1;
	if(p==u)p=0;
	c[u]=-1;
}
void dfs_(int u)
{
	if(d[u]&&p&&!vis[p]&&(b[cnt_]<u||(cnt_==0&&p<u)))
	{
		p=0;
		return;
	}
	vis[u]=1;
	s[++cnt]=u;
	sort(a[u].begin(),a[u].end());
	if(d[u]&&fg)
	{
		fg=0;
		for(int i=0;i<a[u].size();i++)if(d[a[u][i]])p=a[u][i];
	}
	for(int i=0;i<a[u].size();i++)if(!vis[a[u][i]])
	{
		if(d[a[u][i]])for(int j=a[u].size()-1;j>i;j--)b[++cnt_]=a[u][j];
		dfs_(a[u][i]);
		if(b[cnt_]==a[u][i])cnt_--;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(n^m)dfs(1);
	else
	{
		dfs(1,0);
		dfs_(1);
	}
	for(int i=1;i<=cnt;i++)printf("%d ",s[i]);
	return 0;
}
