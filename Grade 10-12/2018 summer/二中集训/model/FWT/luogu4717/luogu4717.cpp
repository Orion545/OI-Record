#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
const ll MOD=998244353;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll n,inv2;
ll a1[200010],b1[200010],a2[200010],b2[200010],a3[200010],b3[200010];
void fwtor(ll *a,ll type){
	ll mid,j,k,len;
	for(mid=1;mid<n;mid<<=1)
		for(len=mid<<1,j=0;j<n;j+=len)
			for(k=0;k<mid;k++)
				if(~type) a[mid+j+k]=(a[j+k]+a[mid+j+k])%MOD;
				else a[mid+j+k]=((a[mid+j+k]-a[j+k])%MOD+MOD)%MOD;
}
void fwtand(ll *a,ll type){
	ll mid,j,k,len;
	for(mid=1;mid<n;mid<<=1)
		for(len=mid<<1,j=0;j<n;j+=len)
			for(k=0;k<mid;k++)
				if(~type) a[j+k]=(a[j+k]+a[mid+j+k])%MOD;
				else a[j+k]=((a[j+k]-a[mid+j+k])%MOD+MOD)%MOD;
}
void fwtxor(ll *a,ll type){
	ll mid,j,k,len,x,y;
	for(mid=1;mid<n;mid<<=1)
		for(len=mid<<1,j=0;j<n;j+=len)
			for(k=0;k<mid;k++){
				x=a[j+k];y=a[j+k+mid];
				a[j+k]=(x+y)%MOD;a[j+k+mid]=((x-y)%MOD+MOD)%MOD;
				if(type==-1) a[j+k]=inv2*a[j+k]%MOD,a[j+k+mid]=inv2*a[j+k+mid]%MOD;
			}
}
int main(){
	n=read();n=(1<<n);int i;inv2=qpow(2,MOD-2);
	for(i=0;i<n;i++) a1[i]=a2[i]=a3[i]=read();
	for(i=0;i<n;i++) b1[i]=b2[i]=b3[i]=read();
	
	fwtor(a1,1);fwtor(b1,1);
	for(i=0;i<n;i++) a1[i]=a1[i]*b1[i]%MOD;
	fwtor(a1,-1);
	
	fwtand(a2,1);fwtand(b2,1);
	for(i=0;i<n;i++) a2[i]=a2[i]*b2[i]%MOD;
	fwtand(a2,-1);
	
	fwtxor(a3,1);fwtxor(b3,1);
	for(i=0;i<n;i++) a3[i]=a3[i]*b3[i]%MOD;
	fwtxor(a3,-1);
	
	for(i=0;i<n;i++) printf("%lld ",a1[i]);puts("");
	for(i=0;i<n;i++) printf("%lld ",a2[i]);puts("");
	for(i=0;i<n;i++) printf("%lld ",a3[i]);
}
