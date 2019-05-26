#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define MOD 998244353
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int f[20000010],finv[20000010];
void init(){
	int i,len=20000000;f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=1ll*f[i-1]*i%MOD;
	finv[len]=qpow(f[len],MOD-2);
//	cout<<len<<' '<<f[len]<<' '<<finv[len]<<'\n';
	for(i=len;i>2;i--) finv[i-1]=1ll*finv[i]*i%MOD;
}
int C(int x,int y){
	return (x<y)?0:1ll*f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
	init();
	int n=read(),m=read(),i;n--;ll ans=C(n<<1,n);
	for(i=0;i<n;i+=m){
		ans-=C(n<<1,n+i+1);
		ans-=C(n<<1,n+i+m-1);
		ans+=C(n<<1,n+i+m)<<1;
	}
	cout<<(ans%MOD+MOD)%MOD<<'\n';
}
