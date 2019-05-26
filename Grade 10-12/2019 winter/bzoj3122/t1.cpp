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
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){x=1;y=0;return a;}
	ll r1,r2,tmp=exgcd(b,a%b,r1,r2);
	x=r2;y=r1-(a/b)*r2;
	return tmp;
}
namespace hash{
	ll first[1000010],next[1000010],val[1000010],hash[1000010],mod=926081,cnt=0;
	void init(){memset(first,0,sizeof(first));cnt=0;}
	void insert(ll w,ll pos){
		ll p=w%mod,u;
//		cout<<"insert "<<w<<' '<<p<<' '<<pos<<'\n';
		for(u=first[p];u;u=next[u]){
			if(hash[u]==w){val[u]=pos;return;}
			if(!next[u]) break;
		}
		if(!next[u]){
			cnt++;
			if(!first[p]) first[p]=cnt;
			else next[u]=cnt;
			val[cnt]=pos;hash[cnt]=w;next[cnt]=0;
		}
	}
	ll find(ll w){
		ll p=w%mod,u;
//		cout<<"find "<<w<<' '<<p<<'\n';
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
	return gcd(b,a%b);
}
ll bsgs(ll a,ll b,ll p){
	if(b==1) return 0;
	ll i,j,m=ceil(sqrt((double)p)),tmp=b,cur,base=qpow(a,m,p);
	hash::init();
//	cout<<"bsgs "<<a<<' '<<b<<' '<<p<<' '<<m<<' '<<base<<'\n';
	for(j=0;j<m;j++){
		hash::insert(tmp,j);
		tmp=tmp*a%p;
	}
	tmp=1;
	for(i=m;i<=p;i+=m){
		tmp=tmp*base%p;cur=hash::find(tmp);
		if(~cur) return i-cur;
	}
	return -1;
}
int main(){
	ll T=read(),a,b,p,x1,t,t1,t2,c,ans,k,gg,tmp,x;
	while(T--){
		a=b=p=x1=t=t1=t2=x=ans=k=gg=tmp=x=0;
		p=read();a=read();b=read();x1=read();t=read();
//		cout<<"read in "<<p<<' '<<a<<' '<<b<<' '<<x1<<' '<<t<<'\n';
		if(a==0){
			if(t==x1) puts("1");
			else{
				if(t==b) puts("2");
				else puts("-1");
			}
			continue;
		}	
		if(a==1){
			//b*(n-1)=t-x1
			t2=(t-x1+p)%p;t1=b;
			//(n-1)*t1+k*p=t2
			gg=gcd(t1,p);
			if(t2%gg) puts("-1");
			else{
				exgcd(t1,p,ans,k);
//				cout<<"finish exgcd "<<t1<<' '<<ans<<' '<<p<<' '<<k<<' '<<t2<<' '<<gg<<'\n';
				if(ans<0){
					tmp=((-ans)/(p/gg))+(((-ans)%(p/gg))!=0);
					ans+=tmp*(p/gg);k-=tmp*(t1/gg);
				}
				ans=ans*(t2/gg)%p;
//				cout<<"finish exgcd "<<t1<<' '<<ans<<' '<<p<<' '<<k<<' '<<t2<<' '<<gg<<'\n';
				assert(ans*t1%p==t2);
				printf("%lld\n",ans+1);
			}
			continue;
		}
		c=qpow(a-1,p-2,p);
		t2=(t+b*c)%p;t1=(x1+b*c)%p;
		//t2=a[n-1]*t1
		//a[n-1]*t1+k*p=t2
		gg=gcd(t1,p);
//		cout<<"finish init "<<a<<' '<<x1<<' '<<b<<' '<<t<<' '<<p<<' '<<c<<' '<<t1<<' '<<t2<<' '<<gg<<'\n';
		if(t1==0){
			if(t2==0) puts("1");
			else puts("-1");
			continue;
		}
		if(t2%gg) puts("-1");
		else{
			exgcd(t1,p,ans,k);
//			cout<<"finish exgcd "<<t1<<' '<<ans<<' '<<p<<' '<<k<<' '<<t2<<'\n';
			if(ans<0){
				tmp=((-ans)/(p/gg))+(((-ans)%(p/gg))!=0);
				ans+=tmp*(p/gg);k-=tmp*(t1/gg);
			}
//			cout<<"finish exgcd "<<t1<<' '<<ans<<' '<<p<<' '<<k<<' '<<t2<<'\n';
			ans=ans*(t2/gg)%p;
			assert(ans*t1%p==t2);
			//a^x=ans
			x=bsgs(a,ans,p);
			if(~x) printf("%lld\n",x+1);
			else puts("-1");
		}
	}
}
