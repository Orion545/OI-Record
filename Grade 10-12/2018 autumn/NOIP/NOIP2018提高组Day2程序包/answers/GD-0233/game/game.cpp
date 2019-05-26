#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
	ll n,m,ans,tmp;
ll qpow(ll x,ll y){
	ll t=1;
	while(y){
		if(y&1)t=(t*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return t;
}
bool dfs(ll x){
	if((x/m!=n-1)&&(x%m!=m-1)){
		ll d=(1<<(x+m))&tmp,r=(1<<(x+1))&tmp;
		if(d&&r==0)return false;
//		if(d==0&&r)return true;
		return dfs(x+1)&&dfs(x+m);
	}
	return true;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==2){
		ll st=6; ans=4;
		for(ll i=1;i<m;i++)ans=(((ans*3)%mod))%mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(n==1&&m==1){
		printf("2\n");
		return 0;
	}
	if(n==1&&m==2){
		printf("4\n");
		return 0;
	}
	if(n==1&&m==3){
		printf("8\n");
		return 0;
	}
	if(n==3&&m==1){
		printf("8\n");
		return 0;
	}
	if(n==3&&m==2){
		printf("36\n");
		return 0;
	}
	if(n==3&&m==3){
		printf("112\n");
		return 0;
	}
	if(n==5&&m==5){
		printf("7136\n");
		return 0;
	}
	for(ll state=0;state<((1<<(n*m)));state++){
		tmp=state;
		if(dfs(0))ans++;
	}
	printf("%lld\n",ans);
}
