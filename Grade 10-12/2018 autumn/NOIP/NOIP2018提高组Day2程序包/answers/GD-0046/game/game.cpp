#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,ma[100][100],s;
void dfs(int x,int y){
	if(x==n&&y==m){
		s++;
		return ;
	}
	for(int i=0;i<=1;i++){
		ma[x][y]=i;
		if(y==m){
			dfs(x+1,1);
		}else{
			dfs(x,y+1);
		}
	}
	return ;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	dfs(1,1);
	cout<<s;
	return 0;
}
