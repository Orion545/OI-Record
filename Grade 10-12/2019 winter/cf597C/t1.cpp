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
ll n,m,a[100010];
struct BIT{
	ll a[100010];
	void add(ll x,ll val){
//		cout<<"	ADD "<<x<<' '<<val<<'\n';
		for(;x<=n;x+=(x&(-x))) a[x]+=val;
	}
	ll sum(ll x){
		ll re=0;
//		cout<<"	SUM "<<x<<'\n';
		for(;x;x-=(x&(-x))) re+=a[x];
//		cout<<"	SUMGET "<<re<<'\n';
		return re;
	}
}T[20];
int main(){
	n=read();m=read();ll i,j;
	for(i=1;i<=n;i++) a[i]=read();
	T[1].add(a[1],1);
	for(i=2;i<=n;i++){
//		cout<<"begin "<<i<<' '<<a[i]<<'\n';
		for(j=m;j>=1;j--) T[j+1].add(a[i],T[j].sum(a[i]));
		T[1].add(a[i],1);
	}
	cout<<T[m+1].sum(n)<<'\n';
}
