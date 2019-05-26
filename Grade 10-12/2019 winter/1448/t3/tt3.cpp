#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll n,m;ll MOD;
ll a[100010][110];
ll qpow(ll a,ll b,ll mm){
	ll re=1;
//	cout<<"qpow "<<a<<' '<<b<<' '<<mm<<' ';
	while(b){
		if(b&1) re=re*a%mm;
		a=a*a%mm;b>>=1;
	}
//	cout<<re%MOD<<'\n';
	return re;
}
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
inline ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll pri[100010],cntp,vis[100010],phi[100010];
inline void init(){
	ll i,j,k,len=100000;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,phi[i]=i-1;
//		if(i<=100) cout<<i<<' '<<phi[i]<<'\n';
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]) phi[k]=phi[i]*(pri[j]-1);
			else{phi[k]=phi[i]*pri[j];break;}
		}
	}
}
ll s[110],top=0;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		re=re*a;
		if(re>=MOD) return -1;
		b--;
	}
	return re;
}
int main(){
	init();
	n=read();m=read();MOD=read();ll i,j,t1,t2,t3,t4;
	s[++top]=MOD;
	while(phi[s[top]]!=1) s[top+1]=phi[s[top]],top++;
	for(i=1;i<=n;i++){
		a[i][1]=a[i][0]=read();
		if(a[i][0]>=MOD) a[i][0]=-1;
		for(j=2;j<=top;j++) a[i][j]=a[i][1]%s[j];
	}
//	for(i=1;i<=n;i++) cout<<i<<' '<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<'\n';
	while(m--){
		t4=read();
		if(t4==0){
			t1=read();t2=read();t3=read();
			for(i=t1;i<=t2;i++){
//				a[i][top]=t3%s[top];
				for(j=1;j<top;j++){
					if(a[i][0]==-1||a[i][0]>=phi[s[j]]) a[i][j]=qpow(t3,a[i][j+1]+phi[s[j]],s[j]);
					else a[i][j]=qpow(t3,a[i][0],s[j]);
				}
				a[i][top]=t3%s[top];
				if(a[i][0]!=-1&&a[i][0]<=MOD) a[i][0]=qpow(t3,a[i][0]);
			}
		}
		else{
			t1=read();t2=read();t3=0;
			for(i=t1;i<=t2;i++) add(t3,a[i][1]);
			printf("%lld\n",t3);
		}
//		for(i=1;i<=n;i++) cout<<i<<' '<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<'\n';
	}
}
