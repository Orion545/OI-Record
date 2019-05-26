#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000009
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1; 
	}
	return re;
}
ll f[2010],finv[2010];
void init(){
	int i;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=2000;i++) f[i]=f[i-1]*i%MOD;
	finv[2000]=qpow(f[2000],MOD-2);
//	cout<<"init "<<f[2000]<<' '<<finv[2000]<<'\n';
	for(i=2000;i>2;i--) finv[i-1]=finv[i]*i%MOD; 
//	cout<<"init "<<f[2]*finv[2]%MOD<<'\n'; 
}
ll C(ll x,ll y){
//	cout<<"C "<<x<<' '<<y<<' '<<f[x]<<' '<<finv[y]<<' '<<finv[x-y]<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int n,k,a[2010],b[2010],lim[2010];ll dp[2010][2010];
//dp[i][j]:前i个糖果，有至少j组是糖果比药片大的
//dp[n][k]=sum(ans[n][k]*C(k,j))(j=0...n-k) 
//ans[n][k]=
int main(){
	n=read();k=read();int i,j;init();
	if((n^k)&1){
		puts("0");return 0;
	}
	k=(n+k)>>1;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++) b[i]=read();
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	
	j=0;
	for(i=1;i<=n;i++){
		while(j<n&&b[j+1]<a[i]) j++;
		lim[i]=j;
//		cout<<i<<' '<<lim[i]<<'\n'; 
	}
	dp[0][0]=1; 
	for(i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0];
		for(j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*max(0,lim[i]-j+1);dp[i][j]%=MOD;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	ll ans=0;
	for(i=k;i<=n;i++) ans=(ans+qpow(MOD-1,i-k)*C(i,k)%MOD*dp[n][i]%MOD*f[n-i]%MOD)%MOD;
	printf("%lld\n",ans); 
}

