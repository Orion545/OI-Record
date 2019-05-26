#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read() {
	int f=1,x=0;
	char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?-1:1;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
	return f*x;
}
const int N=3e5+50;
const ll inf=1e18;
int X,A,Y,B,n,m,i,x,y;
char type[10];
int to[N<<1],nxt[N<<1],lst[N],tot,fr[N];
ll f[N],g[N],p[N];
inline void add(int x,int y) { to[++tot]=y,nxt[tot]=lst[x],lst[x]=tot; }
void dfs(int x,int fa) {
	int i,j;
	fr[x]=fa;
	ll sum=0,sum1=0;
	for (i=lst[x];i;i=nxt[i]) if (to[i]!=fa) dfs(to[i],x),sum+=f[to[i]];
	for (i=lst[x];i;i=nxt[i]) {
		j=to[i];
		if (j==fa) continue;
		sum1+=min(f[j],g[j]);
	}
	g[x]=sum,f[x]=sum1+p[x];
}
void dp(int x,int fa) {
	int i,j;
	ll sum=0,sum1=0;
	f[x]=g[x]=0;
	for (i=lst[x];i;i=nxt[i]) {
		j=to[i];
		if (j==fa) continue;
		dp(j,x);
		sum=f[j]>=inf?inf:sum+f[j];
		sum=min(sum,inf);
	}
	for (i=lst[x];i;i=nxt[i]) {
		j=to[i];
		if (j==fa) continue;
		sum1=min(f[j],g[j])>=inf?inf:sum1+min(f[j],g[j]);
		sum1=min(sum1,inf);
	}
	if (x==A) {
		if (X) f[x]=sum1+p[x],g[x]=inf;
		else f[x]=inf,g[x]=sum;
	}
	if (x==B) {
		if (Y) f[x]=sum1+p[x],g[x]=inf;
		else f[x]=inf,g[x]=sum;
	}
	if (x!=A&&x!=B) g[x]=sum,f[x]=sum1+p[x];
	f[x]=min(f[x],inf),g[x]=min(g[x],inf);
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	scanf("%s",type);
	for (i=1;i<=n;i++) p[i]=read();
	for (i=1;i<n;i++) {
		x=read(),y=read();
		add(x,y),add(y,x);
	}
//	if (n<=2000) {
		for (i=1;i<=m;i++) {
			A=read(),X=read(),B=read(),Y=read();
			dp(1,0);
			if (f[1]>=inf&&g[1]>=inf) printf("-1\n");
			else printf("%lld\n",min(f[1],g[1]));
		}
//		return 0;	
//	}
//	dfs(x,0);
//	if ()
	return 0;
}
