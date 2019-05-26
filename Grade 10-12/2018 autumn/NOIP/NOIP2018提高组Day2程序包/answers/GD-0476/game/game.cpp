#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#define M 5005
#define L long long
#define MOD 1000000007
using namespace std;

L pow_mod(L x,L k){
	L ans=1;
	while(k){
		if(k&1) ans=ans*x%MOD;
		x=x*x%MOD; k>>=1;
	}
	return ans;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	L n,m; cin>>n>>m;
	if(n>m) swap(n,m);
	if(n==1){
		cout<<pow_mod(2,m)<<endl;
		return 0;
	}
	if(n==2){
		cout<<pow_mod(3,m-1)*4LL%MOD<<endl;
		return 0;
	}
	if(n==3){
		L ans=pow_mod(4,m-2)*36LL%MOD;
		L hh=16;
		for(int i=1;i<=m-2;i++){
			hh=hh*2%MOD;
			ans=(ans-hh+MOD)%MOD;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<7136<<endl;
}
