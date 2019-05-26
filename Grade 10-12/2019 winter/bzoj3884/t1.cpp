#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int pri[1000010],cntp,phi[10000010];bool vis[10000010];
void init(){
	int i,j,k,len=10000000;
	phi[1]=1;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,phi[i]=i-1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0){phi[k]=phi[i]*pri[j];break;}
			phi[k]=phi[i]*phi[pri[j]];
		}
	}
}
ll qpow(ll a,ll b,ll MOD){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll solve(int n){
//	cout<<"solve "<<n<<'\n';
	if(n==1) return 0;
	int tmp=0;
	while(1^(n&1)) n>>=1,tmp++;
//	cout<<"get "<<n<<' '<<tmp<<'\n';
	int re=solve(phi[n]);
	re=(re-tmp%phi[n]+phi[n])%phi[n];
	return qpow(2,re,n)<<tmp;
}
int main(){
	init();
	int T=read(),n;
	while(T--){
		n=read();
		printf("%lld\n",solve(n)%n);
	}
}
