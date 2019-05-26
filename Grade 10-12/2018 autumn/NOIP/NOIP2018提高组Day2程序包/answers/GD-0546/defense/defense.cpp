#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2010;
namespace graph
{
	int h[N];
	int v[2*N];
	int t[2*N];
	int cnt;
	void add(int x,int y)
	{
		cnt++;
		v[cnt]=y;
		t[cnt]=h[x];
		h[x]=cnt;
	}
}
int c[N];
ll a[N];
ll f[N];
ll g[N];
void dfs(int x,int fa)
{
	f[x]=a[x];
	g[x]=0;
	if(c[x]==1)
		g[x]=1e12;
	if(c[x]==0)
		f[x]=1e12;
	for(int i=graph::h[x];i;i=graph::t[i])
		if(graph::v[i]!=fa)
		{
			int v=graph::v[i];
			dfs(v,x);
			f[x]+=min(f[v],g[v]);
			g[x]+=f[v];
		}
}

int n,m;
char str[10];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,str);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	int x,y,x2,y2;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		graph::add(x,y);
		graph::add(y,x);
	}
	memset(c,-1,sizeof c);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&x2,&y,&y2);
		c[x]=x2;
		c[y]=y2;
		dfs(1,0);
		ll ans=min(f[1],g[1]);
		if(ans>=1e11)
			printf("-1\n");
		else
			printf("%lld\n",ans);
		c[x]=-1;
		c[y]=-1;
	}
	return 0;
}
