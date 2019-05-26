#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define MOD 1000000007
using namespace std;
ll n,m,k,f[1010][1010],suf[510],suff[510],pre[510],C[510],CC[510],pw[510];
ll qpow(ll a,ll b){
	ll re=1;
	if(b<0) return 0;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(ll p,ll q){
//	cout<<"init "<<p<<' '<<q<<'\n';
	memset(C,0,sizeof(C));memset(CC,0,sizeof(CC));
	int i;C[0]=1;CC[0]=1;
	suf[1]=p;suff[1]=q;

	for(i=2;i<=min(p,k);i++) suf[i]=suf[i-1]*(p-i+1ll)%MOD;
	for(i=2;i<=min(q,k);i++) suff[i]=suff[i-1]*(q-i+1ll)%MOD;

	for(i=1;i<=min(p,k);i++) C[i]=suf[i]*pre[i]%MOD;
	for(i=1;i<=min(q,k);i++) CC[i]=suff[i]*pre[i]%MOD;
}
void getf(){
	int i,j,len=310;
	f[0][0]=1;
	for(i=1;i<=len;i++){
		for(j=1;j<=i*2;j++){
			f[i][j]=(f[i-1][j-1]*2+f[i-1][j-2])%MOD;
		}
	}
}
int main(){
	getf();int T;scanf("%d",&T);
	pre[1]=1;
	for(int i=2;i<=500;i++) pre[i]=(pre[i-1]*qpow(i,MOD-2))%MOD;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		init(n-m,m);
		ll ans=0,tmp;int i,j;
		for(i=0;i<=k;i++) pw[i]=qpow(2,m-i);
//		cout<<"here\n";
		for(i=0;i<=k;i++){
			tmp=0;
			for(j=(k-i+1)/2;j<=k-i;j++){
//				cout<<i<<' '<<j<<'\n';
				(tmp+=CC[j]*pw[j]%MOD*f[j][k-i]%MOD)%=MOD;
			}
			(ans+=tmp*C[i]%MOD)%=MOD;
		}
		printf("%lld\n",ans);
	}
}
