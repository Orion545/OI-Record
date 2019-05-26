#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN=5e3+5,MAXM=MAXN<<1;
const LL INF=1e11;

char opt[5];
int a[MAXN];
int head[MAXM],nxt[MAXM],v[MAXM],w[MAXM],cnt;
LL dp[MAXN][2];

int n,m;
int ax,ay,bx,by;

inline void Addline(int x,int y)
{
	v[cnt]=y;
	nxt[cnt]=head[x],head[x]=cnt++;
	
	return;
}

inline void DFS(int x,int from)
{
	for(int i=head[x];~i;i=nxt[i])
		if(v[i]!=from)
		{
			DFS(v[i],x);
			dp[x][0]+=dp[v[i]][1];
			dp[x][1]+=min(dp[v[i]][0],dp[v[i]][1]);
		}
	
	dp[x][1]+=a[x];
	
	if(x==ax)
	{
		if(ay==1)
			dp[x][0]=INF;
		if(ay==0)
			dp[x][1]=INF;
	}
	
	if(x==bx)
	{
		if(by==1)
			dp[x][0]=INF;
		if(by==0)
			dp[x][1]=INF;
	}
	
	return;
}

signed main(void)
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(head,-1,sizeof head);
	
	scanf("%d %d %s",&n,&m,opt);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		Addline(x,y),Addline(y,x);
	}
	
	while(m--)
	{
		scanf("%d %d %d %d",&ax,&ay,&bx,&by);
		memset(dp,0,sizeof dp);
		DFS(1,0);
		
		LL ans=min(dp[1][0],dp[1][1]);
		
		printf("%lld\n",ans>=INF?-1:ans);
		
		//for(int i=1;i<=n;i++)
		//	printf("%lld %lld\n",dp[i][0],dp[i][1]);
		//putchar('\n');
	}
	
	return 0;
}
