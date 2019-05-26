#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int>e[5010];
int ban1,ban2,ans[5010],vis[5010],t[5010],flag,pos;
void dfs(int u,int fa)
{
	pos++;
	t[pos]=u;
	vis[u]=1;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa||(v==ban1&&u==ban2)||(v==ban2&&u==ban1)||vis[v]) continue;
		dfs(v,u); 
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
	memset(ans,127,sizeof(ans));
	if(m==n)
	{
		for(int i=1;i<=n;i++) 
		for(int j=0;j<e[i].size();j++) 
		{
			memset(vis,0,sizeof(vis));
			ban1=i;ban2=e[i][j];
			flag=0;pos=0;
			dfs(1,-1);
			if(pos<n) continue;
			for(int k=1;k<=n;k++) 
			{
				if(ans[k]<t[k]) {flag=1;break;}
			    if(ans[k]>t[k]) {flag=-1;break;}
			}
			if(flag==-1) for(int k=1;k<=n;k++) ans[k]=t[k];
		}
	}
	else 
	{
		flag=0;pos=0;
		dfs(1,-1);
		for(int k=1;k<=n;k++) ans[k]=t[k];
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
