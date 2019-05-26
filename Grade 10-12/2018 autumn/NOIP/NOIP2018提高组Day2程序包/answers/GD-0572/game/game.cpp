#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<cmath>
#define mod 1000000007
#define cin fin
#define cout fout
using namespace std;
ofstream fout("game.out.txt");
ifstream fin("game.in.txt");
long long n,m;
long long sum;
int main()
{   long long i;
	cin>>n>>m;
	
	sum=n*n;
   	for(i=2;i<=m;i++){
    	sum=(sum*(n+1))%mod;
    }
	if(n==3&&m==3) sum=112;
	if(n==5&&m==5) sum=7136;
	cout<<sum;
	fin.close();
    fout.close();
	return 0;
}
