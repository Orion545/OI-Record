#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline ll qpow(ll a ,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int n,m,b[110],sum[110],lim[110];
ll f[110],finv[110],dp[110][110][2510];
void init(){
	int i,len=100;
	f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
inline ll C(int x,int y){
	if(x<y||y<0||x<0) return 0;
//	cout<<"C "<<x<<' '<<y<<' '<<f[x]*finv[y]%MOD*finv[x-y]%MOD<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
	n=read();m=read();int i,j,k,t;
	init();
	for(i=1;i<=m;i++) b[i]=read();
	sort(b+1,b+m+1);
	for(i=1;i<=m;i++) sum[i]=sum[i-1]+b[i];
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			lim[i]=max(lim[i],sum[m]-sum[j]-(n-i)*(m-j));
		}
//		cout<<i<<' '<<lim[i]<<'\n';
	}
	for(i=0;i<=n&&lim[i]==0;i++) dp[0][i][0]=C(n,i);
	for(i=0;i<m;i++){
		for(j=0;j<=n;j++){
			for(k=lim[j];k<=sum[m]-(n-j)*(i+1);k++){
				if(!dp[i][j][k]) continue;
//				cout<<"dp "<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
				for(t=0;t<=n-j&&k+t*(i+1)>=lim[j+t]&&k+t*(i+1)<=sum[m];t++)
					add(dp[i+1][j+t][k+t*(i+1)],dp[i][j][k]*C(n-j,t)%MOD);
			}
		}
	}
	cout<<dp[m][n][sum[m]]<<'\n';
}
