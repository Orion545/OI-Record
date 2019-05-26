#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000007
#define inv2 500000004
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
ll n,m,t,a[1100010],b[1100010];
int _plus(int a,int b){
	a+=b;
	return (a>=MOD)?a-MOD:a;
}
int _minus(int a,int b){
	a-=b;
	return (a<0)?a+MOD:a;
}
void fwt(ll *a,ll type){
	ll j,k,mid,len,x,y;
	for(mid=1;mid<n;mid<<=1)
		for(len=mid<<1,j=0;j<n;j+=len)
			for(k=0;k<mid;k++){
				x=a[j+k];y=a[j+k+mid];
				a[j+k]=_plus(x,y);a[j+k+mid]=_minus(x,y);
				if(type==-1) a[j+k]=a[j+k]*inv2%MOD,a[j+k+mid]=a[j+k+mid]*inv2%MOD;
			}
}
int main(){
	m=read();t=read();ll i;n=(1<<m);
	for(i=0;i<n;i++) a[i]=read();
	b[0]=1;
	for(i=0;i<=m;i++) b[1<<i]=1;
	fwt(a,1);fwt(b,1);
	while(t){
		if(t&1) for(i=0;i<n;i++) a[i]=a[i]*b[i]%MOD;
		t>>=1;for(i=0;i<n;i++) b[i]=b[i]*b[i]%MOD;
	}
	fwt(a,-1);
	for(i=0;i<n;i++) printf("%lld ",a[i]);
}


