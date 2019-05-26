#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define hash DEEP_DARK_FANTASY
#define next VAN_YOU_SEE
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
namespace hash{
	ll first[1000010],val[1000010],hash[1000010],next[1000010],cnt=0,mod=926081;
	void init(){memset(first,0,sizeof(first));cnt=0;}
	void insert(ll w,ll pos){
		ll p=w%mod,u;
//		cout<<"insert "<<w<<' '<<pos<<'\n';
		for(u=first[p];u;u=next[u]){
			if(hash[u]==w){val[u]=pos;return;}
			if(!next[u]) break;
		}
		if(!next[u]){
			cnt++;
			if(!first[p]) first[p]=cnt;
			else next[u]=cnt;
			next[cnt]=0;val[cnt]=pos;hash[cnt]=w;
		}
	}
	ll query(ll w){
		ll p=w%mod,u;
//		cout<<"query "<<w<<' '<<p<<'\n';
		for(u=first[p];u;u=next[u]){
			if(hash[u]==w) return val[u];
		}
		return -1;
	}
}
ll qpow(ll a,ll b,ll p){
	ll re=1;
	while(b){
		if(b&1) re=re*a%p;
		a=a*a%p;b>>=1;
	}
	return re;
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll bsgs(ll a,ll b,ll p){
	if(b==1) return 0;
	ll i,j,tmp=1,d=1,cnt=0;
	hash::init();
	while((tmp=gcd(a,p))!=1){
		if(b%tmp) return -1;
		cnt++;b/=tmp;p/=tmp;d=d*(a/tmp)%p;
		if(b==d) return cnt;
	}
//	cout<<"begin bsgs "<<a<<' '<<b<<' '<<p<<' '<<d<<' '<<cnt<<'\n';
	ll m=ceil(sqrt(double(p))),base=qpow(a,m,p);
	tmp=b;
	for(j=0;j<m;j++){
		hash::insert(tmp,j);
		tmp=(tmp*a)%p;
	}
	for(i=m;i<=p+m;i+=m){
		d=(d*base)%p;
		tmp=hash::query(d);
		if(tmp!=-1) return i-tmp+cnt;
	}
	return -1;
}
int main(){
	ll a,b,p,ans;
	while(1){
		a=read();p=read();b=read();
		if(a==0&&p==0&&b==0) return 0;
		a%=p;b%=p;
		ans=bsgs(a,b,p);
		if(ans!=-1) printf("%lld\n",ans);
		else puts("No Solution");
	}
}
