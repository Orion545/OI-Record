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
ll n,k,a[2010],h[2010],mo[2010],b[20010],c[20010],t[20010];
void add(ll &x,ll y){
	x+=y;
	if(x>=MOD) x-=MOD;
}
void mul(ll *x,ll *y,ll *z){
	ll i,j;
	for(i=0;i<2*k-2;i++) t[i]=0;
	for(i=0;i<k;i++)
		for(j=0;j<k;j++)
			add(t[i+j],x[i]*y[j]%MOD);
	for(i=2*k-2;i>=k;i--){
		for(j=k-1;j>=0;j--)
			add(t[i-k+j],MOD-t[i]*mo[j]%MOD);
		t[i]=0;
	}
	for(i=0;i<k;i++) z[i]=t[i];
}
int main(){
	n=read()+1;k=read();ll i,j;
	for(i=1;i<=k;i++){
		a[i]=read();
		if(a[i]<0) a[i]+=MOD;
	}
	for(i=1;i<=k;i++){
		h[i]=read();
		if(h[i]<0) h[i]+=MOD;
	}
	mo[k]=1;
	for(i=1;i<=k;i++) mo[k-i]=MOD-a[i];
	if(n<k){cout<<h[n]<<'\n';return 0;}
	i=n-k;b[1]=1;c[0]=1;
	while(i){
		if(i&1) mul(c,b,c);
		mul(b,b,b);i>>=1;
	}
	for(i=k+1;i<=k*2;i++)
		for(j=1;j<=k;j++)
			add(h[i],h[i-j]*a[j]%MOD);
	ll ans=0;
	for(i=0;i<k;i++) add(ans,c[i]*h[i+k]%MOD);
	cout<<ans<<'\n';
}
