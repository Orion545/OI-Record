#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	int n=100000,K=1000000000;
	cout<<n<<' '<<K<<'\n';
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",random(1,i-1),i,rand());
	}
}
