#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
#define MAXN 2000+10
#define INF 0x7fffffff

int n, m;
int dp[MAXN][MAXN];
int head[MAXN], adj[MAXN], next[MAXN], dis[MAXN], tot=0;

void Addedge(int u, int v, int dist){
	adj[++tot]=v, next[tot]=head[u], dis[tot]=dist, head[u]=tot;
}

void DFS(int u, int fa, int wl){
	int v1, v2, d1, d2, degree=0;
	for(int tmp=head[u]; tmp!=-1; tmp=next[tmp]){
		if(adj[tmp]!=fa){
			degree++;
			if(degree==1)  v1=adj[tmp], d1=dis[tmp];
			if(degree==2)  v2=adj[tmp], d2=dis[tmp];
			DFS(adj[tmp], u, wl);
		}
	}
	if(degree==1){
		for(int i=0; i<=m; i++){
			if(dp[v1][i]<0)  continue;
			if(dp[v1][i]+d1>=wl)
				dp[u][i+1]=max(dp[u][i+1], 0);
			dp[u][i]=max(dp[u][i], dp[v1][i]+d1);
		}
	}
	if(degree==2){
		for(int i=0; i<=m; i++){
			for(int j=0; j<=m-i; j++){
				if(dp[v1][i]<0 || dp[v2][j]<0)  continue;
				if(dp[v1][i]+dp[v2][j]+d1+d2>=wl)
					dp[u][i+j+1]=max(dp[u][i+j+1], 0);
				if(dp[v1][i]+d1>=wl)
					dp[u][i+j+1]=max(dp[u][i+j+1], dp[v2][j]+d2);
				if(dp[v2][j]+d2>=wl)
					dp[u][i+j+1]=max(dp[u][i+j+1], dp[v1][i]+d1);
				if(dp[v2][j]+d2>=wl && dp[v1][i]+d1>=wl)
					dp[u][i+j+2]=max(dp[u][i+j+2], 0);
				dp[u][i+j]=max(max(dp[v1][i]+d1, dp[v2][j]+d2), dp[u][i+j]);
			}
		}
	}
	if(degree==0){
		dp[u][0]=0;
	}
}

bool Jud(int wl){
	memset(dp, -63, sizeof(dp));
	DFS(1, 0, wl);
	if(dp[1][m]>=0)  return true;
	else  return false;
}

int main(){
	freopen("track.in","r", stdin);
	freopen("track.out","w", stdout);
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof(head));
	memset(adj, -1, sizeof(adj));
	memset(next, -1, sizeof(next));
	memset(dis, -1, sizeof(dis));
	for(int i=1, u, v, dist; i<n; i++){
		scanf("%d%d%d", &u, &v, &dist);
		Addedge(u, v, dist), Addedge(v, u, dist);
	}
	int l=0, r=10000000, mid;
	Jud(27);
	while(l<r){
		mid=(l+r+1)>>1;
		if(!Jud(mid))  r=mid-1;
		else  l=mid;
	}
	printf("%d\n", l);
	fclose(stdin);  fclose(stdout);
	return 0;
}
