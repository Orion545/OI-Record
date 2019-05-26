#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	int T=500,n=100000,m,k;
	srand(time(NULL));
	cout<<T<<'\n';
	while(T--){
		k=random(100,300);
		cout<<n<<' '<<random(100,n-k)<<' '<<k<<'\n';
	}
}
