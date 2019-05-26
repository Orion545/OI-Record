#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=100001;
const int inf=999999;
int n,m;
string ss;
int p[maxn];
int dp[maxn][2];
int ff[maxn][3],sum;

struct Edge
{
	int next,to;
}edge[maxn*2];
int head[maxn],cnt;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void clear()
{
	memset(head,-1,sizeof(head));
	memset(dp,inf,sizeof(dp));
}

void add(int next,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[next];
	head[next]=cnt;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	clear();
	n=read();m=read();
	cin>>ss;
	for(int i=1;i<=n;i++)
	{
		p[i]=read();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read();
		v=read();
		ff[++sum][1]=u,ff[sum][2]=v;
		add(u,v);
		add(v,u);
	}
	if(ss=="A3")
	{
		while(m--)
		{
			int x,x1,y,y1;
			int ans=0;
			int flag=0;
			x=read();x1=read();
			y=read();y1=read();
			if(x1==1&&y1==1)
			{
			for(int i=1;i<=sum;i++)
			{
				if(x==ff[i][1]&&y==ff[i][2])
				{
					flag=1;
					break;
				}
				if(y==ff[i][1]&&x==ff[i][2])
				{
					flag=1;
					break;
				}
			}
			}
			if(flag==1)
			{
				printf("-1\n");
			}
			else
			{	
				if(x1==0&&y1==0)
				{
					dp[1][0]=0;
					dp[1][1]=p[1];
					for(int i=2;i<=n;i++)
					{
						dp[i][0]=min(dp[i][0],dp[i-1][1]);
						dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
					}
					int op;
					op=min(dp[n][0],dp[n][1]);
					printf("%d\n",op);
				}	
				else if(x1==1||y1==1)
				{
					int yuyu;
					if(x1==1)
						yuyu=x;
					if(y1==1)
						yuyu=y;
					dp[yuyu][1]=p[yuyu];
					dp[yuyu+1][0]=p[yuyu];
					dp[yuyu+1][1]=p[yuyu]+p[yuyu+1];
					for(int i=yuyu+2;i<=n;i++)
					{
						dp[i][0]=min(dp[i][0],dp[i-1][1]);
						dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
					}
					dp[yuyu-1][0]=p[yuyu];
					dp[yuyu-1][1]=p[yuyu]+p[yuyu-1];
					for(int i=yuyu-2;i>=1;i--)
					{
						dp[i][0]=min(dp[i][0],dp[i+1][1]);
						dp[i][1]=min(dp[i+1][0],dp[i+1][1])+p[i];
					}
					int op=0,op1,op2;
					op1=min(dp[1][0],dp[1][1]);
					op2=min(dp[n][0],dp[n][1]);
					op=op1+op2;
					printf("%d\n",op-p[yuyu]);
				}
			}
		}
	}
	if(ss=="A2")
	{
		while(m--)
		{
			int x,x1,y,y1;
			int ans=0;
			int flag=0;
			x=read();x1=read();
			y=read();y1=read();
			if(x1==1&&y1==1)
			{
			for(int i=1;i<=sum;i++)
			{
				if(x==ff[i][1]&&y==ff[i][2])
				{
					flag=1;
					break;
				}
				if(y==ff[i][1]&&x==ff[i][2])
				{
					flag=1;
					break;
				}
			}
			}
			if(flag==1)
			{
				printf("-1\n");
			}
			else
			{	
				if(x1==0&&y1==0)
				{
					dp[1][0]=0;
					dp[1][1]=p[1];
					for(int i=2;i<=n;i++)
					{
						dp[i][0]=min(dp[i][0],dp[i-1][1]);
						dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
					}
					int op;
					op=min(dp[n][0],dp[n][1]);
					printf("%d\n",op);
				}	
				else if(x1==1||y1==1)
				{
					int yuyu;
					if(x1==1)
						yuyu=x;
					if(y1==1)
						yuyu=y;
					dp[yuyu][1]=p[yuyu];
					dp[yuyu+1][0]=p[yuyu];
					dp[yuyu+1][1]=p[yuyu]+p[yuyu+1];
					for(int i=yuyu+2;i<=n;i++)
					{
						dp[i][0]=min(dp[i][0],dp[i-1][1]);
						dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
					}
					dp[yuyu-1][0]=p[yuyu];
					dp[yuyu-1][1]=p[yuyu]+p[yuyu-1];
					for(int i=yuyu-2;i>=1;i--)
					{
						dp[i][0]=min(dp[i][0],dp[i+1][1]);
						dp[i][1]=min(dp[i+1][0],dp[i+1][1])+p[i];
					}
					int op=0,op1,op2;
					op1=min(dp[1][0],dp[1][1]);
					op2=min(dp[n][0],dp[n][1]);
					op=op1+op2;
					printf("%d\n",op-p[yuyu]);
				}
			}
		}
	}
	return 0;
}
