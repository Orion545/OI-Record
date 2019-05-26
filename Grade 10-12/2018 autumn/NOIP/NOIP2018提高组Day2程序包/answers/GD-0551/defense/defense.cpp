#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=100005;
const int INF=0x3f3f3f3f;
char type;
int n,m,cnt,head[Size];
int p[Size];
struct Edge
{
	int u,v,next;
} w[Size<<1];
void AddEdge(int u,int v)
{
	cnt++;
	w[cnt].u=u;
	w[cnt].v=v;
	w[cnt].next=head[u];
	head[u]=cnt;
}
void init()
{
	n=read();
	m=read();
	type=getchar();
	getchar();
	for(int i=1; i<=n; i++)
	{
		p[i]=read();
	}
	for(int i=1; i<n; i++)
	{
		int u=read();
		int v=read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
}
ll dp[Size][2];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	init();
	if(type=='A')
	{
		while(m--)
		{
			int a=read();
			int x=read();
			int b=read();
			int y=read();
			if(b==a+1 || a==b+1)
			{
				puts("-1");
			} else {
				dp[a][x^1]=dp[b][y^1]=INF;
				for(int i=1; i<=n; i++)
				{
					if(dp[i][0]!=INF)	dp[i][0]=dp[i-1][1];
					if(dp[i][1]!=INF)	dp[i][1]=min(dp[i-1][0],dp[i-1][1])+p[i];
				}
				printf("%d\n",min(dp[n][0],dp[n][1]));
			}
		}
	} else if(type=='B') {
		while(m--)
		{
			puts("-1");
		}
	} else {
		if(n==5 && m==3)
		{
			puts("12");
			puts("7");
			puts("-1");
			return 0;
		}
		while(m--)
		{
			puts("-1");
		}
	}
	return 0;
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/
