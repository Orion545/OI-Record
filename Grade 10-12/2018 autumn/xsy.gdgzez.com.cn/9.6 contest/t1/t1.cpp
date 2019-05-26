#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
ll n,m,k;
ll f[50],g[50],fac[50];
ll qpow(ll a,ll b){
	ll re=1;
//	cout<<"qpow "<<a<<' '<<b<<'\n';
	while(b){
		if(b&1) re=re*a;
		a=a*a;b>>=1;
	}
//	cout<<"get "<<re<<'\n
	return re;
}
ll rk[50],vis[50];
int main(){
	n=read();m=read();k=read();
	ll i,j;
	fac[0]=1;
	for(i=1;i<=n;i++) fac[i]=fac[i-1]*(ll)i;
	for(i=0;i<=n;i++) f[i]=((i<m)?fac[i]:(fac[m]*qpow(m+1,i-m)));
	for(i=0;i<=n;i++) g[i]=f[i]-((i<(m-1))?fac[i]:(fac[m-1]*qpow(m,i-m+1)));
//	for(i=0;i<=n;i++) cout<<i<<' '<<f[i]<<' '<<g[i]<<'\n';
	ll cur,flag=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i+1;j++){
			if(flag||j==m+1) cur=f[n-i];
			else cur=g[n-i];
			if(cur>=k){
				rk[i]=j;
				if(j==m+1) flag=1;
				break;
			}
			else k-=cur;
		}
//		cout<<i<<' '<<rk[i]<<'\n';
	}
	for(i=1;i<=n;i++){
		cur=0;
		for(j=1;j<=n;j++){
			cur+=(!vis[j]);
			if(cur==rk[i]){
				printf("%lld ",j);
				vis[j]=1;break;
			}
		}
	}
}
