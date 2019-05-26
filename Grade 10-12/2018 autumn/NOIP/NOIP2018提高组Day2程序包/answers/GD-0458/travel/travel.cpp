#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define mmst(a, b) memset(a,b,sizeof(a))
#define mmcp(a, b) memcpy(a,b,sizeof(a))

using namespace std;

typedef long long LL;

const int N=5050;

int n,m,ans[N],ans2[N],biu;

int st[N],tp;
int num[N],mp[N][N];
int fa[N];
int Cut;
bool vis[N];

void dfs(int x)
{
	ans[++biu]=x;
	vis[x]=1;
	for(int i=1;i<=num[x];i++)
	if(!vis[mp[x][i]])
	{
		fa[mp[x][i]]=x;
		dfs(mp[x][i]);
	}
	else
	if(mp[x][i]!=fa[x]&&!tp)
	{
		int y=x;
		while(y!=mp[x][i])
		{
			st[++tp]=y;
			y=fa[y];
		}
	}
}

void dfs2(int x)
{
	ans2[++biu]=x;
	vis[x]=1;
	for(int i=1;i<=num[x];i++)
	{
		int to=mp[x][i];
		if(vis[to])
		continue;
		if(x==Cut&&to==fa[Cut])
		continue;
		if(to==Cut&&x==fa[Cut])
		continue;
		dfs2(to);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		mp[u][++num[u]]=v;
		mp[v][++num[v]]=u;
	}
	
	for(int i=1;i<=n;i++)
	sort(mp[i]+1,mp[i]+num[i]+1);
	
	dfs(1);
	
	if(m==n)
	{
		for(int i=1;i<=tp;i++)
		{
			biu=0;
			mmst(vis,0);
			Cut=st[i];
			
			dfs2(1);
			
			bool ok=false;
			for(int i=1;i<=n;i++)
			if(ans[i]!=ans2[i])
			{
				if(ans[i]>ans2[i])
				ok=true;
				break;
			}
			if(ok)
			for(int i=1;i<=n;i++)
			ans[i]=ans2[i];
		}
	}
	
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	
	cout<<endl;
	
	return 0;
}

