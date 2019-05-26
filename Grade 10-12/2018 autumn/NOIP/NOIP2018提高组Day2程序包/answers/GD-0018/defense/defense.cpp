#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int tot;
int cost[100010],fir[100010],must[100010],vis[100010];
struct edge
{
	int to;
	int next;
}e[200010];
void add(int x,int y)
{
	tot++;
	e[tot].to=y;
	e[tot].next=fir[x];
	fir[x]=tot;
}
long long dfs(int p,int pd)
{
	if(vis[p]) return 0;
	else vis[p]=1;
	long long ans=0;
	if(pd==1) ans+=(long long)(cost[p]);
	for(int i=fir[p];i;i=e[i].next)
	{
		if(pd==0) 
		{
			if(must[e[i].to]==0) return 0;
			else ans+=dfs(e[i].to,1);
		}
		else 
		{
			if(must[e[i].to]==-1) ans+=min(dfs(e[i].to,0),dfs(e[i].to,1));
			else ans+=dfs(e[i].to,must[e[i].to]);
		}
	}
	vis[p]=0;
 	return ans;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,a,b,c,d;
	string s;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	add(0,1);
	add(1,0);
	for(int i=1;i<=m;i++)
	{
		memset(must,-1,sizeof(must));
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d",&a,&b,&c,&d);
		must[a]=b;
		must[c]=d;
		int ok=0;
		for(int j=fir[a];j;j=e[j].next)
		{
			if(e[j].to==c&&must[a]==0&&must[c]==0) 
			{
				ok=1;
				break;
			}
		}
		if(ok) printf("-1\n");
		else printf("%lld\n",dfs(0,1));
	}
	return 0;
}
