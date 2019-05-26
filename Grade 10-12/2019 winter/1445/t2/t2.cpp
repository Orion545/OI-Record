#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll fac[3010],finv[3010];
void init(){
	ll i,len=3000;
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) fac[i]=fac[i-1]*i%MOD;
	finv[len]=qpow(fac[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD;
}
ll C(ll x,ll y){
	return fac[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll x[1010],y[1010],n,p0,p1,p2,p3,m,f[6010];
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
inline void dec(ll &a,ll b){
	a-=b;
	if(a<0) a+=MOD;
}
int main(){
	init();
	n=read();p0=1;p1=read()+1;p2=p1+read();p3=n+1;m=read();ll i,j;ll t1,t2;
	for(i=0;i<=m;i++) f[i]=((m-i)&1)?0:C(m,(m-i)>>1);
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		x[i]=t1+t2;y[i]=t1-t2;
//		cout<<x[i]<<' '<<y[i]<<'\n';fflush(stdout);
	}
	ll only[3]={0},ans=0,tmpx,tmpy,tmp;
	//get one
	//do only
	tmpx=0;tmpy=0;
	for(i=-3000;i<=3000;i++){
		t1=1;t2=1;
		for(j=p0;j<p1;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		add(tmpx,t1);
		add(tmpy,t2);
	}
	only[0]=tmpx*tmpy%MOD;
	//do other
	tmpx=0;tmpy=0;
	for(i=-3000;i<=3000;i++){
		t1=1;t2=1;
		for(j=p1;j<p3;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		add(tmpx,t1);
		add(tmpy,t2);
	}
	tmp=tmpx*tmpy%MOD;
	dec(ans,tmp*only[0]%MOD);
//	cout<<"finish one "<<only[0]<<' '<<tmp<<' '<<ans<<'\n';
	//get two
	//do only
	tmpx=0;tmpy=0;
	for(i=-3000;i<=3000;i++){
		t1=1;t2=1;
		for(j=p1;j<p2;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		add(tmpx,t1);
		add(tmpy,t2);
	}
	only[1]=tmpx*tmpy%MOD;
	//do other
	tmpx=0;tmpy=0;
	for(i=-3000;i<=3000;i++){
		t1=1;t2=1;
		for(j=p0;j<p1;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		for(j=p2;j<p3;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		add(tmpx,t1);
		add(tmpy,t2);
	}
	tmp=tmpx*tmpy%MOD;
	dec(ans,tmp*only[1]%MOD);
//	cout<<"finish two "<<only[1]<<' '<<tmp<<' '<<ans<<'\n';
	//get three
	//do only
	tmpx=0;tmpy=0;
	for(i=-3000;i<=3000;i++){
		t1=1;t2=1;
		for(j=p2;j<p3;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		add(tmpx,t1);
		add(tmpy,t2);
	}
	only[2]=tmpx*tmpy%MOD;
	//do other
	tmpx=0;tmpy=0;
	for(i=-3000;i<=3000;i++){
		t1=1;t2=1;
		for(j=p0;j<p2;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		add(tmpx,t1);
		add(tmpy,t2);
	}
	tmp=tmpx*tmpy%MOD;
	dec(ans,tmp*only[2]%MOD);
//	cout<<"finish three "<<only[2]<<' '<<tmp<<' '<<ans<<'\n';
	
	add(ans,only[0]*only[1]%MOD*only[2]%MOD);
	//do altogether
	tmpx=0;tmpy=0;
	for(i=-3000;i<=3000;i++){
		t1=1;t2=1;
		for(j=p0;j<p3;j++){
			if(!t1&&!t2) break;
			if(t1) t1=(t1*f[abs(i-x[j])])%MOD;
			if(t2) t2=(t2*f[abs(i-y[j])])%MOD;
		}
		add(tmpx,t1);
		add(tmpy,t2);
	}
	tmp=tmpx*tmpy%MOD;
	add(ans,2*tmp%MOD);

	cout<<ans<<'\n';
}
