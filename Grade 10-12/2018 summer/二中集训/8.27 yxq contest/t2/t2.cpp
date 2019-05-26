#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 1000000007 
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
ll qpow(ll a,ll b,ll mod){
	ll re=1;
	while(b){
		if(b&1) re=re*a%mod;
		a=a*a%mod;b>>=1;
	}
	return re;
}
int m,n;
int main(){
	m=read();n=read();ll i,x,y,cnt;ll ans=0;
	for(i=1;i<n;i++){
		cnt=0;
		for(x=1;x<n;x++){
			for(y=1;y<=m;y++){
				if(qpow(x,i,n)==qpow(x+y,i,n)) cnt++;
			}
		}
		ans+=cnt*i%MOD;
	}
	printf("%lld\n",ans);
}
