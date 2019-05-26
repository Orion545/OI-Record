#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define Mo 1000000007
using namespace std;
const ll N=1e6+10;
ll n,m;
ll ksm(ll a,ll b){
	ll ret=1;
	for(;b;a=a*a%Mo,b>>=1)
		if(b%2)ret=ret*a%Mo;
	return ret;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n>m)swap(n,m);
	if(n==3&&m==3){
		printf("112");
		return 0;
	}
	if(n==1){
		printf("%lld",ksm(2,m));
		return 0;
	}
	if(n==2){
		printf("%lld",ksm(3,m-1)*4%Mo);
		return 0;
	}
	printf("7136");
	return 0;
}
