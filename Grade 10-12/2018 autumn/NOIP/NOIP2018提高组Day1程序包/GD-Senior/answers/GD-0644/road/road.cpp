#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
long long n,t,ma,ans;
int main(){
	fin>>n;
	for(long long i=1;i<=n;i++){
		fin>>t;
		if(t>ma){
			ans+=t-ma;
			ma=t;
		}
		else ma=t;
	}
	fout<<ans<<endl;
	return 0;
}
