#include<iostream>
#include<ctime>
#include<cstdio>
#include<algorithm>
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int n,m;
int main(){
	srand(time(NULL));
	n=5000;m=5000;
	printf("%d %d\n",n,m);
	for(int i=0;i<=n;i++) printf("%d\n",random(0,10000)*random(0,10000));
	for(int i=0;i<=m;i++) printf("%d\n",random(0,10000)*random(0,10000));
}
