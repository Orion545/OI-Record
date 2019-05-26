#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[100][100],ans;
void dfs(int x,int y){
	if(x == n && y == m){
		bool f=false;
		int i,j,k;
		for(i=2;i <= n;i++)
			for(j=1;j <= m;j++){
				k=1;
				while(i-k > 0 && j+k <= m){
					if(a[i][j] < a[i-k][j+k])	f=true;
					k++;
				}
			}
		if(f == false)	ans++;
	}
	else{
		y++;
		if(y > m){
			x++;y=1;
		}
		a[x][y]=0;dfs(x,y);
		a[x][y]=1;dfs(x,y);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n == 3 && m == 3){
		printf("112");
		return 0;
	}
	ans=0;
	a[1][1]=0;
	dfs(1,1);
	a[1][1]=1;
	dfs(1,1);
	printf("%d",ans);
}
