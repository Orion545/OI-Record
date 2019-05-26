#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll qpow(ll a,ll b){
	a%=MOD;
	ll re=1;
	while(b){
		if(b&1ll) re=re*a%MOD;
		a=a*a%MOD;b>>=1ll;
	}
	return re;
}
ll a00,a01,a10,a11;
int main(){
	ll n=read(),m=read();
	if(m<n) swap(n,m);
	if(n==1){printf("%lld\n",qpow(2,m));return 0;}
	if(n==2){printf("%lld\n",4ll*qpow(3,m-1)%MOD);return 0;}
	if(n==3){printf("%lld\n",112ll*qpow(3,m-3)%MOD);return 0;}
	ll t1=(912ll*qpow(8,n-4)%MOD-5ll*qpow(2,n)%MOD*qpow(3,MOD-2)%MOD*(qpow(4,n-4)%MOD-1)%MOD+MOD)%MOD;
	if(n==m){printf("%lld\n",t1);return 0;}
	ll t2=(t1*3ll-3*qpow(2,n)%MOD+MOD)%MOD;
	if(n==m-1){printf("%lld\n",t2);return 0;}
	ll t3=t2*qpow(3,m-n-1)%MOD;
	printf("%lld\n",t3);
}
