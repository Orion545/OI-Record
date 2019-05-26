#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int M = 1000005;
const int MOD = 1000000007;
int n, m, line[105], vis[9][9], pic[9][9];

void dfs(int tx,int ty,int num){
	if ( tx==n && ty==m ){
		line[++line[0]] = num;
		return ;
	}
	if ( tx+1<=n && !vis[tx+1][ty] ){
		vis[tx+1][ty] ++ ;
		dfs(tx+1,ty,num*10+pic[tx+1][ty]);
		vis[tx+1][ty] -- ;
	}
	if ( ty+1<=m && !vis[tx][ty+1] ){
		vis[tx][ty+1] ++ ;
		dfs(tx,ty+1,num*10+pic[tx][ty+1]);
		vis[tx][ty+1] -- ;
	}
	return ;
}

int isok(){
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			vis[i][j] = 0;
		}
	}
	vis[1][1] = 1;
	line[0] = 0;
	dfs(1,1,pic[1][1]);
	int flag = 1;
	for (int i = 2; i <= line[0]; i ++)
		if ( line[i]>line[i-1] ) flag = 0;
	return flag;
}

int EasyWork(){
	int tot = n*m, Res1 = 0;
	for (int i = 0; i < (1<<tot); i ++ ){
		for (int jx = 1; jx <= n; jx ++){
			for (int jy = 1; jy <= m; jy ++){
				if ( (1<<((jx-1)*m+jy-1)) & i ) pic[jx][jy] = 1;
				else pic[jx][jy] = 0; 
			}			
		}
		if ( isok() ) Res1 ++ ;
	}
	return Res1;
}

int SolveN1(){
	int Res2 = 1;
	for (int i = 1; i <= m; i ++)
		Res2 = (Res2 * 2) % MOD;
	return Res2;
}

long long SolveN2(){
	long long Res3 = 4;
	for (int i = 1; i < m; i ++)
		Res3 = (Res3 * 3) % MOD;
	return Res3;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	scanf("%d%d", &n, &m);
	if ( n*m<10 )
		printf("%d", EasyWork());
	else if ( n==1 )
		printf("%d", SolveN1());
	else if ( n==2 )
		printf("%lld", SolveN2());

	return 0;
}
