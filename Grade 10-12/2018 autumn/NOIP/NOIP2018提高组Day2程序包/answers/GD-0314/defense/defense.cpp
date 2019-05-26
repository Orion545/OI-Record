#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=100100;
int n,m;
int p[N]; 
int qa,qx,qb,qy;
int fa[N],d[N],d0;
ll f[N][2],inf;
int las[N],nex[N*2],to[N*2];
void dfs(int x)
{
	d[++d0]=x;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		to[tp][fa]=x;
		dfs(to[tp]);
	}
}
int tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
char sts[10];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,sts);
	fo(i,1,n) scanf("%d",&p[i]);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	dfs(1);inf=(1ll<<60);
	while(m--)
	{
		scanf("%d%d%d%d",&qa,&qx,&qb,&qy);
		if(qa==qb&&qx!=qy)
		{
			printf("-1\n");
			continue;
		}
		fd(x,d0,1) 
		{
			int i=d[x];
			f[i][0]=0,f[i][1]=p[i];
			for(int tp=las[i];tp;tp=tp[nex])
			if(tp[to]!=fa[i])
			{
				f[i][1]+=min(f[to[tp]][1],f[to[tp]][0]);
				if(f[i][1]>=inf) f[i][1]=inf;
				f[i][0]+=f[to[tp]][1];
				if(f[i][0]>=inf) f[i][0]=inf;
			}
			if(i==qa) f[i][qx^1]=inf;
			if(i==qb) f[i][qy^1]=inf;
		}
		ll ans=min(f[1][0],f[1][1]);
		if(ans>=inf) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}







