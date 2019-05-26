#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
ll random(ll l,ll r){
	ll x=rand(),y=rand();
	return x*y%(r-l+1ll)+l;
}
int main(){
	ll n=200000,m=20000;
	printf("%lld %lld\n",n,m);
	int i;
	for(i=1;i<=n;i++) printf("%lld\n",random(1,1e9));
	for(i=1;i<=m;i++){
		ll tmp;
		printf("%lld %lld %lld ",(tmp=random(0,1)),random(1,n),random(1,n));
		if(tmp) printf("%lld\n",random(1,n*m));
		else printf("%lld\n",random(1,1e6));
	}
}
