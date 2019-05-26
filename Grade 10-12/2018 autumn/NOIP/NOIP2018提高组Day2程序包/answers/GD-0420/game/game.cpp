#include <iostream>
#include <cstdio>
using namespace std;

const long long p=1e9+7;
long long n,m,ans=1,h; 

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	cin>>n>>m;
	if(n>m){ h=n; n=m; m=h; }
	
	for(long long i=1;i<=n;i++) ans=ans*i%p;
	
	ans=ans*ans%p;
	
	for(long long i=1;i<=m-n+1;i++) ans=ans*(n+1)%p;
	
	cout<<ans;
	
	return 0;
}
