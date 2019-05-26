#include<iostream>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll n,MOD,g[2010],cnte[2010],sqrsum[2010],link[2010],cntelink[2010],sqrlink[2010];
ll qpow(ll a,ll b){
	ll re=1;
	if(b<0) return 0;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll c[2010][2010];
void init(){
	int i,j;
	c[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=i;j++){
			c[i][j]=c[i-1][j];
			if(j>0) c[i][j]+=c[i-1][j-1];
			c[i][j]%=MOD;
		}
	}
}
void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
void dec(ll &a,ll b){
	a-=b;
	if(a<0) a+=MOD;
}

int main(){
	scanf("%lld%lld",&n,&MOD);
	init();ll i,j;
	for(i=1;i<=n;i++) g[i]=qpow(2,i*(i-1)/2);
	for(i=1;i<=n;i++) cnte[i]=(i*(i-1)/2)*qpow(2,(i*(i-1)/2)-1)%MOD;
//	for(i=1;i<=n;i++){
//		for(j=0;j<i;j++){
//			cout<<j<<' '<<(j*j%MOD*g[i-1]%MOD+2ll*j%MOD*cnte[i-1]%MOD+sqrsum[i-1]%MOD)%MOD<<' '<<c[i-1][j]%MOD<<'\n';
//			add(sqrsum[i],((j*j%MOD*g[i-1]%MOD+2ll*j%MOD*cnte[i-1]%MOD+sqrsum[i-1]%MOD)%MOD)*c[i-1][j]%MOD);
//		}
//	}
	sqrsum[1]=0;sqrsum[2]=1;
	for(i=3;i<=n;i++) sqrsum[i]=(i*(i-1)/2)*(i*(i-1)/2+1)%MOD*qpow(2,(i*(i-1)/2)-2)%MOD;
	for(i=1;i<=n;i++){
		link[i]=g[i];
		for(j=1;j<i;j++)
			dec(link[i],link[j]*g[i-j]%MOD*c[i-1][j-1]%MOD);
//		cout<<"link "<<i<<' '<<link[i]<<'\n';
	}
	for(i=1;i<=n;i++){
		cntelink[i]=cnte[i];
		for(j=1;j<i;j++)
			dec(cntelink[i],(cntelink[j]*g[i-j]+link[j]*cnte[i-j])%MOD*c[i-1][j-1]%MOD);
//		cout<<"cntelink "<<i<<' '<<cntelink[i]<<'\n';
	}
	for(i=1;i<=n;i++){
		sqrlink[i]=sqrsum[i];
		for(j=1;j<n;j++)
			dec(sqrlink[i],(sqrlink[j]*g[i-j]%MOD+2ll*cntelink[j]*cnte[i-j]%MOD+sqrsum[i-j]*link[j]%MOD)*c[i-1][j-1]%MOD);
	}
	printf("%lld\n",sqrlink[n]);
}
