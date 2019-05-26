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
	int T=read();
	ll n,m,k;
	while(T--){
		n=read();m=read();k=read();
		if(k<n||k<m){
			puts("-1");continue;
		}
		ll tmp=min(m,n),f=0;
		if(n%2!=m%2) f=1;
		if(!f){
			if(((k-tmp)%2)==0) cout<<k<<'\n';
			else cout<<k-2<<'\n';
		}
		else{
			cout<<k-1<<'\n';
		}
	}
}
