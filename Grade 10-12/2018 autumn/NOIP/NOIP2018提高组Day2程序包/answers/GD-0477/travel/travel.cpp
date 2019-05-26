#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N=5010;
int h[N],c[N],ans[N];
int n,m,tot,now,x,y;
int deg[N],vis[N],s[N];
struct edge{int y,next;}g[N*2];
vector<int>son[N];

void adp(int x,int y){
	g[++tot].y=y;
	g[tot].next=h[x];
	h[x]=tot;
}

void dfs(int x,int fa){
	ans[++now]=x;
	for (int i=h[x];i;i=g[i].next)
		if (g[i].y!=fa) son[x].push_back(g[i].y);
	sort(son[x].begin(),son[x].end());
	for (int i=0;i<son[x].size();i++)
		dfs(son[x][i],x);
}

void dfs1(int x,int fa){
	ans[++now]=x;vis[x]=1;
	for (int i=h[x];i;i=g[i].next)
		if (g[i].y!=fa && !vis[g[i].y]) 
			son[x].push_back(g[i].y);
	sort(son[x].begin(),son[x].end());
	for (int i=0;i<son[x].size();i++)
		dfs1(son[x][i],x);
}

void gao(int x,int flag,int w){
	ans[++now]=x;vis[x]=1;int nxt=0;
	for (int i=h[x];i;i=g[i].next)
		if (!vis[g[i].y]) nxt=g[i].y;
	if (flag && nxt>w)
		gao(w,0,0); else 
	if (nxt)
		gao(nxt,flag,w);
}

void work(){
	int t=0;ans[++now]=1;vis[1]=1;
	for (int i=h[1];i;i=g[i].next)
		s[++t]=g[i].y;
	if (s[1]<s[2])
		gao(s[1],1,s[2]); else 
		gao(s[2],1,s[1]);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if (m==n-1){
		for (int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			adp(x,y);adp(y,x);
		}
		dfs(1,0);
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	} else {
		for (int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			deg[x]++;deg[y]++;
			adp(x,y);adp(y,x);
		}
		int ok=1;
		for (int i=1;i<=n;i++)
			if (deg[i]>=3) ok=0;
		if (ok)
			work(); else 
			dfs1(1,0);
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
}
