#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
#define MAXN 5000+10

int n, m, a, b, x, y, cost[MAXN];
int type;  char ch[10];
int head[MAXN], adj[MAXN], next[MAXN], dp[2][MAXN], tot=0;

void Work(int u, int fa){
	for(int tmp=head[u]; tmp!=-1; tmp=next[tmp]){
		if(adj[tmp]==fa)  continue;
		Work(adj[tmp], u);
	}
	dp[1][u]=cost[u];
	for(int tmp=head[u]; tmp!=-1; tmp=next[tmp]){
		if(adj[tmp]==fa)  continue;
		dp[1][u]+=min(dp[1][adj[tmp]], dp[0][adj[tmp]]);
	}

	for(int tmp=head[u]; tmp!=-1; tmp=next[tmp]){
		if(adj[tmp]==fa)  continue;
		dp[0][u]+=dp[1][adj[tmp]];
	}
	
	if(a==u){
		if(x==1)  dp[0][u]=1000000000;
		else  dp[1][u]=1000000000;
	}
	if(b==u){
		if(y==1)  dp[0][u]=1000000000;
		else  dp[1][u]=1000000000;
	}
}

void Addedge(int u, int v){
	adj[++tot]=v, next[tot]=head[u], head[u]=tot;
}

int main(){
	freopen("defense.in","r", stdin);
	freopen("defense.out","w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", ch);
	for(int i=1; i<=n; i++)
		scanf("%d", &cost[i]);
	memset(head, -1, sizeof(head));
	memset(adj, -1, sizeof(adj));
	memset(next, -1, sizeof(next));
	for(int i=1, u, v; i<n; i++)
		scanf("%d%d", &u, &v),
		Addedge(u, v), Addedge(v, u);
	for(int i=1; i<=m; i++){
		scanf("%d%d%d%d", &a, &x, &b, &y);
		memset(dp, 0, sizeof(dp));
		Work(1, 0);
		if(dp[0][1]>=1000000000 && dp[1][1]>=1000000000)
			printf("-1\n");
		else  printf("%d\n", min(dp[0][1], dp[1][1]));
	}
	fclose(stdin);  fclose(stdout);
	return 0;
}
