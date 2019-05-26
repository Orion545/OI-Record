#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MOD 1000000007
#define ll long long
ll n,m,f[3010],finv[3010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=(re*a)%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	int i;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=3000;i++) f[i]=f[i-1]*i%MOD;
	finv[3000]=qpow(f[3000],MOD-2);
	for(i=3000;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll h[3010],g[3010],ff[3010],pm[6000010];
void dec(ll &a,ll b){
//	cout<<"dec "<<a<<' '<<b<<'\n';
	a-=b;
	if(a<0) a+=MOD;
}
void add(ll &a,ll b){
//	cout<<"add "<<a<<' '<<b<<'\n';
	a+=b;
	if(a>=MOD) a-=MOD;
}
ll C(ll x,ll y){
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	scanf("%lld%lld",&n,&m);
	if(m<=1){puts("0");return 0;}
	if(n==1){puts("1");return 0;}
	int i,j;
	init();
	for(i=1;i<=n;i++) h[i]=qpow(m,i*(i-1));
	pm[0]=1;
	for(i=1;i<=(n*n)/2;i++) pm[i]=pm[i-1]*m%MOD;
	for(i=1;i<=n;i++){
		g[i]=h[i];
		for(j=1;j<i;j++) dec(g[i],h[i-j]*g[j]%MOD*C(i,j)%MOD*pm[j*(i-j)]%MOD);
//		cout<<i<<' '<<g[i]<<'\n';
	}
	for(i=1;i<=n;i++){
		ff[i]=g[i];
		for(j=1;j<i;j++) add(ff[i],C(i-1,j-1)*ff[j]%MOD*g[i-j]%MOD);
//		cout<<i<<' '<<ff[i]<<'\n';
	}
	dec(h[n],ff[n]);
	printf("%lld\n",h[n]*qpow(m,n)%MOD);
}
