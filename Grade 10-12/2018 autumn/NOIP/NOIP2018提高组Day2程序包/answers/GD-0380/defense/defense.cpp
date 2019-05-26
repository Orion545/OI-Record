#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-48;
		ch=getchar();
	}
	return s*w;
}
struct node
{
	int next;
	int to;
}edge[100005];
struct node1
{
	int st;
	int wt;
	int from;
	int present;
	friend bool operator<(node1 a,node1 b)
	{
		return a.wt>b.wt;
	}
};
int n,m,tot;
int w[100005],dp[100005][2],head[100001];
int a,b,x,y;
char te[10];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();
	m=read();
	scanf("%s",te);
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		head[i]=-1;
	for(int i=1;i<=n-1;i++)
	{
		a=read();
		b=read();
		edge[++tot].to=b;
		edge[tot].next=head[a];
		head[a]=tot;
		edge[++tot].to=a;
		edge[tot].next=head[b];
		head[b]=tot;		
	}
	while(m--)
	{
		a=read();
		x=read();
		b=read();
		y=read();	
		int flag=0;
		if(!x&&!y)
		{
			for(int i=head[a];i!=-1;i=edge[i].next)
			{
				if(edge[i].to==b)
				{
					cout<<"-1"<<endl;
					flag=1;
					break;
				}
			}
			if(flag) continue;
		}
		if(te[0]=='A')
		{
			for(int i=2;i<=n;i++)
				dp[i][0]=dp[i][1]=20000000;
			dp[1][0]=0;
			dp[1][1]=w[1];
			for(int i=1;i<=n;i++)
			{
				dp[i][0]=dp[i-1][1];
				dp[i][1]=min(dp[i-1][0],dp[i-1][1])+w[i];	
				if((i==a&&x==1)||(i==b&&y==1))	
					dp[i][0]=20000000;		
				if((i==a&&x==0)||(i==b&&y==0))					
					dp[i][1]=20000000;
			}
			cout<<min(dp[n][1],dp[n][0])<<endl;
			continue;
		}
	}
	return 0;
}
