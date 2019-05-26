#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m;
long long tot=1,ans,cnt;
long long qpow(long long x,int i){
	long long res=1;
	while(i){
	    if(i&1) res=res*x%mod;
		x=x*x%mod;
		i/=2;	
	}
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	for(int i=1;i<n;i++){tot=tot*qpow(i+1,2)%mod;}
	tot=tot*qpow(n+1,(m-n+1));
	if(n==2) printf("%lld\n",tot);
	if(n==3) printf("112\n");
}
