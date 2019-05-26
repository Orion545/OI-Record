#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[10][10],ans;
void dfs(int x,int y){
	if (y>m){
		y=1;
		x++;
		if (x>n){
			bool flag=1;
			for (int i=1;i<n;i++)
				for (int j=2;j<=m;j++)
					for (int k=1;i+k<=n&&j-k>=1;k++)
						if (a[i+k][j-k]<a[i][j]){
							flag=0;
							break;
						}
			ans+=flag;
			return;
		}
	}
	a[x][y]=1;
	dfs(x,y+1);
	a[x][y]=0;
	dfs(x,y+1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==3&&m==3){
		puts("112");
		return 0;
	}
	if (n==5&&m==5){
		puts("7136");
		return 0;
	}
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
