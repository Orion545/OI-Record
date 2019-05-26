#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
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
ll pow_mod(ll a, ll b, ll p){//a的b次方求余p 
    ll ret = 1;
    while(b){
        if(b & 1ll) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1ll;
    }
    return ret;
}
ll Fermat(ll a, ll p){//费马求a关于b的逆元 
        return pow_mod(a, p-2, p);
}
ll n,a,b,K,x[100010],MOD=1e9+9;char s[100010];
int main(){
	n=read();a=read();b=read();K=read();ll i,ans=0,tmp1,tmp2;
	scanf("%s",s);
	for(i=0;i<K;i++) x[i]=((s[i]=='+')?1:-1);
	if(a==b){
		tmp1=(n+1)/K;ans=0;
		for(i=0;i<K;i++){
			ans=ans+x[i]*tmp1;ans=ans+MOD;ans%=MOD;
//			cout<<i<<ends<<ans<<endl;
		}
//		cout<<tmp1<<ends<<pow_mod(a,n,MOD);
		cout<<(ans*pow_mod(a,n,MOD)%MOD+MOD)%MOD;return 0;
	} 
	if(a<b){
		swap(a,b);
	}
	else{
		for(i=0;i<=(K-1)/2;i++) swap(x[i],x[K-i-1]);
	}
	ans=0;
	for(i=0;i<K;i++){
		tmp1=pow_mod(b,K-i-1,MOD)*pow_mod(a,n+i+1,MOD)%MOD;
		tmp1=tmp1-pow_mod(a,i,MOD)*pow_mod(b,n+K-i,MOD)%MOD+MOD;tmp1%=MOD;
		tmp2=pow_mod(a,K,MOD)-pow_mod(b,K,MOD)+MOD;tmp2%=MOD;
//		cout<<tmp1<<ends<<tmp2<<ends<<Fermat(tmp2,MOD)<<ends<<(tmp1*Fermat(tmp2,MOD))%MOD<<endl;
		ans=ans+x[i]*(tmp1*Fermat(tmp2,MOD))%MOD+MOD;ans%=MOD;
	}
	cout<<ans;
}
