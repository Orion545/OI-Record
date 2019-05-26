#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	int n=200,m=200,i,j;
	printf("%d %d\n",n,m);
	for(i=1;i<n;i++) printf("%d\n",random(1,1e3));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ",random(1,1e3));
		}
		puts("");
	}
}
