#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[9]={0,2,3,4,5,6,7,8,9};
int n,m,ans=1;
int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1) ret=1ll*ret*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ret;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	for(int i=1;i<n;i++) ans=1ll*ans*a[i]%mod*a[i]%mod;
	ans=1ll*ans*qpow(a[n],m-n+1)%mod;
	printf("%d",ans);
}
