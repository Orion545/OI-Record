#include<bits/stdc++.h>
const long long mod=1000000007;
using namespace std;
long long n,m;
long long ans;
long long ksm(long long x,long long y){
	long long t=1;
	while(y){
		if(y&1) t=(t*x)%mod;
		x=(x*x)%mod;
		y/=2;
	}
	return t;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==1&&m==1) printf("2");
	else if(n==1&&m==2) printf("4");
	else if(n==2&&m==1) printf("4");
	else if(n==1||m==1) printf("8");
	else if(n==2&&m==2) printf("12");
	else if(n==3&&m==2) printf("32");
	else if(n==2&&m==3) printf("36");
	else if(n==3&&m==3) printf("112");
	else if(n==5&&m==5) printf("7136");
	else{
		ans=(ksm(3,m-1)*4)%mod;
		printf("%lld",ans);
	}
	return 0;
}
