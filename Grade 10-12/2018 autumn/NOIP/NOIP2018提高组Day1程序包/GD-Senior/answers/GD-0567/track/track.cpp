#include<set>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 100010
using namespace std;
struct V{ int v,x; };
struct edge{ int v,c,nt; } G[N<<1];
int n,m,h[N],cnt,d[N],A,B; set<V> s[N];
inline bool operator<(V a,V b){
	return a.v==b.v?a.x<b.x:a.v<b.v;
}
inline int dfs(int x,int p){
	for(int v,i=h[x];i;i=G[i].nt)
		if((v=G[i].v)!=p){
			int t=G[i].c+dfs(v,x);
			if(t>=B) ++A;
			else s[x].insert((V){t,v});
		}
	int mx=0;
	for(set<V>::iterator it,z;s[x].size();){
		it=s[x].begin();
		int r=max(it->v,B-it->v);
		z=s[x].lower_bound((V){r,r==it->v?it->x+1:0});
		if(z==s[x].end()){ mx=max(mx,it->v); s[x].erase(it); }
		else{ ++A; s[x].erase(it); s[x].erase(z); }
	}
	return mx;
}
inline int cal(int M){
	for(int i=1;i<=n;++i) s[i].clear();
	A=0; B=M;
	if(dfs(1,0)>=M) ++A;
	return A;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int S=0;
	for(int x,y,c,i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&c); S+=c;
		G[++cnt]=(edge){y,c,h[x]}; h[x]=cnt;
		G[++cnt]=(edge){x,c,h[y]}; h[y]=cnt;
	}
	int l=1,r=S/m+1;
	for(int M;l<r;){
		M=l+r+1>>1;
		if(cal(M)>=m) l=M;
		else r=M-1;
	}
	printf("%d\n",l);
	return 0;
}
