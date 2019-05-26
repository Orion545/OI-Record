#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
#define rep(i,x) for(int i=ls[x];i;i=nx[i])
using namespace std;
typedef long long ll;
const int N=1e5+10,M=2e5+10;
const ll inf=1e13;
int to[M],nx[M],ls[N],num=0;
int a[N];
ll f[N][2];
int bz[N];
void link(int u,int v){
	to[++num]=u,nx[num]=ls[v],ls[v]=num;
}
char ch[4];
void dfs(int x,int fr){
	f[x][0]=0;
	f[x][1]=a[x];
	rep(i,x){
		int v=to[i];
		if(v==fr) continue;
		dfs(v,x);
		f[x][0]+=f[v][1];
		f[x][1]+=min(f[v][0],f[v][1]);
	}
	if(bz[x]>=0) f[x][bz[x]^1]=inf;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	scanf("%d %d %s",&n,&m,ch);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,2,n){
		int u,v;
		scanf("%d %d",&u,&v);
		link(u,v),link(v,u);
	}
	memset(bz,255,sizeof(bz));
	while(m--){
		int u,x,v,y;
		scanf("%d %d %d %d",&u,&x,&v,&y);
		bz[u]=x,bz[v]=y;
		dfs(1,0);
		ll ans=min(f[1][0],f[1][1]);
		ans>=inf?puts("-1"):printf("%lld\n",ans);
		bz[u]=-1,bz[v]=-1;
	}
}
