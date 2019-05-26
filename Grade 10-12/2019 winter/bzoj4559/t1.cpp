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
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=1ll*re*a%MOD;
		a=1ll*a*a%MOD;b>>=1;
	}
	return re;
}
ll n,m,K,lim[110],r[110],y[110],inv[110],dp[110][110];
ll f[110],finv[110];
void init(){
	ll i,len=100;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=1ll*f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=1ll*finv[i]*i%MOD;
}
ll C(ll x,ll y){
	if(x<y||x<0||y<0) return 0;
//	cout<<"C "<<x<<' '<<y<<'\n';
	return 1ll*f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	n=read();m=read();K=read();ll i,j,k,tmp,cur;
	init();
	for(i=1;i<=m;i++) lim[i]=read();
	for(i=1;i<=m;i++) r[i]=read();
	dp[0][0]=1;
	for(i=1;i<=m;i++){
		//lag
		cur=0;
		for(j=1;j<=n+1;j++){
			y[j]=0;
			for(k=1;k<=j;k++) add(y[j],1ll*qpow(j-k,r[i]-1)*qpow(k,n-r[i])%MOD);
//			cout<<i<<' '<<j<<' '<<y[j]<<'\n';	
			if(j==lim[i]){cur=y[j];goto jump;}
		}
		for(j=1;j<=n+1;j++){
			inv[j]=1;
			for(k=1;k<=n+1;k++){
				if(j==k) continue;
				inv[j]=(1ll*inv[j]*(j-k)+MOD)%MOD;
			}
			inv[j]=qpow(inv[j],MOD-2);
		}
		for(j=1;j<=n+1;j++){
			tmp=1ll*y[j]*inv[j]%MOD;
			for(k=1;k<=n+1;k++)
				if(k!=j) tmp=(1ll*tmp*(lim[i]-k)%MOD+MOD)%MOD;
			add(cur,tmp);
		}
//		cout<<i<<' '<<cur<<'\n';
		//finish lag
		jump:
		for(j=0;j<=n;j++){
			for(k=0;k<=j;k++) add(dp[i][j],1ll*dp[i-1][k]*C(n-1-k,j-k)%MOD*C(k,r[i]-1-j+k)%MOD);
			dp[i][j]=1ll*dp[i][j]*cur%MOD;
//			cout<<"dp "<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	cout<<dp[m][n-1-K]<<'\n';
}
