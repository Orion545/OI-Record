#include <cstdio>
#include <cstring>
#define MAXN 5010

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

int n,m;
int g[MAXN],nume;
bool visit[MAXN];
int ans[MAXN],na;
int st[MAXN],ns;
int c[MAXN],nc;

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

void dfs(int x){
	c[x]=nc;
	for(int i=g[x];~i;i=e[i].next)
		if(!visit[e[i].to] && !c[e[i].to])
			dfs(e[i].to);
}

void gao(){
	visit[1]=1;
	st[++ns]=1;
	ans[++na]=1;
	while(na<n){
		nc=0;
		for(int i=1;i<=n;i++) c[i]=0;
		int lim=0;
		for(int i=1;i<=ns;i++){
			int x=st[i];
			for(int j=g[x];~j;j=e[j].next)
				if(!visit[e[j].to] && !c[e[j].to]){
					lim=i;
					nc++;
					dfs(e[j].to);
				}
		}
		int t1=n+1,t2;
		for(int i=ns;i>=lim;i--){
			int x=st[i];
			for(int j=g[x];~j;j=e[j].next)
				if(!visit[e[j].to] && e[j].to<t1){
					t1=e[j].to;
					t2=i;
				}
		}
		st[ns=(t2+1)]=t1;
		visit[t1]=1;
		ans[++na]=t1;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(g,-1,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	gao();
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
