#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
const ll oo=1000000000000ll;
const int mx=1e5+10;
int n,m;
char tp[3];
int p[mx];
int hd[mx],node[mx*2],nt[mx*2],fp=0;
ll f[mx][2];
int x,y,a,b;

void con(int x,int y)
{
	node[fp]=y;
	nt[fp]=hd[x];
	hd[x]=fp;
	fp++;
}

int fa[mx];

void dfs(int u,int fat)
{
	if(!u) return ;
	fa[u]=fat;
	int v;
	ll t1=0,t2=0;
	for(int i=hd[u];i!=-1;i=nt[i])
	{
		v=node[i];
		if(!v || v==fat) continue;
		dfs(v,u);
		t1+=f[v][1];
		t2+=min(f[v][0],f[v][1]);
	}
	
	f[u][0]=t1;
	f[u][1]=p[u]+t2;
	if(u==a) f[u][x^1]=oo;
	if(u==b) f[u][y^1]=oo;
}

void solve1()
{
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		for(int j=1;j<=n;j++) f[j][0]=f[j][1]=0;
		dfs(1,0);
		ll ans=min(f[1][0],f[1][1]);
		if(ans>=oo) printf("-1\n");
		else printf("%lld\n",ans);
	}
}


int up(int &u,int t)
{
	if(!u) return 0;
	int p=u;
	ll tt[2];
	tt[0]=f[u][0],tt[1]=f[u][1];
	tt[t]=oo;
	while(p!=1)
	{
		ll t1=tt[1],t0=tt[0];
		tt[1]=min(t0,t1);
		tt[0]=t1;
		u=p;
		p=fa[p];
	}
	return min(tt[0],tt[1]);
}

void solve2()
{
	a=x=b=y=0;
	for(int j=1;j<=n;j++) f[j][0]=f[j][1]=0;
	dfs(1,0);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		int tmp=up(b,y);
		ll ans=min(f[1][0],f[1][1]-min(f[b][0],f[b][1])+tmp);
		if(ans>=oo) printf("-1\n");
		else printf("%lld\n",ans);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(hd,-1,sizeof hd);
	
	scanf("%d%d",&n,&m);
	scanf("%s",tp);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		con(x,y),con(y,x);
	}
	
	if(n<=2000) return solve1(),0;
	if(tp[0]=='B' && tp[1]=='1') return solve2(),0;
	solve1();	

	
	return 0;
}
