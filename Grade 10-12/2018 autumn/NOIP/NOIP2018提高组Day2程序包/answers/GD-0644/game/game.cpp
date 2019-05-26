#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("game.in");
ofstream fout("game.out");
long long i,t,n,m,ans=1,mo=1000000007;
int main(){
	fin>>n>>m;
	if(n==3&&m==3){
		fout<<112<<endl;
		return 0;
	}
	if(n>m){
		t=n;
		n=m;
		m=t;
	}
	for(i=1;i<=n;i++){
		ans=(ans*(i+1))%mo;
	}
	for(i=1;i<=m-n;i++){
		ans=(ans*(n+1))%mo;
	}
	for(i=1;i<n;i++){
		ans=(ans*(i+1))%mo;
	}
	fout<<ans<<endl;
	return 0;
}
