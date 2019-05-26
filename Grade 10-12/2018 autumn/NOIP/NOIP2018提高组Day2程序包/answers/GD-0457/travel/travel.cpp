using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5000
#define M 5000
int n,m;
int to[N+1][N+1];
int nto[N+1];
void dfs(int,int);
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		to[u][++nto[u]]=v;
		to[v][++nto[v]]=u;
	}
	for (int i=1;i<=n;++i)
		sort(to[i]+1,to[i]+nto[i]+1);
	if (m==n-1){
		dfs(1,0);
		return 0;
	}
	return 0;
}
void dfs(int x,int fa){
	printf("%d ",x);
	for (int i=1;i<=nto[x];++i)
		if (to[x][i]!=fa) dfs(to[x][i],x);
}
