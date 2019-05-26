#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define inf 200000000
using namespace std;

int n,m;int a,x,b,y;
string s;
int dp[100005][2],p[100005];
int cnt;
int head[100005],next[100005],to[100005];

void add(int u,int v)
{
	to[++cnt]=v;
	next[cnt]=head[u];
	head[u]=cnt;
}

bool check(int u,int v)
{
	for(int i=head[u];i;i=next[i])
	{
		if(to[i]==v)return 1;
	}
	return 0;
}

int dps(int u,int f,int fa)
{
	
	if(dp[u][f]!=0) return dp[u][f];
	if(f==0)
	{
		int t=0;
		for(int i=head[u];i;i=next[i])
		{
			int v=to[i];
			if(v==fa) continue;
			t+=dps(v,1,u);
		}
		dp[u][0]=t;
//		cout<<u<<" "<<f<<" "<<t<<endl;
		return dp[u][0];
	}
	else
	{
		int t=p[u];
		for(int i=head[u];i;i=next[i])
		{
			int v=to[i];
			if(v==fa) continue;
			t+=min(dps(v,1,u),dps(v,0,u));
		}
		dp[u][1]=t;
//		cout<<u<<" "<<f<<" "<<t<<endl;
		return dp[u][1];
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	cin>>s;
	
	for(i=1;i<=n;i++)scanf("%d",&p[i]);
	
	for(i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}

	for(i=1;i<=m;i++)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d%d",&a,&x,&b,&y);
		dp[a][!x]=inf;
		dp[b][!y]=inf;	
		if(x==0&&y==0)
		{
			if(check(a,b))printf("-1\n");
			continue;
		}
		int ans=min(dps(1,1,1),dps(1,0,1));
		if(ans==inf)ans=-1;
		printf("%d\n",ans);
	}
}
