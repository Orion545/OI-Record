#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i.=l;--i)

using namespace std;
typedef long long ll;
const ll N=120000,M=N<<1,maxn=1e16;

int la[N],ne[M],lb[M],fa[N];
int n,m,x,y,x1,y1,oo;
char s[N];
int bh[N];
ll f[N],g[N];
ll p[N];

inline void llb(int a,int b)
{ne[++oo]=la[a]; la[a]=oo; lb[oo]=b;}

inline ll min(ll a,ll b)
{return a<b?a:b;}

inline void dg(int o)
{
	f[o]=p[o];
	for(int y=la[o];y;y=ne[y])
	if(!fa[lb[y]]){
		fa[lb[y]]=o;
		dg(lb[y]);
		f[o]=f[o]+min(f[lb[y]],g[lb[y]]);
	}
	ll zh=f[o]-p[o];
	g[o]=0;
	for(int y=la[o];y;y=ne[y])
	if(fa[lb[y]]==o)g[o]=g[o]+f[lb[y]];
	if(bh[o]==0)f[o]=maxn;
	if(bh[o]==1)g[o]=maxn;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	fo(i,1,n)scanf("%lld",&p[i]);
	fo(i,1,n-1){
		scanf("%d%d",&x,&y);
		llb(x,y); llb(y,x);
	}
	fo(i,1,n)bh[i]=2;
	fo(i,1,m){
		scanf("%d%d%d%d",&x,&x1,&y,&y1);
		if(fa[x]==y||fa[y]==x&&x1==0&&y1==0){
			puts("-1");
			continue;
		}
		bh[x]=x1; bh[y]=y1;
		fo(i,1,n)fa[i]=0;
		fa[1]=-1;
		dg(1);
		bh[x]=bh[y]=2;
		ll ans=min(f[1],g[1]);
		printf("%lld\n",ans);
	}
}
