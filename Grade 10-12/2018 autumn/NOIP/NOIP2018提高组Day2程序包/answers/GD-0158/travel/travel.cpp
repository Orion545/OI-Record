#include<cstdio>
#include<algorithm>
#include<cstring>
#define lb(x) ((x)&-(x))
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define link(x,y) e[++tot]=y,nt[tot]=fi[x],fi[x]=tot
#define F(x) for(int i=fi[x];i;i=nt[i])
using namespace std;
const int N=5e3+5,M=2*N;
int e[M],nt[M],fi[N],tot,BZ;
int n,m,vis[N],pri[N],bz,cir[N];
void dfs(int x,int fa){
	if(pri[x]) return;
	if(cir[x] && bz && bz<x && !BZ){
		BZ=x;
		return;
	}
	int cnt=0;int d[N];
	F(x) if(!pri[e[i]]) d[++cnt]=e[i],vis[e[i]]=1;
	sort(d+1,d+cnt+1);
	if(cir[x] && !bz) fo(i,1,cnt) if(cir[d[i]]) bz=d[i]; 
	printf("%d ",x);pri[x]++;
	fo(i,1,cnt) dfs(d[i],x);
}
int make(int x,int aim,int fa){
	if(x==aim) return 1;
	F(x){
		int y=e[i];
		if(y==fa) continue;
		cir[y]=make(y,aim,x);
		if(cir[y]==1) return 1;
	}
	return 0;
}
int f[N];
int get(int x){
	if(f[x]==x) return x;
	return f[x]=get(f[x]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);int x,y;
	fo(i,1,n) f[i]=i;
	fo(i,1,m) {
		scanf("%d%d",&x,&y);
		if(get(x)==get(y)) 
			cir[x]=cir[y]=make(x,y,x);
		link(x,y),link(y,x);
		f[get(x)]=get(y);
	}
	fo(i,1,n) vis[i]=0;
	dfs(1,1);
	if(BZ) dfs(BZ,0);
}
