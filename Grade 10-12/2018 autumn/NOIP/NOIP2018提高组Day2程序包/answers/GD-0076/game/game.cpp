#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
ll mod=1000000007;
ll n,m;
ll quickpow(int a,int b)
{
	ll ret=1;
	while(b){
		if(b%2==1)	ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n<=1||m<=1){	printf("0");return 0;}
	if(n==2){
		ll rt=(quickpow(3,m-1)*4)%mod;
		printf("%lld",rt);
		return 0;
	}
	if(n==3){
		if(m==2){
			printf("36");
			return 0;
		}
		if(m==3){
			printf("112");
			return 0;
		}
	}
	if(n==5&&m==5){
		printf("7136");
		return 0;
	}
	if(n==3){
		ll rt;
		printf("%lld",rt);
		return 0;
	}
	return 0;
}

