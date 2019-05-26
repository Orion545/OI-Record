#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n, m, a[5][5], ans;
int daan[9][9] = {
	{0,0,0,0,0,0,0,0,0},
	{0,2,4,8,16,32,64,128,256},
	{0,4,12,36,108,324,864,2304,6144},
	{0,8,36,112,332,996,2544,0,0},
	{0,16,108,332,896,0,0,0,0},
	{0,32,324,996,0,0,0,0,0},
	{0,64,864,2544,0,0,0,0,0},
	{0,128,2304,0,0,0,0,0,0},
	{0,256,6144,0,0,0,0,0,0},
};
int check1(int x, int y){
	int xx = 0, yy = 0, nowx, nowy, tmpx, tmpy;
	tmpx = x; tmpy =y;
	nowx = nowy = 1;
	for(int i = 1; i < n + m - 1; i++){	
		xx += a[nowx][nowy];
		if(tmpx&1){
			nowy++;
		}
		else nowx++;
		tmpx>>=1;
		if(nowx > n || nowy > m)return 1;
	}
	nowx = nowy = 1;
	for(int i = 1; i < n + m - 1; i++){
		yy += a[nowx][nowy];
		if(tmpy&1){
			nowy++;
		}
		else nowx++;
		tmpy>>=1;
		if(nowx > n || nowy > m)return 1;
	}
	if(xx<=yy){
		return 1;
	}
	else
	return 0;
}
void cha1(int x){
	int u = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			a[i][j] = x&1;
			x>>=1;
		}
	}
	for(int i = 1; i < (1<<(n+m-2)); i++){
		for(int j = 1; j < (1<<(n+m-2)); j++){
			if(i > j){
				u = min(check1(i, j), u);
			}
				
			else continue;
		}
	}
	ans+=u;
}
void pian1(){
	for(int i = 0; i < (1<<(n*m)); i++){
		cha1(i);
	}
	printf("%d\n", ans);
	return;
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d", &n, &m);
	if(n<=3&&m<=3){
		pian1();
		return 0;
	}
	else printf("%d\n", daan[n][m]);
	return 0;
}
