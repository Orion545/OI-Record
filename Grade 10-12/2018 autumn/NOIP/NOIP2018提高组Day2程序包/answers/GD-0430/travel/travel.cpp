#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=5005;
using namespace std;
int n,m,x,y;
int a[INF][INF],dfs_ord[INF];
int mn[INF];//维护一个mn数组，判断当前每个点可转移的最小的点 
bool vis[INF];
inline void add(int x,int y){
	a[x][++a[x][0]]=y;
	a[y][++a[y][0]]=x;
}
inline void dfs(int x){
	for (int u=1;u<=a[x][0];++u){
		int to=a[x][u];
		if (!vis[to]){
			vis[to]=1;
			dfs_ord[++dfs_ord[0]]=to;
			dfs(to);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<a[i][0];++j){
			for (int k=j+1;k<=a[i][0];++k){
				if (a[i][j]>a[i][k]){
					int t=a[i][j]; a[i][j]=a[i][k]; a[i][k]=t;
				}
			} 
		}
		mn[i]=a[i][1];
	}
	vis[1]=1;
	mn[a[1][1]]=a[a[1][1]][2];
	//for (int i=1;i<=n;++i) printf("%d\n",mn[i]);
	dfs_ord[++dfs_ord[0]]=1;
	dfs(1);
	for (int i=1;i<=dfs_ord[0];++i) printf("%d ",dfs_ord[i]);
	return 0;
}
