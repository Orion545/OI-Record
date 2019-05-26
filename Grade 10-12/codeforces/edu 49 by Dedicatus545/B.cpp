#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
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
int main(){
	ll n=read(),q=read();
	if(n&1ll){
	while(q--){
		ll x=read(),y=read(),tmp=x+y,id=(x-1)*n+y;
		if(tmp&1){
			cout<<(id)/2ll+(n*n)/2ll+1ll<<'\n';
		}
		else{
			cout<<(id+1ll)/2ll<<'\n';
		}
	}
	}
	else{
	while(q--){
		ll x=read(),y=read(),tmp=x+y,id=(x-1)*n+y;
		if((x&1ll)==(y&1ll)){
			if(x&1ll) cout<<(id-1ll)/2ll+1ll<<'\n';
			else cout<<(id)/2ll<<'\n';
		}
		else{
			if(x&1ll) cout<<id/2ll+(n*n)/2ll<<'\n';
			else cout<<(id-1ll)/2ll+1ll+(n*n)/2ll<<'\n';
		}
	}
	}
}
