#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=2e9;
int p[1005];
vector<int> g[1005];
int aa[105],bb[105];
bool vis[1005];
int minn;
int mon[1005];
int a,x,b,y;
int n,m;
void dfs(int u,int s)
{
	bool tf=true;
	for(int i=1;i<n;i++)
	{
		if(mon[aa[i]]=false&&mon[bb[i]]==false)
		{
			tf=false;
			break;
		}
	}
	if(tf&&s<minn&&mon[a]==x&&mon[b]==y) minn=s;
	for(int i=0;i<g[u].size();i++)
	{
		if(!vis[g[u][i]])
		{
			vis[g[u][i]]=true;
			dfs(g[u][i],s);
			vis[g[u][u]]=false;
		}
	}
	mon[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		if(!vis[g[u][i]])
		{
			vis[g[u][i]]=true;
			dfs(g[u][i],s+p[u]);
			vis[g[u][u]]=false;
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char yy[29];
	scanf("%d%d",&n,&m);
	scanf(" %s",yy);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	int t1,t2;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
		aa[i]=t1;
		bb[i]=t2;
	}
	while(m--)
	{
		for(int j=1;j<=n;j++)
		{
			vis[j]=false;
			mon[j]=0;
		}
		scanf("%d%d%d%d",&a,&x,&b,&y);
		minn=INF;
		vis[1]=true;
		dfs(1,0);
		if(minn!=INF) printf("%d\n",minn);
		else printf("-1");
	}
	return 0;
}
