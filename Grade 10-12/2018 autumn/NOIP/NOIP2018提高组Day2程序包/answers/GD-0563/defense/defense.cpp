#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1000000000000ll;
int n,m;
#define Maxn 100010
int val[Maxn];
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
int fa[Maxn],depth[Maxn];
ll dp[Maxn][2];
ll pre[Maxn][2];
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
void dfs(int u,int f){
	fa[u]=f;depth[u]=depth[f]+1;
	for(int i=head[u];i;i=nxt[i])
	if(v[i]^f)dfs(v[i],u);
	dp[u][0]=0;
	for(int i=head[u];i;i=nxt[i])
	if(v[i]^f)dp[u][0]+=dp[v[i]][1];
	dp[u][1]=val[u];
	for(int i=head[u];i;i=nxt[i])
	if(v[i]^f)dp[u][1]+=min(dp[v[i]][0],dp[v[i]][1]);
	pre[u][0]=dp[u][0];
	pre[u][1]=dp[u][1];
}
char opt[10];
int A,x,a,b,B,y;

void trans(int u,int ty){
	if(u==A&&ty!=x){
		dp[u][ty]=inf;
		return;
	}
	if(u==B&&ty!=y){
		dp[u][ty]=inf;
		return;
	}
	if(ty==0){
	dp[u][0]=0;
	for(int i=head[u];i;i=nxt[i])
	if(v[i]!=fa[u])dp[u][0]+=dp[v[i]][1];
	dp[u][0]=min(dp[u][0],inf);
}else{
	dp[u][1]=val[u];
	for(int i=head[u];i;i=nxt[i])
	if(v[i]!=fa[u])dp[u][1]+=min(dp[v[i]][0],dp[v[i]][1]);
	dp[u][1]=min(dp[u][1],inf);
}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,opt);
	int s,e;
	for(register int i=1;i<=n;++i)scanf("%d",&val[i]);
	for(register int i=1;i<n;++i){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
	}
	dfs(1,0);
	for(register int i=1;i<=m;++i){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		A=a;B=b;
		for(register int j=1;j<=n;++j)
		dp[j][0]=pre[j][0],dp[j][1]=pre[j][1];
		dp[a][x^1]=inf;dp[b][y^1]=inf;
		while(depth[a]>depth[b]){
			trans(a,0);
			trans(a,1);
			a=fa[a];
		}
        while(depth[b]>depth[a]){
        	trans(b,0);
        	trans(b,1);
        	b=fa[b];
        }		
        while(a!=b){
        	trans(a,0);
        	trans(a,1);
        	trans(b,0);
        	trans(b,1);
        	a=fa[a];
        	b=fa[b];
        }
        while(a!=0){
        	trans(a,0);
        	trans(a,1);
        	a=fa[a];
        }
        ll Ans=min(dp[1][0],dp[1][1]);
        if(Ans==inf)puts("-1");
        else printf("%lld\n",Ans);
	}
	return 0;
}
