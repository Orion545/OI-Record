#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
int n,m;
char tpy[5];
bool ok;
LL p[100005],f[100005][2],g[100005][2];
int lst[100005],nxt[200005],e[200005],cnt;
int ask[100005];
void build(int x,int y)
{
	e[++cnt]=y;
	nxt[cnt]=lst[x];
	lst[x]=cnt;
}
void dfs(int x,int fa)
{
	f[x][0]=f[x][1]=(1ll<<34);
	LL sum1=p[x],sum2=0;
	for(int u=lst[x];u;u=nxt[u])
	{
		int y=e[u];
		if(y==fa) continue;
		if(ask[x]==0&&ask[y]==0)
		{
			ok=true;
			return;
		}
		dfs(y,x);
		if(ask[y]==1) sum1+=f[y][1],sum2+=f[y][1];
		else if(ask[y]==0) sum1+=f[y][0],sum2=(1ll<<34);
		else sum1+=min(f[y][0],f[y][1]),sum2+=f[y][1];
		if(ok) return;
	}
	f[x][0]=min(f[x][0],sum2);
	f[x][1]=min(f[x][1],sum1);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",tpy);
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i]),ask[i]=2;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		build(x,y);
		build(y,x);
	}
	if(n<=2000)
	{
		while(m--)
		{
			ok=false;
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			ask[a]=b;
			ask[c]=d;
			dfs(1,0);
			ask[a]=ask[c]=2;
			if(ok) printf("-1\n");
			else printf("%lld\n",min(f[1][0],f[1][1]));
		}
		return 0;
	}
	if(tpy[0]=='A'&&tpy[1]=='2')
	{
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];
		}
		for(int i=n;i>0;i--)
		{
			g[i][0]=g[i+1][1];
			g[i][1]=min(g[i+1][1],g[i+1][0])+p[i];
		}
		while(m--)
		{
			ok=false;
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(a>c)
			{
				int t=a;
				a=c;
				c=t;
			}
			if(b==0&&d==0) printf("-1\n");
			else printf("%lld\n",f[a][b]+g[c][d]);
		}
		return 0;
	}
	return 0;
}
