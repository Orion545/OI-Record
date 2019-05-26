#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector >
#define rep(i,x,y) for (int i=x;i<=y;++i)
#define LL long long
#define rrep(i,x,y) for (int i=x;i<y;++i)
const int N = 1e5+233;
const LL INF =1ll<<50;
using namespace std;
struct xx
{
	int V,nxt;
}B[N];
int head[N],G;
void add(int x,int y)
{
	B[++G]=(xx){y,head[x]};
	head[x]=G;
}
#define F(x) for (int i=head[x];i;i=B[i].nxt)
#define v B[i].V
LL f[N][3],g[N][2];

int n,x,m,y,s,a,t,b,A[2333][2333],rt;
int w[N];
void dfs1(int x,int Fa)
{
	int t1=0,t2=0;
	LL S0=0,S1=0,S2=0;
	F(x) if (v^Fa)
	{
		dfs1(v,x);
		S1+=min(f[v][0],f[v][1]);
		S0+=f[v][1];
		S2+=f[v][0];
	}
	f[x][0]=S0;
	f[x][1]=INF;
	f[x][2]=S2+w[x];
	F(x) if(v^Fa)
	{
		f[x][1]=min(f[x][1],f[v][1]+S1-min(f[v][0],f[v][1]));
	}
	if (x==s)
	{
		if (a==1) f[x][0]=f[x][1]=INF;
		else f[x][2]=INF;
	}
	if(x==t)
	{
		if (b==1) f[x][0]=f[x][1]=INF;
		else f[x][2]=INF;
	}
}
void solve1()
{
	rep(i,2,n ) 
	  scanf("%d%d",&x,&y),add(x,y),add(y,x),A[x][y]=1;;
	while (m--)
	{
		scanf("%d%d%d%d",&s,&a,&t,&b);
		if (a==0&&b==0&&A[s][t]==1) 
		{
			printf("-1\n");
			continue;
		}
		rep(i,1,n) if (i!=s&&i!=t) 
		{
			rt=i;break;
		}
		dfs1(rt,0);
		printf("%lld\n",min(f[rt][0],f[rt][1]));
	}
	return ;
}

void solve2()
{
	rep(i,2,n) scanf("%d %d",&x,&y);
	f[0][0]=f[0][1]=g[n+1][0]=g[n+1][1]=INF;
	rep(i,1,n) f[i][0]=f[i-1][1],
	f[i][1]=min(f[i-1][1],f[i-1][0])+w[i];
	for(int i=n;i>=1;--i)
	  g[i][0]=g[i+1][1],
	  g[i][1]=min(g[i+1][0],g[i+1][1])+w[i];
	  
	while (m--)
	{
		scanf("%d%d%d%d",&s,&a,&t,&b);
		if (s>t) swap(a,b),swap(s,t);
		//if (a==1&&b==1) 
		printf("%lld\n",f[s][a]+g[t][b]);
		//printf("%lld\n",f[s])
	}
}

void solve3()
{
	rep(i,2,n) scanf("%d %d",&x,&y);
	f[0][0]=f[0][1]=g[n+1][0]=g[n+1][1]=INF;
	f[1][0]=INF;f[1][1]=w[1];
	rep(i,2,n) f[i][0]=f[i-1][1],
	f[i][1]=min(f[i-1][1],f[i-1][0])+w[i];
	for(int i=n;i>=1;--i)
	  g[i][0]=g[i+1][1],
	  g[i][1]=min(g[i+1][0],g[i+1][1])+w[i];
	  
	while (m--)
	{
		scanf("%d%d%d%d",&s,&a,&t,&b);
		if (s>t) swap(a,b),swap(s,t);
		printf("%lld\n",f[s][a]+g[t][b]);
		//printf("%lld\n",f[s])
	}
	return;
}

char ss[5];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
		scanf("%d%d%s",&n,&m,ss);
		rep(i,1,n) scanf("%d",&w[i]);
		//rep(i,2,n ) scanf("%d%d",&x,&y),add(x,y),add(y,x);
		if (ss[0]=='A'&&ss[1]=='2')
		{
			solve2();
			return 0;
		}
		if (ss[0]=='A'&&ss[1]=='1')
		{
			solve3();
			return 0;
		}
		if(n<=2000)
		{
			solve1();
			return 0;
		}
		//rep(i,2,n ) scanf("%d%d",&x,&y),add(x,y),add(y,x);
}


