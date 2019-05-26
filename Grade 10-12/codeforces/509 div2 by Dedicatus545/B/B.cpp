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


ll gcd(ll asdfa,ll b){
	if(b==0) return asdfa;
	return gcd(b,asdfa%b);
}
ll asdfa,b,x,y;




int main(){
	
	asdfa=read();
	
				b=read();
				
			x=read();
											y=read();
	ll ggggggg=gcd(x,y);
	x/=ggggggg;
	y/=ggggggg;
	cout<<min(asdfa/x,b/y)<<'\n';
}
