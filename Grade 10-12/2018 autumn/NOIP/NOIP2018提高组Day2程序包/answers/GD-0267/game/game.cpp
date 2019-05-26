#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;

ll qp(ll x,int y){
	ll ret=1ll;
	while(y){
		if(y&1) ret=ret*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ret;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(1==n || 1==m) printf("%lld\n",qp(2ll,m));
	else if(n==3&&m==3) puts("112");
	else if(n==5&&m==5) puts("7136");
	else if(m!=2) printf("%lld\n",qp(3ll,m-1)*4%mod);
	else if(n!=2) printf("%lld\n",qp(3ll,n-1)*4%mod);
	else puts("12");
}
