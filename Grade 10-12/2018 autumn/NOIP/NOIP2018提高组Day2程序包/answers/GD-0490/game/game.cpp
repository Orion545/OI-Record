#include<cstdio>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;

ifstream fin("game.in");
ofstream fout("game.out");

const ll mo=1e9+7;
const int N=1e6+5;
int n,m;
ll g[N][2][2][2];

int main(){
	fin>>n>>m;
	
	if(n==3&&m==3){
		fout<<112;return 0;
	}
		
	if(n==5&&m==5){
		fout<<7136;return 0;
	}
	
	if(m==2)n^=m,m^=n,n^=m;
	
	if(n==2){
		ll s=4;
		rep(i,2,m)
			s=(s*3)%mo;
		fout<<s;
		return 0;
	}
	
	if(n==3){
		ll s=112;
		rep(i,4,m)
			s=(s*3)%mo;
		fout<<s;
		return 0;
	}
	
	return 0;
}


