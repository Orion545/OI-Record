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
ll n,len,x,st[100010],ed[100010];
int main(){
	n=read();len=read();x=read();ll i;
	for(i=1;i<=n;i++){
		st[i]=read();ed[i]=st[i]+read();
	}
	st[0]=ed[0]=0;ll ans=0;
	for(i=0;i<n;i++){
		ans+=(st[i+1]-ed[i])/x;
	}
	ans+=(len-ed[n])/x;
	cout<<ans;
}
