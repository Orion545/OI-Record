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
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll n,m,o;ll fac[2010],finv[2010];
void init(){
	ll i,len=2000;
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) fac[i]=fac[i-1]*i%MOD;
	finv[len]=qpow(fac[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll t1[2010],t2[2010],g[2010],f[2010],num[2010],cnt;
inline void add(ll &a,ll b){
	assert(b>=0);
	a+=b;
	if(a>=MOD) a-=MOD;
}
inline ll calc(ll k,ll lim){
	if(lim<=k) return g[lim];
//	cout<<"begin calc "<<k<<' '<<lim<<'\n';
	ll i,tcnt;ll ans=0;
	tcnt=0;
	for(i=lim;i>=lim-k;i--){
		if(tcnt==0) t1[tcnt]=1;
		else t1[tcnt]=t1[tcnt-1]*((i+1)%MOD)%MOD;
		tcnt++;
	}
	tcnt=k;
	for(i=lim-k;i<=lim;i++){
		if(tcnt==k) t2[tcnt]=1;
		else t2[tcnt]=t2[tcnt+1]*((i-1)%MOD)%MOD;
		tcnt--;
	}
	for(i=0;i<=k;i++){
		tcnt=(((k-i)&1)?MOD-finv[k-i]:finv[k-i]);
//		cout<<"	calc "<<i<<' '<<g[i]<<' '<<t1[i]<<' '<<t2[i]<<' '<<finv[i]<<' '<<tcnt<<'\n';
//		assert(g[i]>=0);
//		assert(t1[i]>=0);
//		assert(t2[i]>=0);
//		assert(finv[i]>=0);
//		assert(tcnt>=0);
		add(ans,g[i]*t1[i]%MOD*t2[i]%MOD*finv[i]%MOD*tcnt%MOD);
	}
	assert(ans>=0&&ans<=MOD);
	return ans;
}
int main(){
	n=read();m=read();o=read();
	ll i,j;
	init();
	num[++cnt]=1;
	for(i=1;i<=n;i=i*m){
		for(j=1;j<=o;j++)
			num[++cnt]=i;
	}
	f[0]=1;f[1]=1;
	for(i=2;i<=cnt;i++){
		swap(f,g);
		memset(f,0,sizeof(f));
		if(num[i]==num[i-1]){
			for(j=0;j<=i;j++){
				if(j) f[j]=f[j-1];
				add(f[j],calc(i-1,j));
//				cout<<i<<' '<<j<<' '<<f[j]<<'\n';
			}
		}
		else{
			for(j=0;j<=i;j++){
				if(j) f[j]=f[j-1];
				add(f[j],calc(i-1,j*m+(n%num[i])/num[i-1]));
//				cout<<i<<' '<<j<<' '<<f[j]<<'\n';
			}
		}
	}
	swap(f,g);
	cout<<calc(cnt,n/num[cnt])<<'\n';
}
