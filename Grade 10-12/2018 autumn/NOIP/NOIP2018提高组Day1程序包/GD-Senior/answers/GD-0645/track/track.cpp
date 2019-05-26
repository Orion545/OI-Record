#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=50500,K=1050,M=N<<1;

int a[N],b[N],c[N];
int f[N],g[N],r[N],son[N];
int la[N],ne[M],lb[M],cd[M];
int d[N],e[N],bj[N],bh[N],fa[N];

int o1,o2,o3,o4,p,oo;
int n,m,v;

inline void llb(int x,int y,int z)
{ne[++oo]=la[x]; la[x]=oo; lb[oo]=y; cd[oo]=z;}

inline bool judge1(int p)
{
	int zb=0,yb=n-1;
	int ans=0;
	fo(i,1,m){
		if(c[yb]>=p){
			--yb;
			continue;
		}
		while(c[yb]+c[zb]<p&&zb+1<=yb)++zb;
		if(zb>=yb)return false;
		++zb; --yb;
	}
	return true;
}

inline bool judge2(int p)
{
	int dq=0;
	fo(i,1,m){
		int tott=0;
		while(dq<=n&&tott<p)tott=tott+c[++dq];
		if(dq>n)return false;
	}
	return true;
}

inline void dg(int o)
{
	f[o]=g[o]=0;
	for(int y=la[o];y;y=ne[y])
	if(!fa[lb[y]]){
		fa[lb[y]]=o;
		dg(lb[y]);
		f[o]=max(f[o],g[o]+g[lb[y]]+cd[y]);
		g[o]=max(g[o],g[lb[y]]+cd[y]);
	}
}

inline int max(int a,int b)
{return a>b?a:b;}

inline void find(int o,int k,int zh,int len)
{
	for(int y=la[o];y;y=ne[y])
	if(fa[lb[y]]==o){
		d[++v]=zh+g[o]-f[lb[y]]+g[lb[y]];
		e[v]=len+cd[y];
		bj[v]=((k==0)?lb[y]:k);
		find(lb[y],((k==0)?lb[y]:k),zh+g[o]-f[lb[y]],len+cd[y]);
	}
}

inline bool kmp(int a,int b)
{return bj[a]<bj[b];}

inline void dfs(int o,int len)
{
	f[o]=g[o]=son[o]=0;
	for(int y=la[o];y;y=ne[y])
	if(!fa[lb[y]]){
		fa[lb[y]]=o;
		dfs(lb[y],cd[y]);
		g[o]=g[o]+f[lb[y]];
		++son[o];
	}
	f[o]=g[o]+(len>=p);
	v=0,find(o,0,0,0);
	fo(i,1,v)f[o]=max(f[o],d[i]+(e[i]+len>=p));
	if(son[o]==2){
		fo(i,1,v)bh[i]=i;
		sort(bh+1,bh+v+1,kmp);
		int br=0,gg=bj[bh[1]];
		fo(i,1,v)if(bj[bh[i]]==gg)br=i;
		else break;
		int exw=(len>=p);
		fo(i,1,br)fo(j,br+1,v)f[o]=max(f[o],d[bh[i]]+d[bh[j]]+(e[bh[i]]+e[bh[j]]>=p)+exw);
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	fo(i,1,n-1)llb(a[i],b[i],c[i]),llb(b[i],a[i],c[i]);
	o1=o2=o3=o4=1;
	fo(i,1,n-1)o1=o1&(a[i]==1);
	fo(i,1,n-1)o2=o2*(a[i]+1==b[i]);
	o3=(m==1);
	if(o3){
		fa[1]=-1;
		dg(1);
		int ans=max(f[1],g[1]);
		cout<<ans;
		return 0;
	}
	if(o1==1){
		sort(c+1,c+n);
		int le=1,ri=n*10000+1;
		while(le+1<ri){
			int mid=le+ri>>1;
			if(judge1(mid))le=mid;
			else ri=mid;
		}
		cout<<le;
		return 0;
	}
	if(o2==1){
		int le=1,ri=n*10000+1;
		while(le+1<ri){
			int mid=le+ri>>1;
			if(judge2(mid))le=mid;
			else ri=mid;
		}
		cout<<le;
		return 0;
	}
	fo(i,1,n-1)++r[a[i]],++r[b[i]];
	int root=0;
	fo(i,1,n)if(r[i]==1)root=i;
	int le=0,ri=n*10000+1;
	while(le+1<ri){
		p=le+ri>>1;
		fo(i,1,n)fa[i]=0;
		fa[root]=-1;
		dfs(root,0);
		if(f[root]>=m)le=p;
		else ri=p;
	}
	p=le;
		fo(i,1,n)fa[i]=0;
		fa[root]=-1;
		dfs(root,0);
	cout<<le;
	return 0;
}
