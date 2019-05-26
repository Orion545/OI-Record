#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
#define go(u) for (int o=ft[u],v;v=E[o].t,o;o=E[o].n)
const int N=100010;
int a[N<<1],st[N],ed[N],ft[N],du[N],tot,tt;
int vis[N];
struct edge{int t,n;}E[N<<1];
int n,m;
void dfs1(int u,int f){
	vis[u]=1;
	printf("%d ",u);
	rep(i,st[u],ed[u]) if (!vis[a[i]]) dfs1(a[i],u);
}
void work1(){
	rep(i,1,n){
		st[i]=tt+1;
		go(i) a[++tt]=v;
		ed[i]=tt;
		sort(a+st[i],a+ed[i]+1);
	}
	dfs1(1,0);
}
int q[N],h,t,icr[N];
void ini(){
	rep(i,1,n) if (du[i]==1) q[++t]=i;
	h=1;
	rep(i,1,n) icr[i]=1;
	while (h<=t){
		int u=q[h++];
		icr[u]=0;
		go(u) if (icr[v]){
			--du[v];
			if (du[v]==1) q[++t]=v;
		}
	}
}
int tag,mn2,fob;
void dfs2(int u,int f){
	vis[u]=1;
	printf("%d ",u);
	if (!icr[u]){
		rep(i,st[u],ed[u]) if (!vis[a[i]]) dfs2(a[i],u);
		return;
	}
	if (!icr[f]){
		bool f_f=0;
		rep(i,st[u],st[u]+1) if (a[i]==f) f_f=1;
		if (!f_f){
			mn2=a[st[u]+1];
			dfs2(a[st[u]],u);
			rep(i,st[u],ed[u]) if (!vis[a[i]]) dfs2(a[i],u);
			return;
		}
		else{
			mn2=a[st[u]+2];
			dfs2(a[st[u]]+a[st[u]+1]-f,u);
			rep(i,st[u],ed[u]) if (!vis[a[i]]) dfs2(a[i],u);
			return;
		}
	}
	if (1/*tag||fob*/){
		rep(i,st[u],ed[u]) if (!vis[a[i]]) dfs2(a[i],u);
		return;
	}
	
}
void work2(){
	ini();
	rep(i,1,n){
		st[i]=tt+1;
		go(i) a[++tt]=v;
		ed[i]=tt;
		sort(a+st[i],a+ed[i]+1);
	}
	dfs2(1,0);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		E[++tot]=(edge){y,ft[x]},ft[x]=tot;
		E[++tot]=(edge){x,ft[y]},ft[y]=tot;
		++du[x],++du[y];
	}
	work1();
	return 0;
}
