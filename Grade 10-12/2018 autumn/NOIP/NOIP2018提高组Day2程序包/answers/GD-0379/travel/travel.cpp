#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

const int N=5010;
vector<int>g[N];
int rnk[N],cnt=0,xx,yy,zz,mn,tot=0,huan[N],sz[N],dep[N],fa[N],vis[N];
bool nc[N];

void rd(int &x){
	int y=0;char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') y=y*10+c-'0',c=getchar();
	x=y;
}

void dfs(int x){
	vis[x]=1;
	dep[x]=dep[fa[x]]+1;
	rnk[++cnt]=x;
	for(int i=0;i<g[x].size();++i){
		int to=g[x][i];
		if(to!=fa[x]){
			if(!vis[to]) fa[to]=x,dfs(to);
			else xx=x,yy=to;
		}
	}
}


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,u,v,i;
	rd(n),rd(m);
	for(i=1;i<=m;++i){
		rd(u),rd(v);
		g[u].pb(v),g[v].pb(u);
	}
	for(i=1;i<=n;++i) sort(g[i].begin(),g[i].end());
	dfs(1);
	for(i=1;i<=n;++i) printf("%d ",rnk[i]);
}
