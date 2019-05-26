#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll n,m;ll MOD;
ll f[1010][1010],x[1010],y[1010],ans;
ll qpow(ll a,ll b){
	if(a<0) a+=MOD;
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int main(){
	m=read();n=read();MOD=read();ll i,j,cnt,inv;
	f[0][0]=1;
	for(i=1;i<=n*2+1;i++){
		f[i][0]=f[i-1][0];
		for(j=1;j<=n;j++) f[i][j]=(f[i-1][j]+1ll*i%MOD*f[i-1][j-1])%MOD;
	}
	for(i=1;i<=n*2+1;i++){
		x[i]=i;
		y[i]=f[i][n];
//		cout<<i<<' '<<y[i]<<'\n';
	}
	for(i=1;i<=n*2+1;i++){
		cnt=y[i];inv=1;
		for(j=1;j<=n*2+1;j++){
			if(i==j) continue;
			cnt=cnt*(m-x[j]+MOD)%MOD;
			inv=inv*(x[i]-x[j]+MOD)%MOD;
//			assert(cnt>=0);assert(inv>=0);
		}
		ans=(ans+cnt*qpow(inv,MOD-2)%MOD+MOD)%MOD;
	}
	for(i=1;i<=n;i++) ans=ans*i%MOD;
	cout<<ans<<'\n';
}
