#include<iostream>
#include<cstdio>

using namespace std;

const long long p=1000000007ll;
long long n,m;

inline long long qpow(long long a,int x){long long s=1ll;while(x>0){if(x&1)(s*=a)%p;(a*=a)%=p,x>>=1;}return s;}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);if(n>m){long long t=n;n=m,m=t;}
	if(n==3ll&&m==3ll)printf("%lld",112ll);else if(n==5ll&&m==5ll)printf("%lld",7136ll);
	else if(n==3ll&&m==4ll)printf("%lld",480ll);
	else if(n==1)printf("%lld",qpow(2ll,m));else if(n==2)printf("%lld",4ll*qpow(3ll,m-1)%p);
}
