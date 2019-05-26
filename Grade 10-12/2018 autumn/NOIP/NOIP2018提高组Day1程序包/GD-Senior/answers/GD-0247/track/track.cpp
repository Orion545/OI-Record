#include<cstdio>
#include<cstdlib>
#define maxn 2000
int map[maxn][maxn];
int vis[maxn];
int n,m;
int ans=0;

int max(int a,int b) {
	return a>b?a:b;
}

int dfs(int now) {
	vis[now]=1;
	int tot=0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]&&map[now][i]!=-1) {
			tot=max(tot,dfs(i)+map[now][i]);
		}
	}
	vis[now]=0;
	return tot;
}

void judge() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
}

int main() {
	judge();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			map[i][j]=-1;
		}
	}
	for(int i=1;i<=n-1;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		map[u][v]=w;
		map[v][u]=w;
	}
	
	for(int i=1;i<=n;i++) {
		ans=max(dfs(i),ans);
		//printf("s:%d l:%d\n",i,dfs(i));
	}
	printf("%d",ans);
}

