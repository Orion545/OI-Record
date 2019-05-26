#include<bits/stdc++.h>
using namespace std;
struct xp{
	int v,ne,w;
}e[500010<<1];
int n,m,tot,head[500010],a,b,l,fa[500010][22],d[500010],ju[500010];
long long ans=0;
void add(int x,int y,int w){
	e[++tot].v=y;
	e[tot].w=w;
	e[tot].ne=head[x];
	head[x]=tot;
}
void dfs(int x,int f){
	d[x]=d[f]+1; 
	fa[x][0]=f;
	for(int r=1;(1<<r)<=d[x];r++) fa[x][r]=fa[fa[x][r-1]][r-1];
	for(int r=head[x];r;r=e[r].ne){
		if(e[r].v!=f){
			ju[e[r].v]=ju[x]+e[r].w;
			dfs(e[r].v,x);
		}
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&a,&b,&l);
		add(a,b,l);
		add(b,a,l);
	}
	for(int i=1;i<=n;i++){
		memset(ju,0,sizeof(ju));
		memset(fa,0,sizeof(fa));
		memset(d,0,sizeof(d));
		dfs(i,0);
		for(int j=1;j<=n;j++) if(i!=j){
			if(ju[j]>ans) ans=ju[j];
		}
	} 
	printf("%lld\n",ans);
	return 0;
}
