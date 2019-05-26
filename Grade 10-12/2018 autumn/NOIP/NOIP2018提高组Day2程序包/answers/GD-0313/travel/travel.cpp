#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 5005;
int n, m, to[N][N], from[N], vis[N], path[N];

void dfs(int k,int x){
	if ( k==n ) return;
	int MIN = n+1;
	for (int i = 1; i <= to[x][0]; i ++)
		if ( !vis[to[x][i]] ) MIN = min(MIN,to[x][i]);
	if ( MIN!=n+1 ){
		path[k+1] = MIN;
		vis[MIN] ++;
		if ( !from[MIN] ) from[MIN] = x;
		dfs(k+1,MIN);
	}
	else{
		dfs(k,from[x]);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++){
		int x, y;
		scanf("%d%d", &x, &y);
		to[x][++to[x][0]] = y;
		to[y][++to[y][0]] = x;
	}
	
//	if ( m==n-1 ){
		vis[1] = 1;
		path[1] = 1;
		dfs(1,1);
		for (int i = 1; i <= n; i ++) printf("%d ", path[i]);
//	}
//	else{
		
//	}
	
	return 0;
}
