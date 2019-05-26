#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 2139062143
using namespace std;
struct edge{ll to,next;}e[5010];
ll head[2010],v[2010],dp[2010][2],cnt,q1,q2,t1,t2,n,m;
void add(ll u,ll v)
{
	e[++cnt]=(edge){v,head[u]};
	head[u]=cnt;
}
void dfs(ll u,ll fa)
{
	dp[u][1]=v[u];dp[u][0]=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(fa==v) continue;
		dfs(v,u);
		dp[u][1]+=min(dp[v][0],dp[v][1]);
		dp[u][0]+=dp[v][1];
	}
	if(q1==u)dp[u][!t1]=inf;
	if(q2==u)dp[u][!t2]=inf;
	dp[u][0]=min(dp[u][0],(ll)inf);
	dp[u][1]=min(dp[u][1],(ll)inf);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char opt[10];
	scanf("%lld %lld %s",&n,&m,opt);
	for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
    for(int i=1;i<n;i++)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		add(x,y);add(y,x);
	}
	while(m--)
	{
		memset(dp,127,sizeof(dp));
		scanf("%lld%lld%lld%lld",&q1,&t1,&q2,&t2);
		dfs(1,-1);
		if(min(dp[1][0],dp[1][1])>=inf)printf("-1\n");
		else if(q1==1)printf("%lld\n",dp[1][t1]);
		else if(q2==1)printf("%lld\n",dp[1][t2]);
		else printf("%lld\n",min(dp[1][0],dp[1][1]));
	}
	return 0;
}
