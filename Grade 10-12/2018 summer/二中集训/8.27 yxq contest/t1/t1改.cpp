#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 999999999999999989
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
ll mul(ll a,ll b){
	ll re=0;
	while(b){
		if(b&1ll) re=(re+a)%MOD;
		a=(a+a)%MOD;b>>=1ll;
	}
	return re;
}
namespace M{
	ll a[2],b[4];
	void mul1(){
		ll re[2];
		re[0]=(mul(a[0],b[0])+mul(a[1],b[2]))%MOD;
		re[1]=(mul(a[0],b[1])+mul(a[1],b[3]))%MOD;
		a[0]=re[0];a[1]=re[1];
	}
	void mul2(){
		ll re[4];
		re[0]=(mul(b[0],b[0])+mul(b[1],b[2]))%MOD;
		re[1]=(mul(b[0],b[1])+mul(b[1],b[3]))%MOD;
		re[2]=(mul(b[2],b[0])+mul(b[3],b[2]))%MOD;
		re[3]=(mul(b[2],b[1])+mul(b[3],b[3]))%MOD;
		b[0]=re[0];b[1]=re[1];b[2]=re[2];b[3]=re[3];
	}
}
ll qpow(ll b,ll d,ll n){
//	using namespace M;
//	cout<<"qpow "<<b<<' '<<d<<' '<<n<<'\n'; 
	M::a[0]=b;M::a[1]=2;
	M::b[0]=b;M::b[2]=(d-b*b)/4ll;M::b[1]=1;
	n--;
	while(n){
//		cout<<"	do "<<n<<'\n'; 
		if(n&1ll) M::mul1();
		M::mul2();n>>=1ll;
//		cout<<"	finish "<<n<<'\n'; 
	}
	return M::a[0];
}
int main(){
	ll b=read(),d=read(),n=read();
	if(n==0){
		puts("1");return 0;
	}
	ll re=qpow(b,d,n);
	if(b*b!=d&&n%2==0) re=(re-1+MOD)%MOD;
	printf("%lld\n",re);
}
