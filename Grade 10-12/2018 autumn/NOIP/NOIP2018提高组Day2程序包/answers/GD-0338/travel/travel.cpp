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

int n, m, node, graph[MAXN][MAXN];
int onloop[MAXN];
int fa[MAXN], on_loop[MAXN];
int ans[2][MAXN];

int Getfa(int u){
	return fa[u]=fa[u]==u?u:Getfa(fa[u]);
}

bool DFS1(int u, int to, int fa){
	bool jud=0;
	if(u==to)
		return true;
	for(int i=1; i<=n; i++){
		if(i!=fa && graph[u][i]==1)
			jud=max(jud, DFS1(i, to, u));
	}
	if(jud==1){
		onloop[u]=1;
		return true;
	}
	else  return false;
}

void DFS2(int u, int fa){
	ans[1][++node]=u;
	for(int i=1; i<=n; i++){
		if(i!=fa && graph[u][i]==1)
			DFS2(i, u);
	}
}

int main(){
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout);
	scanf("%d%d", &n, &m);
	memset(onloop, 0, sizeof(onloop));
	memset(ans[0], 1, sizeof(ans[0]));
	for(int i=1; i<=n; i++)
		fa[i]=i;
	int flag=0;
	for(int i=1, u, v; i<=m; i++){
		scanf("%d%d", &u, &v);
		fa[u]=Getfa(fa[u]), fa[v]=Getfa(fa[v]);
		if(fa[u]==fa[v]){
			onloop[u]=1, onloop[v]=1;
			DFS1(u, v, 0);  flag=1;
		}
		else  fa[fa[u]]=fa[v];
		graph[u][v]=graph[v][u]=1;
	}
	for(int i=1; i<=n; i++){
		if(onloop[i]){
			for(int j=1; j<=n; j++)
				if(graph[i][j]==1 && onloop[j] && i!=j){
					graph[i][j]=graph[j][i]=0;  node=0;
					DFS2(1, 0);
					graph[i][j]=graph[j][i]=1;
					for(int k=1; k<=n; k++)
						if(ans[0][k]<ans[1][k])  break;
						else if(ans[0][k]>ans[1][k]){
							for(int l=1; l<=n; l++)
								ans[0][l]=ans[1][l];
							break;
						}
				}
		}
	}
	if(flag==0){
		node=0;
		DFS2(1, 0);
		for(int k=1; k<=n; k++)
			if(ans[0][k]>ans[1][k])
				for(int l=1; l<=n; l++)
					ans[0][l]=ans[1][l];
	}
	for(int i=1; i<=n; i++)
		printf("%d ", ans[0][i]);
	printf("\n");
	fclose(stdin);  fclose(stdout);
	return 0;
}
