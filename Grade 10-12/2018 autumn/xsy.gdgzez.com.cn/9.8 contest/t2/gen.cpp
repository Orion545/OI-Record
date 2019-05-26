#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#include<ctime>
#include<cassert>
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int vis[100010]={0};
int main(){
	srand(time(NULL));int i;
	int n=5000,m=5000,Q=5000;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++) printf("1 ");
	putchar('\n');
	for(i=1;i<=m;i++){
		int t1=random(1,n);
		int t2=random(t1,n);
		printf("%d %d\n",t1,t2);
		assert(t1<=t2);
	}
	printf("%d\n",Q);
	while(Q--){
		while(vis[i=random(1,n)]);
		printf("%d\n",i);
	}
}
