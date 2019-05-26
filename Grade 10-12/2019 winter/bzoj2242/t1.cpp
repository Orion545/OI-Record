#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#include<cmath>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll qpow(ll a,ll b,ll m){
	ll re=1;
	while(b){
		if(b&1) re=re*a%m;
		a=a*a%m;b>>=1;
	}
	return re;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){x=1;y=0;return a;}
	ll t1=0,t2=0;ll gcd=exgcd(b,a%b,t1,t2);
	x=t2;y=t1-(a/b)*t2;
	return gcd;
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
unordered_map<ll,ll>mp;
ll bsgs(ll y,ll z,ll p){
	if(y==0&&z!=0) return -1;
	if(z==1) return 0;
	ll i,j,m=ceil(sqrt((double)p)),tmp=z,b=qpow(y,m,p);
//	cout<<y<<' '<<z<<' '<<p<<' '<<m<<' '<<b<<'\n';
	for(j=0;j<m;j++) mp[tmp]=j,tmp=tmp*y%p;
	tmp=1;
	for(i=1;i<=m;i++){
		tmp=tmp*b%p;
//		cout<<"	find "<<tmp<<' '<<i<<' '<<m<<' '<<b<<' '<<p<<'\n';
		if(mp.count(tmp)) return i*m-mp[tmp];
	}
	return -1;
}
int main(){
	ll T=read(),useless=read(),y,z,p,x,k,gg;
	while(T--){
		y=read();z=read();p=read();
		if(useless==1){
			y%=p;z%=(p-1);
			printf("%lld\n",qpow(y,z,p));
		}
		if(useless==2){
			//yx+pk=z
			y%=p;z%=p;
			gg=gcd(y,p);
			if(z%gg) puts("Orz, I cannot find x!");
			else{
				exgcd(y,p,x,k);
				if(x<0){
					ll tt=(-x)/(p/gg)+(((-x)%(p/gg))!=0);
					x+=tt*(p/gg);k-=tt*(y/gg);
				}
//				cout<<"final get "<<x<<' '<<y<<' '<<z<<' '<<k<<' '<<p<<'\n';
//				assert((x*(z/gg)%p)*y%p==z);
				printf("%lld\n",x*(z/gg)%p);
			}
		}
		if(useless==3){
			y%=p;z%=p;mp.clear();
			k=bsgs(y,z,p);
			if(k==-1) puts("Orz, I cannot find x!");
			else printf("%lld\n",k);
		}
	}
}
