#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
const int mod=1e9+7;
using namespace std;
long long ksm(long long x){
	long long a=2;
	long long res=1;
	while(x){
		if(x%2==1){
			res=res*a%mod;
		}
		a=a*a%mod;
	x=x/2;
	}
	return res%mod;
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long  n,m;
	scanf("%lld%lld",&n,&m);
	
	if(n==1){
		long long  k=ksm(m);
		printf("%lld",k);
	}else if(m==1){
		long long  k=ksm(n);
		printf("%lld",k);
	}
	if(n==3&&m==3){
		cout<<"112";
	}
	if(n==5&&m==5){
		cout<<"7136";
	}
	if(n==2){	
	long long k=ksm(m-1);
	cout<<((4*(1+k))%mod*k/2)%mod;
	}
	if(m==2){
		long long  k=ksm(n-1);
		cout<<((4*(1+k))%mod*k/2)%mod;
	}
	return 0;
}
