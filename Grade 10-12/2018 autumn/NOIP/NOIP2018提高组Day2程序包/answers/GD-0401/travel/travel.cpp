#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
inline int read() {
	int f=1,x=0;
	char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?-1:1;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
	return f*x;
}
const int N=1e4+50;
int i,j,n,m,x,y,ans[N],cnt,tot,lca,a[N],b[N];
int tota,totb,totc,tmp[N],fr[N],gx,gy;
struct edge {
	int x,y;
} e[N<<1],tt[N<<1];
bool vis[N];
vector<int> g[N];
void dfs(int x) {
	tmp[++cnt]=x;
	vis[x]=1;
	int sz=g[x].size();
	for (int i=0;i<sz;i++) {
		if (!vis[g[x][i]]) dfs(g[x][i]);
	}
}
void DFS(int x,int fa) {
	vis[x]=1;
	fr[x]=fa;
	int sz=g[x].size();
	for (int i=0;i<sz;i++) {
		if (vis[g[x][i]]&&g[x][i]!=fa) gx=x,gy=g[x][i];
		if (!vis[g[x][i]]) DFS(g[x][i],x);
	}
}
inline void cmp() {
	for (int i=1;i<=n;i++) {
		if (tmp[i]==ans[i]) continue;
		if (tmp[i]!=ans[i]) {
			if (tmp[i]<ans[i]) for (int j=1;j<=n;j++) ans[j]=tmp[j];
			return;
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for (i=1;i<=m;i++) {
		x=read(),y=read();
		e[++tot]=(edge){x,y};
		if (e[tot].x>e[tot].y) swap(e[tot].x,e[tot].y);
		g[x].push_back(y),g[y].push_back(x);
	}
	ans[1]=0x3f3f3f3f;
	if (n==m) {
		for (i=1;i<=n;i++) vis[i]=0;
		DFS(1,0);
		tota=totb=totc=0;
		lca=0;
		tt[++totc]=(edge){gx,gy};
		if (tt[totc].x>tt[totc].y) swap(tt[totc].x,tt[totc].y);
		while (gx) a[++tota]=gx,gx=fr[gx];
		while (gy) b[++totb]=gy,gy=fr[gy];
		for (i=1;i<=n;i++) vis[i]=0;
		for (i=tota;i>=1;i--) vis[a[i]]=1;
		for (i=1;i<=totb;i++) {
			if (vis[b[i]]) continue;
			if (i!=totb) {
				tt[++totc]=(edge){b[i],b[i+1]};
				if (tt[totc].x>tt[totc].y) swap(tt[totc].x,tt[totc].y);
			}
		}
		for (i=1;i<=totc;i++) {
			for (j=1;j<=n;j++) g[j].clear();
			for (j=1;j<=tot;j++) {
				if (e[j].x==tt[i].x&&e[j].y==tt[i].y) continue;
				g[e[j].x].push_back(e[j].y),g[e[j].y].push_back(e[j].x);
			} 
			for (j=1;j<=n;j++) sort(g[j].begin(),g[j].end());
			for (j=1;j<=n;j++) vis[j]=0;
			cnt=0;
			dfs(1);
			cmp();
		}
	} else {
		for (j=1;j<=tot;j++) g[e[i].x].push_back(e[i].y),g[e[i].y].push_back(e[i].x);
		for (i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
		for (i=1;i<=n;i++) vis[i]=0;
		cnt=0;
		dfs(1);
		cmp();
	}
	for (i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
