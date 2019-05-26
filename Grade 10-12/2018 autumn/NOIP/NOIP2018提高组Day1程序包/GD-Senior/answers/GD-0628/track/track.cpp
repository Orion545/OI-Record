#include<cstdio>
#include<algorithm>
using namespace std;
struct Edge
{
	int to,nxt,val;
}e[200010];
int n,m,x,y,z,cnt,bj;
int h[200010],r[100010];
void add(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].nxt=h[u];e[cnt].val=w;h[u]=cnt;
}
bool cmp(Edge a,Edge b) { return a.val<b.val; }
void dfs(int u)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);add(x,y,z);add(y,x,z);
		r[x]++;r[y]++;if (x!=1) bj=1;	
	}
	if (m==1)
	{
		for(int i=1;i<=n;i++) if (r[i]==1) dfs(i);
	}
	else if (!bj)
	{
		sort(e+1,e+cnt+1,cmp);
	}
}
