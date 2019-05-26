#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
	struct forward_star
	{
		int next,to;
	};
	int n,m,cnt,a,x,b,y;
	char type[3];
	int cost[1000001];
	forward_star edge[2000001];
	int head[1000001];
	long long dp[1000001][3];
	bool usable[2000001];
	bool vis[1000001];
void add(int u,int v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
void build(int now)
{
	vis[now]=true;
	int i=head[now];
	while (i!=0)
	{
		if (!vis[edge[i].to])
			build(edge[i].to);
		else usable[i]=false;
		i=edge[i].next;
	}
}
void treedp(int now)
{
	int i=head[now];
	long long k=2147483647;
	bool flag=false;
	bool leaf=true;
	while (i!=0)
	{
		if (usable[i])
		{
			leaf=false;
			treedp(edge[i].to);
			if (dp[edge[i].to][2]==-1)
			{
				flag=true;
				dp[now][2]+=dp[edge[i].to][1];
			}
			else
			{
				dp[now][2]+=dp[edge[i].to][2];
				if (dp[edge[i].to][1]!=-1)
				{
					k=min(k,dp[edge[i].to][1]-dp[edge[i].to][2]);
					dp[now][0]+=min(dp[edge[i].to][1],dp[edge[i].to][2]);
					dp[now][1]+=min(dp[edge[i].to][1],min(dp[edge[i].to][0],dp[edge[i].to][2]));
				}
				else
				{
					dp[now][0]+=dp[edge[i].to][2];
					dp[now][1]+=min(dp[edge[i].to][0],dp[edge[i].to][2]);
				}
			}
		}
		i=edge[i].next;
	}
	if (leaf)
	{
		dp[now][0]=0;
		dp[now][1]=cost[now];
		dp[now][2]=cost[now];
	}
	else
	{
		if (!flag&&k!=2147483647) dp[now][2]+=k;
			else if (k==2147483647&&!flag) dp[now][2]=-1;
		dp[now][1]+=cost[now];
	}
	if (a==now)
		if (x==0)
			dp[now][1]=-1;
		else if (x==1)
		{
			dp[now][0]=-1;
			dp[now][2]=-1;
		}
	if (b==now)
		if (y==0)
			dp[now][1]=-1;
		else if (y==1)
		{
			dp[now][0]=-1;
			dp[now][2]=-1;
		}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",type+1);
	for (int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	memset(usable,true,sizeof(usable));
	build(1);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(dp,0,sizeof(dp));
		treedp(1);
		if (dp[1][1]==-1)
		{
			if (dp[1][2]==-1)
				printf("-1\n");
			else printf("%lld\n",dp[1][2]);
		}
		else
		{
			if (dp[1][2]==-1)
				printf("%lld\n",dp[1][1]);
			else printf("%lld\n",min(dp[1][1],dp[1][2]));
		}
	}
	return 0;
}
