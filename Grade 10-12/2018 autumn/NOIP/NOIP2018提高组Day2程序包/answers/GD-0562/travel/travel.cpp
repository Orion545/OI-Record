#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long n,m,x,y,a[5500][5500],p[5500];
long dfs(long k){
	for(int i=1;i<=n;i++){
		if(p[i]==0&&a[i][k]==1){
			p[i]=1;
			printf("%ld ",i);
			dfs(i);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%ld%ld",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	printf("1 ");
	p[1]=1;
	dfs(1);
	printf("\n");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
