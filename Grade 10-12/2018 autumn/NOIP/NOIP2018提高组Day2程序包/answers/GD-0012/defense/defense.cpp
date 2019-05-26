#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a) for(int i=lst[a];i;i=nxt[i])
using namespace std;

typedef long long ll;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

void write(ll x) {
	if (!x) {puts("0");return;}
	char ch[20];int tot=0;
	for(;x;x/=10) ch[++tot]=x%10+'0';
	fd(i,tot,1) putchar(ch[i]);
	puts("");
}

const int N=1e5+5;
const ll inf=1e12;

int t[N<<1],nxt[N<<1],lst[N],l;
void add(int x,int y) {t[++l]=y;nxt[l]=lst[x];lst[x]=l;}

int n,m,dep[N],fa[N][17],p[N],opt[N];
ll f[N][2],g[N][2],h[2],F[N][17][2][2],G[2][2];
char ty[10];

struct Que{
	int x,y,id;
}ask[N];

void dfs(int x,int y) {
	fa[x][0]=y;dep[x]=dep[y]+1;
	fo(i,1,16) fa[x][i]=fa[fa[x][i-1]][i-1];
	rep(i,x) if (t[i]!=y) dfs(t[i],x);
}

void dp(int x,int y) {
	rep(i,x) if (t[i]!=y) dp(t[i],x);
	f[x][0]=0;f[x][1]=p[x];
	if (opt[x]!=-1) f[x][opt[x]^1]=inf;
	rep(i,x)
		if (t[i]!=y) {
			f[x][0]+=f[t[i]][1];
			f[x][1]+=min(f[t[i]][0],f[t[i]][1]);
		}
}

void calc(int x,int y) {
	h[0]=0;h[1]=p[x];
	rep(i,x)
		if (t[i]!=y) {
			h[0]+=f[t[i]][1];
			h[1]+=min(f[t[i]][0],f[t[i]][1]);
		}
	h[0]+=g[x][1];h[1]+=min(g[x][0],g[x][1]);
	rep(i,x)
		if (t[i]!=y) {
			g[t[i]][0]=h[0]-f[t[i]][1];
			g[t[i]][1]=h[1]-min(f[t[i]][0],f[t[i]][1]);
		}
	rep(i,x) if (t[i]!=y) calc(t[i],x);
}

int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	fd(j,16,0) if (dep[fa[x][j]]>dep[y]) x=fa[x][j];
	x=dep[x]==dep[y]?x:fa[x][0];
	fd(j,16,0) if (fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
	return x==y?x:fa[x][0];
}

void solve(int &x,int z,ll *G,int op) {
	if (fa[x][0]==z) {
		G[op]=f[x][op];
		G[op^1]=inf;
		return;
	}
	bool fir=0;
	fd(j,16,0)
		if (dep[fa[x][j]]>dep[z]) {
			if (!fir) {
				fo(y,0,1) G[y]=F[x][j][op][y];
				x=fa[x][j];fir=1;continue;
			}
			fo(y,0,1) {
				h[0]=h[1]=inf;
				fo(y1,0,1) h[y1]=min(h[y1],G[y]+F[x][j][y][y1]-f[x][y]);
			}
			fo(y,0,1) G[y]=h[y];
			x=fa[x][j];
		}
}

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();scanf("%s",ty+1);
	fo(i,1,n) p[i]=read();
	fo(i,1,n-1) {
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	fo(i,1,n) opt[i]=-1;
	dfs(1,0);dp(1,0);calc(1,0);
	if (n<=2000) {
		fo(i,1,m) {
			int x=read(),opx=read();
			int y=read(),opy=read();
			if (x==y&&opx!=opy) {puts("-1");continue;} 
			if (!opx&&!opy) {
				if (fa[x][0]==y||fa[y][0]==x) {
					puts("-1");
					continue;
				}
			}
			opt[x]=opx;opt[y]=opy;
			dp(1,0);
			opt[x]=-1;opt[y]=-1;
			write(min(f[1][0],f[1][1]));
		}
		return 0;
	}
	if (ty[2]=='2') {
		fo(i,1,m) {
			int x=read(),opx=read();
			int y=read(),opy=read();
			if (x==y) if (opx!=opy) {puts("-1");continue;}
			if (!opx&&!opy) {
				if (fa[x][0]==y||fa[y][0]==x) {
					puts("-1");
					continue;
				}
			}
			if (fa[x][0]==y) write(f[x][opx]+g[x][opy]);
			if (fa[y][0]==x) write(f[y][opy]+g[y][opx]);
		}
		return 0;
	}
	memset(F,63,sizeof(F));
	fo(i,1,n)
		if (fa[i][0]) {
			int z=fa[i][0];
			fo(x,0,1) fo(y,0,1) {
				if (!x&&!y) continue;
				F[i][0][x][y]=f[z][y]-((y==1)?min(f[i][0],f[i][1]):f[i][1]);
				F[i][0][x][y]+=f[i][x];
			}
		}
	fo(j,1,16)
		fo(i,1,n)
			if (fa[i][j]) {
				int z=fa[i][j-1];
				fo(x1,0,1) fo(y1,0,1)
					fo(y2,0,1) {
						ll now=F[i][j-1][x1][y1]+F[z][j-1][y1][y2];
						now-=f[z][y1];
						F[i][j][x1][y2]=min(F[i][j][x1][y2],now);
					}
			}
	fo(i,1,m) {
		int x=read(),opx=read();
		int y=read(),opy=read();
		int z=lca(x,y);
		if (x==y) {
			if (opx!=opy) {puts("-1");continue;}
			if (opx==1) write(f[x][1]+min(g[x][0],g[x][1]));
			else write(f[x][0]+g[x][1]);
			continue;
		}
		if (!opx&&!opy) {
			if (fa[x][0]==y||fa[y][0]==x) {
				puts("-1");
				continue;
			}
		}
		if (z==x||z==y) {
			if (z==x) swap(x,y),swap(opx,opy);
			solve(x,z,G[0],opx);
			ll ans=inf;
			ll now=f[y][opy];
			now-=(opy==1)?min(f[x][0],f[x][1]):f[x][1];
			now+=(opy==1)?min(G[0][0],G[0][1]):G[0][1];
			now+=(opy==1)?min(g[y][0],g[y][1]):g[y][1];
			ans=min(ans,now);
			write(ans);
			continue;
		}
		solve(x,z,G[0],opx);
		solve(y,z,G[1],opy);
		ll ans=inf;
		fo(op,0,1) {
			ll now=f[z][op];
			now-=(op==1)?min(f[x][0],f[x][1]):f[x][1];
			now-=(op==1)?min(f[y][0],f[y][1]):f[y][1];
			now+=(op==1)?min(G[0][0],G[0][1]):G[0][1];
			now+=(op==1)?min(G[1][0],G[1][1]):G[1][1];
			now+=(op==1)?min(g[z][0],g[z][1]):g[z][1];
			ans=min(ans,now);
		}
		write(ans);
	}
	return 0;
}
