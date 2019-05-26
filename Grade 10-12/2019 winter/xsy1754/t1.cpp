#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#include<cmath>
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
ll qpow(ll a,ll b,ll mod){
	ll re=1;
	while(b){
		if(b&1) re=re*a%mod;
		a=a*a%mod;b>>=1;
	}
	return re;
}
unordered_map<ll,ll>mp;
ll bsgs(ll a,ll b,ll p){
	if(b==1) return 0;
	ll i,j,m=ceil(sqrt(double(p))),tmp=b,base=qpow(a,m,p);
	mp.clear();
//	cout<<"bsgs "<<a<<' '<<b<<' '<<p<<' '<<m<<' '<<base<<'\n';
	for(j=0;j<m;j++){
		mp[tmp]=j;
		tmp=(tmp*a)%p;
	}
	tmp=1;
	for(i=m;i<=p;i+=m){
		tmp=(tmp*base)%p;
		if(mp.count(tmp)) return i-mp[tmp];
	}
	return -1;
}
int main(){
	ll a,b,p,x;
	while(~scanf("%lld%lld%lld",&p,&a,&b)){
		a%=p;b%=p;
		x=bsgs(a,b,p);
		if(x==-1) puts("no solution");
		else printf("%lld\n",x);
	}
}
