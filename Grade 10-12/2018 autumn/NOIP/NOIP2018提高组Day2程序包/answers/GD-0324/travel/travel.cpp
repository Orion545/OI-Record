#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
#define rep(i,x) for(int i=ls[x];i;i=nx[i])
using namespace std;
const int N=1e4+10,M=2e4+10;
int an[N];
bool vis[N];
struct node{
	int u,v,id;
}e[M],b[M];
int tot=0;
int L[N],R[N];
int c[N],up[N],fa[N];
int d[N];
bool ban[M];
bool cmp(node x,node y){
	return x.u<y.u || (x.u==y.u && x.v<y.v);
}
void dfs(int x,int fr){
	an[++an[0]]=x;
	fo(i,L[x],R[x]) if(!ban[e[i].id]){
		int v=e[i].v;
		if(v==fr) continue;
		dfs(v,x);
	}
}
bool find(int x,int fr){
	vis[x]=1,fa[x]=fr;
	fo(i,L[x],R[x]){
		int v=e[i].v;
		if(v==fr) continue;
		if(vis[v]){
			c[++c[0]]=e[i].id;
			for(int u=x;u!=v;u=fa[u]) c[++c[0]]=up[u];
			return true;
		}
		up[v]=e[i].id;
		if(find(v,x)) return true;
	}
	return false;
}
void update(){
	if(!d[0]) memcpy(d,an,sizeof(an));
	else{
		fo(i,1,d[0]) if(an[i]<d[i]){
			memcpy(d,an,sizeof(an));
			break;
		}
		else if(an[i]>d[i]) break;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	fo(i,1,m){
		int u,v;
		scanf("%d %d",&u,&v);
		e[++tot].u=u,e[tot].v=v,e[tot].id=i;
		e[++tot].u=v,e[tot].v=u,e[tot].id=i;
	}
	sort(e+1,e+tot+1,cmp);
	L[e[1].u]=1;
	fo(i,1,tot)
	if(i<tot && e[i].u!=e[i+1].u) L[e[i+1].u]=i+1,R[e[i].u]=i;
	R[e[tot].u]=tot;
	if(m==n-1){
		dfs(1,0);
		fo(i,1,n) printf("%d ",an[i]);
		return 0;
	}
	find(1,0);
	fo(i,1,c[0]){
		ban[c[i]]=1;
		an[0]=0,dfs(1,0);
		ban[c[i]]=0;
		update();
	}
	fo(i,1,n) printf("%d ",d[i]);
}
