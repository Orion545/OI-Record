#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll q;
ll gcd(ll l,ll r){
	if(r==0) return l;
	return gcd(r,l%r);
}
int main(){
	q=read();ll a,b,c,g,help,gg;
	while(q--){
		a=read();b=read();c=read();
		if(a==0){
			puts("Finite");continue;
		}
		g=gcd(a,b);help=(b/g);
		while((gg=gcd(c,help))>1){
			while(help%gg==0) help/=gg;
		}
		if(help==1) puts("Finite");
		else puts("Infinite");
//		if(gcd(c,help)==min(c,help)) puts("Finite");
//		else puts("Infinite");
	}
}
