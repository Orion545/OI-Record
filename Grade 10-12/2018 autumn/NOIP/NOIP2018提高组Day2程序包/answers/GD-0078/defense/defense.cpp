#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const ll inf=1e12;
int fa[100010];
int n,m,a,b,x,y,reta,retb,w[100010];char _type1[3];
struct path{int y,nxt;}g[200010];int h[100010];
ll dp[100010][2];
void dfs(int x,int f)
{
	dp[x][0]=0,dp[x][1]=w[x];fa[x]=f;
	for (int i=h[x];i;i=g[i].nxt)
	if (g[i].y!=f){
		dfs(g[i].y,x);
		dp[x][0]+=dp[g[i].y][1];
		dp[x][1]+=min(dp[g[i].y][1],dp[g[i].y][0]);
	}	
	dp[x][0]=min(dp[x][0],inf);
	dp[x][1]=min(dp[x][1],inf);	
	if (a==x) if (reta) dp[x][0]=inf;else dp[x][1]=inf;
	if (b==x) if (retb) dp[x][0]=inf;else dp[x][1]=inf;
}
ll dp1[100010][2];
void work(int x)
{
	for (;fa[x];x=fa[x])
	{
		dp1[fa[x]][0]=dp[fa[x]][0];dp1[fa[x]][1]=dp[fa[x]][1];
		dp1[fa[x]][0]-=dp[x][0];dp1[fa[x]][1]-=min(dp[x][1],dp[x][0]);
		dp1[fa[x]][0]+=dp1[x][1];dp1[fa[x]][0]+=min(dp1[x][0],dp1[x][1]);
	}
}
ll l[100010][2],r[100010][2];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&_type1);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[i*2-1]=path{y,h[x]};h[x]=i*2-1;
		g[i*2]=path{x,h[y]};h[y]=i*2;
	}
	if (n<=2000)
	{
		while (m--)
		{
			scanf("%d%d%d%d",&a,&reta,&b,&retb);
			dfs(1,0);
			if (min(dp[1][1],dp[1][0])>=inf) puts("-1");else
			printf("%lld\n",min(dp[1][1],dp[1][0]));
		}	return 0;	
	}
	if (_type1[0]=='A'&&_type1[1]=='2')
	{
		for (int i=1;i<=n;i++) l[i][0]=l[i-1][1],l[i][1]=min(l[i-1][0],l[i-1][1])+w[i];
		for (int i=n;i;i--) r[i][0]=r[i+1][1],r[i][1]=min(r[i+1][0],r[i+1][1])+w[i];
		while (m--)
		{
			scanf("%d%d%d%d",&a,&reta,&b,&retb);
			if (a>b) swap(a,b),swap(reta,retb);
			if (!reta&&!retb) puts("-1");
			else if (!reta) printf("%lld\n",l[a][0]+r[b][1]);
			else printf("%lld\n",l[a][1]+r[b][0]);
		}
	}
	if (_type1[0]=='B'&&_type1[1]=='1')
	{
		dfs(1,0);
		while (m--)
		{
			scanf("%d%d%d%d",&a,&reta,&b,&retb);
			dp1[b][0]=dp[b][0];dp1[b][1]=dp[b][1];
			dp1[b][retb^1]=inf;
			work(b);
			printf("%lld\n",dp1[1][1]);
			for (;b;b=fa[b]) dp1[b][0]=dp1[b][1]=0;
		}
	}
	return 0;
}
