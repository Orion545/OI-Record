#include<cstdio>
#include<algorithm>
#define MAXN 100000+10

using namespace std;

struct edgevf
{
	int v,next;
};

inline int read()
{
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

edgevf e[(MAXN)<<1];
int p[MAXN],dp[MAXN][2],w[MAXN];
bool usd[MAXN],flg=0;
int n,m,st1,st2,qe1,qe2,topv=0;

void dfs1(int x)
{
	dp[x][0]=0;
	dp[x][1]=w[x];
	for(int i=p[x]; i; i=e[i].next)
		if(!usd[e[i].v])
		{
			if(e[i].v!=st1&&e[i].v!=st2)
			{
				usd[e[i].v]=1;
				dfs1(e[i].v);
				if(dp[x][0]!=0x7fffffff)
					dp[x][0]+=dp[e[i].v][1];
				dp[x][1]+=min(dp[e[i].v][1],dp[e[i].v][0]);
			}
			else
			{
				if(e[i].v==st1)
				{
					usd[e[i].v]=1;
					dfs1(e[i].v);
					if(qe1==0) dp[x][0]=0x7fffffff;
					else dp[x][0]+=dp[e[i].v][qe1];
					dp[x][1]+=dp[e[i].v][qe1];
				}
				else
				{
					if(e[i].v==st2)
					{
						usd[e[i].v]=1;
						dfs1(e[i].v);
						if(qe2==0) dp[x][0]=0x7fffffff;
						else dp[x][0]+=dp[e[i].v][qe2];
						dp[x][1]+=dp[e[i].v][qe2];
					}
				}
			}
		}
}

void dfs2(int x,int fa)
{
	if((x==st1&&fa==st2)||(x==st2&&fa==st1)) 
	{
		flg=1;
		return ;
	}
	for(int i=p[x]; i; i=e[i].next)
		if(e[i].v!=fa&&!flg)
			dfs2(e[i].v,x);
}

void addedge(int u,int v)
{
	e[++topv].v=v;
	e[topv].next=p[u];
	p[u]=topv;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	char s[4];
	scanf("%s",s+1);
	for(int i=1; i<=n; i++)
		w[i]=read();
	for(int i=1; i<n; i++)
	{
		int x=read(),y=read();
		addedge(x,y);
		addedge(y,x);
	}	
	for(int i=1; i<=m; i++)
	{
		st1=read(),qe1=read(),st2=read(),qe2=read();
		if(qe1==0&&qe2==0)
		{
			flg=0;
			dfs2(1,0);
			if(flg)
			{
				printf("-1\n");
				continue;
			}
		}
		for(int j=1; j<=n; j++)
			usd[j]=0;
		usd[1]=1;
		dfs1(1);
		if(st1==1)
			printf("%d\n",dp[1][qe1]);
		else
		{
			if(st2==1)
				printf("%d\n",dp[1][qe2]);
			else
				printf("%d\n",min(dp[1][0],dp[1][1]));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
