#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n=3,m=3;
int a[100][100];
int num=0;
int maxx=0;
bool bk;
void dfs(int x,int y,int sum){
	if(m==y&&n==x){
		if(maxx>sum)
			bk=false;
		maxx=max(maxx,sum);
	}
	else{
		sum<<=2;
		if(x<n)
			dfs(x+1,y,sum+a[x][y]);
		if(y<=m)
			dfs(x,y+1,sum+a[x][y]);
	}
	
}
void dfs(int x,int y){
	if(m==y&&n==x){
		maxx=0;
		bk=true;
		a[n][m]=0;
		dfs(1,1,0);
		if(bk)
			num++;
		maxx=0;
		bk=true;
		a[n][m]=1;
		dfs(1,1,0);
		if(bk)
			num++;
	}
	else{
		a[x][y]=0;
		dfs(x+y/m,y%m+1);
		a[x][y]=1;
		dfs(x+y/m,y%m+1);
	}
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,1);
	printf("%d",num);
	return 0;
}
