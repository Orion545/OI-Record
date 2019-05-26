#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define mmst(a, b) memset(a,b,sizeof(a))
#define mmcp(a, b) memcpy(a,b,sizeof(a))

using namespace std;

typedef long long LL;

const int N=200200;
const LL oo=1e11;

int n,m;
char cc[12];
int head[N],nex[N],to[N],cnt;
int tim[N],times;
LL f[N],g[N],q[N],p[N];
int ok[N];
bool vis[N];

int fa[N][18];

struct yy
{
	LL tt,tf,ft,ff;	
}u[N][18],by;

yy unite(yy x,yy y)
{
	yy hy;
	if(x.tt==0&&x.tf==0&&x.ft==0&&x.ff==0)
	return y;
	hy.tt=min(min((x.tt+y.tt),(x.tf+y.tt)),(x.tt+y.ft));
	hy.tf=min(min((x.tt+y.tf),(x.tf+y.tf)),(x.tt+y.ff));
	hy.ft=min(min((x.ft+y.tt),(x.ff+y.tt)),(x.ft+y.ft));
	hy.ff=min(min((x.ft+y.tf),(x.ff+y.tf)),(x.ft+y.ff));
	return hy;
}

void add(int u,int v)
{
	to[++cnt]=v;
	nex[cnt]=head[u];
	head[u]=cnt;
}

void dfs(int x)
{
	vis[x]=1;
	tim[x]=++times;
	f[x]=g[x]=0;
	for(int h=head[x];h;h=nex[h])
	if(!vis[to[h]])
	{
		dfs(to[h]);
		fa[to[h]][0]=x;
		f[x]+=q[to[h]];
		g[x]+=f[to[h]];
	}
	f[x]+=p[x];
	f[x]=min(f[x],oo);
	g[x]=min(g[x],oo);
	
	if(ok[x]==1)
	g[x]=oo;
	if(ok[x]==0)
	f[x]=oo;
	q[x]=min(f[x],g[x]);
}

int lca(int x,int y)
{
	if(x==y)
	return x;
	
	for(int j=17;j>=0;j--)
	if(tim[fa[y][j]]>tim[x])
	y=fa[y][j];
	return fa[y][0];
}

yy work(int y,int lc,int &son)
{
	yy ret=by;
	if(fa[y][0]==lc)
	{
		ret.tf=ret.ft=oo;
		ret.tt=f[y];
		ret.ff=g[y];
		son=y;
		return ret;
	}
	
	int oi=0;
	for(int j=17;j>=0;j--)
	if(tim[fa[y][j]]>tim[lc])
	{
		yy hy=u[y][j];
					
		hy.tt-=q[oi];
		hy.tf-=q[oi];
		hy.ft-=f[oi];
		hy.ff-=f[oi];
		
		ret=unite(ret,hy);
		
		oi=y;			
		y=fa[y][j];
	}
	son=y;
	return ret;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	cin>>n>>m;
	scanf("%s",cc);
	
	for(int i=1;i<=n;i++)
	scanf("%lld",&p[i]);
	
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	ok[i]=-1;
	
	if(n<=2000&&m<=2000)
	{	
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d",&x);
			scanf("%d",&ok[x]);
			
			scanf("%d",&y);
			scanf("%d",&ok[y]);
			
			for(int i=1;i<=n;i++)
			vis[i]=0;
			
			dfs(1);
			
			LL ans=min(f[1],g[1]);
			
			if(ans<oo)
			printf("%lld\n",ans);
			else
			printf("-1\n");
			
			ok[x]=ok[y]=-1;
		}
		return 0;
	}
	
	dfs(1);
	
	u[1][0].ff=g[1];
	u[1][0].tt=f[1];
	u[1][0].ft=u[1][0].tf=oo;
	
	for(int i=2;i<=n;i++)
	{
		int ba=fa[i][0];
		u[i][0].tt=f[ba]-q[i]+f[i];
		u[i][0].ff=oo;
		u[i][0].tf=g[ba];
		u[i][0].ft=f[ba]-q[i]+g[i];
	}
	
	fa[1][0]=1;
	for(int j=1;j<=17;j++)
	for(int i=1;i<=n;i++)
	{
		fa[i][j]=fa[fa[i][j-1]][j-1];
		if(fa[i][j]==fa[i][j-1])
		u[i][j]=u[i][j-1];
		else
		{
			int x=fa[i][j-1];
			int ba=fa[x][0];
			
			yy hy=u[ba][j-1];
			
			hy.tt-=q[x];
			hy.tf-=q[x];
			hy.ft-=f[x];
			hy.ff-=f[x];
			
			u[i][j]=unite(u[i][j-1],hy);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(tim[a]>tim[b])
		swap(a,b),swap(x,y);
		
		if(!x&&!y)
		if(fa[a][0]==b||fa[b][0]==a)
		{
			printf("-1");
			continue;
		}
		
		int lc=lca(a,b),sona,sonb;
		LL ans=0;
		
		yy ha=work(a,lc,sona);
		yy hb=work(b,lc,sonb);
		
		LL QA,QB,FA,FB;
		if(x==1)
		QA=min(ha.tt,ha.tf),FA=ha.tt;
		else
		QA=min(ha.ft,ha.ff),FA=ha.ft;
			
		if(y==1)
		QB=min(hb.tt,hb.tf),FB=hb.tt;
		else
		QB=min(hb.ft,hb.ff),FB=hb.ft;
		
		if(a==1)
		{
			if(x==1)
			ans=f[1]-q[sonb]+QB;
			else
			ans=g[1]-f[sonb]+FB;
		}
		else
		{
			ans=f[1]-q[sona]-q[sonb]+QA+QB;
			ans=min(ans,g[1]-f[sona]-f[sonb]+FA+FB);
		}
		printf("%lld\n",ans);
	}

	return 0;
}

