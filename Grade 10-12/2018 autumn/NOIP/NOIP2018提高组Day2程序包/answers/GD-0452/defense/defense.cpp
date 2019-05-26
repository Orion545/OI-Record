#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;

struct hh{
	int v,nex;
}e[200100];
int n,m,tot,tot1;
int head[100100],father[100100],leaf[100100];
bool vis[100100];
long long price[100100],dp[100100][2];

void readin()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
}

void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nex=head[u];
	head[u]=tot;
}

void dfs(int u)
{
	vis[u]=true;
	bool isleaf=true;
	for(int i=head[u];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			isleaf=false;
			father[v]=u;
			dfs(v);
		}
	}
	if(isleaf)
		leaf[++tot1]=u;
}

void dfs2(int u)
{
	if(u==1)
		return;
	dp[father[u]][0]=dp[u][1];
	dp[father[u]][1]=min(dp[u][0],dp[u][1])+price[father[u]];
	dfs(father[u]);
}

int main()
{
	readin();
	
	tot=tot1=0;
	int a,x,b,y,u,v;
	scanf("%d%d",&n,&m);
	char c=getchar();
	c=getchar();
	if(c=='A')
	{
		c=getchar();
		for(int i=1;i<=n;i++)
			scanf("%lld",&price[i]);
		for(int i=1;i<=n-1;i++)
			scanf("%d%d",&u,&v);
		for(int j=1;j<=m;j++)
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(abs(a-b)==1&&x==0&&y==0)
			{
				puts("-1");
				continue;
			}
			memset(dp,0,sizeof(dp));
			dp[1][0]=0;
			dp[1][1]=price[1];
			if((a==1||b==1)&&(x==1||y==1))
				dp[1][0]=400000000000;
			if((a==1||b==1)&&(x==0||y==0))
				dp[1][1]=400000000000;
			for(int i=2;i<=n;i++)
			{
				if(i==a&&x==1)
				{
					dp[i][0]=400000000000;
					dp[i][1]=min(dp[i-1][0],dp[i-1][1])+price[i];
				}
				else
				if(i==a&&x==0)
				{
					dp[i][0]=dp[i-1][1];
					dp[i][1]=400000000000;
				}
				else
				if(i==b&&y==1)
				{
					dp[i][0]=400000000000;
					dp[i][1]=min(dp[i-1][0],dp[i-1][1])+price[i];
				}
				else
				if(i==b&&y==0)
				{
					dp[i][0]=dp[i-1][1];
					dp[i][1]=400000000000;
				}
				else
				{
					dp[i][0]=dp[i-1][1];
					dp[i][1]=min(dp[i-1][0],dp[i-1][1])+price[i];
				}
			}
			printf("%lld\n",min(dp[n][0],dp[n][1]));
		}
	}
	else
	{
		c=getchar();
		for(int i=1;i<=n;i++)
			scanf("%d",&price[i]);
		for(int i=1;i<=n-1;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1);
		
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(x==1)
				dp[a][0]=400000000000;
			else
			if(x==0)
				dp[a][1]=400000000000;
			else
			if(y==1)
				dp[b][0]=400000000000;
			else
			if(y==0)
				dp[b][1]=400000000000;
			for(int j=1;j<=tot1;j++)
			{
				dp[leaf[j]][0]=0;
				dp[leaf[j]][1]=price[leaf[j]];
				dfs2(leaf[j]);
			}
			printf("%d\n",min(dp[1][0],dp[1][1]));
		}
	}
}
