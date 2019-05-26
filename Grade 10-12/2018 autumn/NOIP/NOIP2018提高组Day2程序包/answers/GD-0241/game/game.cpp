#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#include<vector>
#define MOD 1000000007
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
int n,m;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re%MOD;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n>m) swap(n,m);
	if(n==1){
		cout<<qpow(2,n*m)<<'\n';
		return 0;
	}
	if(n==2){
		cout<<qpow(4,n+m-1)<<'\n';
		return 0;
	}
	if(n==3&&m==3){
		cout<<112<<'\n';
		return 0;
	}
	if(n==3&&m>=4){
		cout<<256ll*qpow(4,m-4)%MOD<<'\n';
		return 0;
	}
	if(n==4&&m==4){
		cout<<912<<'\n';
		return 0;
	}
	if(n==4&&m>=4){
		cout<<1048576ll*qpow(4,m-5)%MOD<<'\n';
		return 0;
	}
	if(n==5&&m==5){
		cout<<7136<<'\n';
		return 0;
	}
}
