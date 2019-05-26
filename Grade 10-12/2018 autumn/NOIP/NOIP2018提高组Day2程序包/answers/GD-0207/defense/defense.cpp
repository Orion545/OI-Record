#include<iostream>
#include<cstdio>
#include<cstring>
#define mxn 200010
using namespace std;
typedef long long LL;
const LL inf=1ll<<60;
int n,m,q,x,y,xx,yy,a[mxn],fa[mxn],dep[mxn],head[mxn];
LL f[mxn],g[mxn];
char typ[10];
struct ed{int to,nxt;}edge[mxn<<1];
void addedge(int u,int v){
	edge[++m]=(ed){v,head[u]};head[u]=m;
	edge[++m]=(ed){u,head[v]};head[v]=m;
}
void upd(int u){
	f[u]=a[u],g[u]=0;int v;
	for (int i=head[u];i;i=edge[i].nxt)
		if ((v=edge[i].to)!=fa[u]) f[u]+=min(f[v],g[v]),g[u]+=f[v];
}
void update(int u){
	upd(u);
	if (u!=fa[u]) update(fa[u]);
}
void solve(int x,int xx,int y,int yy){
	int num1,num2;
	if (xx) num1=g[x],g[x]=inf;
	else num1=f[x],f[x]=inf;
	if (x>1) update(fa[x]);
	if (yy) num2=g[y],g[y]=inf;
	else num2=f[y],f[y]=inf;
	if (y>1) update(fa[y]);
	if (min(f[1],g[1])>=inf) puts("-1");
	else printf("%lld\n",min(f[1],g[1]));
	if (yy) g[y]=num2;
	else f[y]=num2;
	if (y>1) update(fa[y]);
	if (xx) g[x]=num1;
	else f[x]=num1;
	if (x>1) update(fa[x]);
}
void dfs(int u,int fth,int d){
	dep[u]=d,fa[u]=fth;int v;
	for (int i=head[u];i;i=edge[i].nxt)
		if ((v=edge[i].to)!=fth) dfs(v,u,d+1);
	upd(u);
}
void read(int &x){
	x=0;char c=getchar();
	while (c<48||c>57) c=getchar();
	while (c>47&&c<58) x=x*10+c-48,c=getchar();
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&q,typ);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<n;++i) read(x),read(y),addedge(x,y);
	if (n>2000&&typ[0]=='A'){
		if (typ[1]=='1'){
			f[2]=a[2],f[3]=a[3],g[n]=a[n],g[n-1]=a[n-1];
			for (int i=4;i<=n;++i) f[i]=min(f[i-2],f[i-1])+a[i];
			for (int i=n-2;i;--i) g[i]=min(g[i+2],g[i+1])+a[i];
		}
		else{
			f[1]=a[1],f[2]=a[2],g[n]=a[n],g[n-1]=a[n-1];
			for (int i=3;i<=n;++i) f[i]=min(f[i-2],f[i-1])+a[i];
			for (int i=n-2;i;--i) g[i]=min(g[i+2],g[i+1])+a[i];
		}
		for (int i=1;i<=q;++i){
			read(x),read(xx),read(y),read(yy);
			if (x>y) m=x,x=y,y=m,m=xx,xx=yy,yy=m;
			int l=max(0,x-3+xx),r=min(n,y+3-yy),num=0;
			if (xx) num+=a[x];
			else num+=a[x-1]+a[x+1];
			if (yy) num+=a[y];
			else num+=a[y-1]+a[y+1];
			if (x+1==y&&!xx&&!yy) puts("-1");
			else if (x+1==y&&!xx) num-=a[y];
			else if (x+1==y&&!yy) num-=a[x];
			printf("%lld\n",min(f[l],l?f[l-1]:0)+min(g[r],g[r+1])+num);
		}
		return 0;
	}
	dfs(1,1,1);
	for (int i=1;i<=q;++i){
		read(x),read(xx),read(y),read(yy);
		if (dep[x]<dep[y]) solve(y,yy,x,xx);
		else solve(x,xx,y,yy);
	}
	return 0;
}
