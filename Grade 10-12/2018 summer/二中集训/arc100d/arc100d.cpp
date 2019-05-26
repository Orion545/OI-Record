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
ll n;ll m=200000;
struct BIT{
	ll a[200010];
	void clear(){
		memset(a,0,sizeof(a));
	}
	ll lowbit(ll x){
		return x&(-x);
	}
	void add(ll x,ll val){
		for(;x<=m;x+=lowbit(x)) a[x]+=val;
	}
	ll sum(ll x){
		ll re=0;
//		cout<<"getsum "<<x<<' ';
		for(;x>0;x-=lowbit(x)) re+=a[x];
//		cout<<re<<'\n';
		return re;
	}
}T;
struct ele{
	ll val,num;
}a[100010];ll w[100010];
bool cmp1(ele l,ele r){
	return l.val<r.val;
}
bool cmp2(ele l,ele r){
	return l.num<r.num;
}
ll x[100010];ll lim;
bool check(ll val){
	ll i;ll sum=0,re=0;T.clear();
	for(i=1;i<=n;i++){
		if(a[i].val<val) x[i]=-1;
		else x[i]=1;
	}
	T.add(100000,1);
	for(i=1;i<=n;i++){
		sum+=x[i];
		re+=T.sum(sum+100000);
		T.add(sum+100000,1);
	}
//	cout<<"check "<<val<<' '<<re<<'\n';
	return re>=(lim/2+lim%2);
}
int main(){
	ll i;
	n=read();lim=n*(n+1)/2;
	for(i=1;i<=n;i++) a[i].val=read(),a[i].num=i;
	sort(a+1,a+n+1,cmp1);
	for(i=1;i<=n;i++) w[i]=a[i].val;
	sort(a+1,a+n+1,cmp2);
	ll l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(check(w[mid])) l=mid;
		else r=mid-1;
	}
	printf("%lld\n",w[l]);
} 
/*
10
5 9 5 9 8 9 3 5 4 3

*/
