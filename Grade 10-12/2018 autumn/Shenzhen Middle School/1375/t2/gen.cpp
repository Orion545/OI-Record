#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	int n=500,i;
	srand(time(NULL));
	cout<<n<<'\n';
	for(i=1;i<=n;i++) cout<<random(1,10)<<' ';
	cout<<'\n';
}
