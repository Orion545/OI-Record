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
ll n,k;
int main(){
	n=read();k=read();
	if(k<=n+1ll){
		cout<<(k-1ll)/2ll;
	}
	else{
		cout<<max(0ll,(n-(k-n)+1ll)/2);
	}
}
