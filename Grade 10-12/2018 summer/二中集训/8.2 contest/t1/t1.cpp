#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 100003
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,k,a[100010],mk[100010];
ll inv[100010],f[100010],fac;
int main(){
	n=read();k=read();ll i,j,tmp,cnt=0;fac=1;
	for(i=1;i<=n;i++) a[i]=read(),fac=fac*i%MOD;
	for(i=n;i>=1;i--){
		tmp=a[i];
		for(j=i*2;j<=n;j+=i) if(mk[j]) tmp^=1;
		if(tmp) mk[i]=1,cnt++;
	}
//	cout<<"*** "<<cnt<<' '<<k<<'\n';
	if(cnt<=k){printf("%lld\n",fac*cnt%MOD);return 0;}
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	f[n+1]=0;
	ll ans=0;
	for(i=n;i>k;i--) f[i]=(f[i+1]*(n-i)%MOD+n)%MOD*inv[i]%MOD;
	for(i=1;i<=k;i++) f[i]=1;
	for(i=1;i<=cnt;i++) ans=(ans+f[i])%MOD;
	printf("%lld\n",ans*fac%MOD);
}

