#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=5e3+10;
const int maxm=maxn<<1;
int n,m,ans[maxn],b[maxn];
namespace graph {
	struct E {
		int v,id,nxt;
	} e[maxm];
	int h[maxn],tot=0;
	int g[maxn][maxn];
	int no,top;
	bool vis[maxn];
	inline void add(int x,int y,int id) {
		g[x][y]=g[y][x]=id;
	}
	void prepare() {
		for (int i=1;i<=n;++i) for (int j=n;j>0;--j) if (g[i][j]) {
			e[++tot]=(E){j,g[i][j],h[i]};
			h[i]=tot;
		}
	}
	void dfs(int x) {
		vis[x]=true;
		b[++top]=x;
		for (int i=h[x];i;i=e[i].nxt) {
			int v=e[i].v,id=e[i].id;
			if (id==no || vis[v]) continue;
			dfs(v);
		}
	}
	bool work(int _no) {
		no=_no,top=0;
		fill(vis+1,vis+n+1,false);
		dfs(1);
		return top==n;
	}
}
bool smaller(int a[],int b[]) {
	for (int i=1;i<=n;++i) {
		if (a[i]<b[i]) return true;
		if (a[i]>b[i]) return false;
	}
	return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;++i) {
		int x=read(),y=read();
		graph::add(x,y,i);
	}
	graph::prepare();
	fill(ans+1,ans+n+1,n+1);
	for (int i=0;i<=m;++i) {
		bool flag=graph::work(i); // delete edge i
		if (flag && smaller(b,ans)) copy(b+1,b+n+1,ans+1);
	}
	for (int i=1;i<=n;++i) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
