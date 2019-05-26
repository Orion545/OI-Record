#include <iostream>
#include <fstream>
using namespace std;
long long n,d[100003],ans=0;
int main(){
	long long i,j,k;
	d[0]=0;
	ifstream fin;
	fin.open("road.in");
	fin>>n;
	for(i=1;i<=n;i++){
		fin>>d[i];
		if(d[i]>d[i-1]) ans+=d[i]-d[i-1];
	}
	fin.close();
	ofstream fout;
	fout.open("road.out");
	fout<<ans;
	fout.close();
	return 0;
}
