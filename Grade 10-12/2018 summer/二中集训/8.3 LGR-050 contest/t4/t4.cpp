#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 998244353
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m;
ll f[100010],finv[100010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void init(){
	int i;
	f[1]=f[0]=finv[1]=finv[0]=1;
	for(i=2;i<=100000;i++) f[i]=f[i-1]*i%MOD;
	finv[100000]=qpow(f[100000],MOD-2);
	for(i=100000;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(int x,int y){
//	cout<<"	C "<<x<<' '<<y<<' '<<f[x]*finv[y]%MOD*finv[x-y]%MOD<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
namespace DP{
	ll dp[2010][2010];
	void solve(){
		init();int i,j;
		dp[0][0]=1;
		for(i=1;i<=n;i++){
			for(j=0;j<=i;j++){
				if((i<<1)>(j<<1)+(m-j)) continue;
				dp[i][j]=0;
				//put 2 elements into 2 different 0-columns
				dp[i][j]+=dp[i-1][j]*C(m-j-(((i-1)<<1)-(j<<1)),2)%MOD;
				//put 2 elements into 2 different 1-columns
				if(j>1) dp[i][j]+=dp[i-1][j-2]*C(((i-1)<<1)-((j-2)<<1),2)%MOD;
				//put 1 element into 0-column, 1 element into 1-column
				if(j>0) dp[i][j]+=dp[i-1][j-1]*C(m-j+1-(((i-1)<<1)-((j-1)<<1)),1)%MOD*C(((i-1)<<1)-((j-1)<<1),1)%MOD;
				//finish renew dp[i][j]
				dp[i][j]%=MOD;
//				cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			}
		}
		ll ans=0;
		for(i=0;i<=m;i++) ans=(ans+dp[n][i])%MOD;
		printf("%lld\n",ans);
	}
}
namespace OEIS{
	ll dp[100010],inv[100010];
	void solve(){
		ll i;
		inv[1]=1;
		for(i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		dp[3]=6;dp[4]=90;
		for(i=5;i<=n;i++) dp[i]=((2*i*(i-1)%MOD*dp[i-1]%MOD)+(i*(i-1)%MOD*(i-1)%MOD*dp[i-2]%MOD))*inv[2]%MOD;
		printf("%lld\n",dp[n]);
	}
}
int main(){
	n=read();m=read();
	if(n==m) OEIS::solve();
	else if(n<=2000&&m<=2000) DP::solve();
}

