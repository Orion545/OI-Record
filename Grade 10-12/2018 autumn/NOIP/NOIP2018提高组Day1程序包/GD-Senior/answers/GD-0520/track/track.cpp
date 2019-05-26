#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define of(i,l,r) for(int i=r;i>=r;--i)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define fin(str) freopen(str,"r",stdin)
#define fou(str) freopen(str,"w",stdout)
using namespace std;
typedef long long ll;
inline int rd()
{static int x,f;static char ch;
	x=0;f=1;ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=50010;
struct edge{
	int v,w,next;
	edge(int v=0,int w=0,int next=0):v(v),w(w),next(next){}
}e[N<<1];
int n,m;
int tot=0,head[N];
int mx=0,f[N],g[N];

inline void add(int u,int v,int w){e[++tot]=edge(v,w,head[u]);head[u]=tot;}

void dfs(int u,int fat,int mid)
{static int st[N],tp;static bool bo[N];
	f[u]=0;g[u]=0;
	fe(i,u){
		int v=e[i].v;if(v==fat)continue;
		dfs(v,u,mid);
	}
	tp=0;
	fe(i,u){
		int v=e[i].v;if(v==fat)continue;
		f[u]+=f[v];
		if(g[v]+e[i].w>=mid)++f[u];
		else{st[++tp]=g[v]+e[i].w;bo[tp]=0;}
	}
	sort(st+1,st+tp+1);
	fo(i,1,tp){
		if(bo[i])continue;
		int t=lower_bound(st+1,st+tp+1,mid-st[i])-st;
		t=max(i+1,t);
		while(bo[t]&&t<=tp)++t;
		if(t>tp)continue;
		bo[t]=bo[i]=1;++f[u];
	}
	fo(i,1,tp)if(!bo[i])g[u]=max(g[u],st[i]);
}

inline int gao(int mid)
{
	memset(f,0,sizeof f);memset(g,0,sizeof g);
	dfs(1,0,mid);
	return f[1];
}

int main()
{
	fin("track.in");
	fou("track.out");
	n=rd();m=rd();
	fo(i,2,n){
		int x=rd(),y=rd(),z=rd();
		add(x,y,z);add(y,x,z);
		mx+=z;
	}
	int l=1,r=mx,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(gao(mid)>=m)ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

