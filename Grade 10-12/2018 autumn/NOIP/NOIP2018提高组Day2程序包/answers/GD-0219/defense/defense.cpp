#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct node{
	int x,y,next;
}a[210000];int len,last[210000];
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int n,m;
char st[51];
int d[2100];
int dp[2100][2];
int u,v,ax,bx;
void treedp(int x,int fa)
{
	int sum=0;
	dp[x][1]=d[x];
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			treedp(y,x);
			if((y==u&&ax==0)||(y==v&&bx==0))dp[x][0]=1<<30;
			if(y==u||y==v)
			{
				if(y==u)dp[x][1]+=dp[y][ax],dp[x][0]+=dp[y][ax];
				else dp[x][1]+=dp[y][bx],dp[x][0]+=dp[y][bx];	
			}
			else
			{
				dp[x][1]+=min(dp[y][0],dp[y][1]);
				dp[x][0]+=dp[y][1];
			}
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();scanf("%s",st+1);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=n;i++)d[i]=read();
	for(int i=1;i<n;i++)
	{
		int x,y;
		x=read();y=read();
		ins(x,y);ins(y,x);
	}
	while(m--)
	{
		memset(dp,0,sizeof(dp));
		u=read();ax=read();v=read();bx=read();
		if(ax==bx&&ax==0)
		{
			bool bk=true;
			for(int k=last[u];k;k=a[k].next)
			{
				int y=a[k].y;
				if(y==v){bk=false;break;}
			}
			if(bk==false){printf("-1\n");continue;}
		}
		treedp(1,0);
		if(u==1)printf("%d\n",dp[u][ax]);
		else if(v==1)printf("%d\n",dp[v][bx]);
		else printf("%d\n",min(dp[1][0],dp[1][1]));
	}
	return 0;
}
