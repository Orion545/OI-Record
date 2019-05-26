using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 8
#define M 1000000
int n,m;
int mat[N][M];
int now;
bool ok(int x,int y,int s){
	s+=mat[x][y];
	if (x==n-1 && y==m-1){
		if (s>=now){
			now=s;
			return 1;
		}
		return 0;
	}
	if (y<m-1){
		if (!ok(x,y+1,s))
			return 0;
	}
	if (x<n-1){
		if (!ok(x+1,y,s))
			return 0;
	}
	return 1;
}
int ans=0;
void dfs(int x,int y){
	if (y==m){
		x++;
		y=0;
	}
	if (x==n){
		now=0;
		ans+=ok(0,0,mat[0][0]);
		return;	
	}
	mat[x][y]=0;
	dfs(x,y+1);
	mat[x][y]=1;
	dfs(x,y+1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}
