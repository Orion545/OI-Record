#include<iostream>
#include<fstream>
using namespace std;

const int maxn=100500;
ifstream fin("road.in");
ofstream fout("road.out");
int a[maxn];

int main(){
	int n;
	long long ans;
	int i,j;
	fin>>n;
	
	for(i=1;i<=n;i++) fin>>a[i];
	ans=a[1];
	for(i=2;i<=n;i++){
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	fout<<ans;
	fin.close();
	fout.close();
	return 0;
}
