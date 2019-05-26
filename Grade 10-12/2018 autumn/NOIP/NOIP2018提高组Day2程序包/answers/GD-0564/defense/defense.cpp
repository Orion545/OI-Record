#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) (a<b?a:b) 
using namespace std;
typedef long long ll; 
inline int read(){
	int n=0;char c;
	for(c=getchar();c<'0'||c>'9';c=getchar()) ;
	for(;c>='0'&&c<='9';c=getchar())  n=n*10+c-48;
	return n; 
} 
const int maxn=1e5+5; 
const ll inf=1e12; 
int i,j,n,m,p[maxn],h[maxn],F[maxn][17];
int q[maxn],cnt; 
ll f[maxn][2],ax,by,ans; 
vector<int>g[maxn];
void dfs(int x,int fa){
	F[x][0]=fa,h[x]=h[fa]+1,f[x][1]=p[x]; 
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if (y==fa) continue;
		dfs(y,x);
		f[x][0]+=f[y][1],f[x][1]+=min(f[y][0],f[y][1]); 
	}
}
int lca(int x,int y){
	int j;
	if (h[x]>h[y]) swap(x,y); 
	if (h[x]<h[y]) {
		fd(j,16,0) if (h[x]<h[F[y][j]]) y=F[y][j]; 
		y=F[y][0]; 
	} 
	if (x==y) return x; 
	fd(j,16,0) if (F[x][j]!=F[y][j])  x=F[x][j],y=F[y][j];
	return F[x][0]; 
} 
void update(int x,int y){
	for(;x!=y;x=F[x][0]) q[++cnt]=x;
	for(;cnt;cnt--)
	x=q[cnt],y=F[x][0],f[y][0]-=f[x][1],f[y][1]-=min(f[x][0],f[x][1]); 
} 
void up(int x,int y){
	for(int fa=F[x][0];x!=y;x=fa,fa=F[x][0])
	f[fa][0]+=f[x][1],f[fa][1]+=min(f[x][0],f[x][1]);  
} 
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read(),i=read();
	fo(i,1,n) p[i]=read();
	fo(i,1,n-1) {
		int x=read(),y=read();
		g[x].push_back(y),g[y].push_back(x);
	} 
	dfs(1,0); 
	fo(j,1,16) 
	fo(i,1,n) F[i][j]=F[F[i][j-1]][j-1]; 
	for(;m--;) {
		int a=read(),x=read(),b=read(),y=read();
		int lc=lca(a,b); 
		update(lc,1),update(a,lc),update(b,lc); 
		ax=f[a][x^1],by=f[b][y^1],f[a][x^1]=f[b][y^1]=inf; 
		up(a,lc),up(b,lc),up(lc,1); 
		ans=min(f[1][0],f[1][1]);
		if (ans>=inf) puts("-1");else printf("%lld\n",ans);  
		update(lc,1),update(a,lc),update(b,lc); 
		f[a][x^1]=ax,f[b][y^1]=by;
		up(a,lc),up(b,lc),up(lc,1); 
	}return 0; 
} 
