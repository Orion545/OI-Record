#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll n,x[200010],root[200010],a[4000010],cnt,ch[4000010][2];
ll insert(ll l,ll r,ll pos,ll old){
	ll mid=(l+r)>>1,cur=++cnt;
//	cout<<"insert "<<l<<ends<<r<<ends<<pos<<ends<<a[old]<<endl;
	if(l==r){
		a[cur]=a[old]+1;return cur;
	}
	a[cur]=a[old]+1;
	if(mid>=pos) ch[cur][0]=insert(l,mid,pos,ch[old][0]),ch[cur][1]=ch[old][1];
	else ch[cur][1]=insert(mid+1,r,pos,ch[old][1]),ch[cur][0]=ch[old][0];
	return cur;
}
ll query(ll l,ll r,ll ql,ll qr,ll num){
	ll mid=(l+r)>>1,re=0;
	if(l>=ql&&r<=qr) return a[num];
	if(mid>=ql) re+=query(l,mid,ql,qr,ch[num][0]);
	if(mid<qr) re+=query(mid+1,r,ql,qr,ch[num][1]);
	return re; 
}
int main(){
	ll i;n=read();
//	assert(n<=100000);
	for(i=1;i<=n;i++){
		x[i]=read();
		if(x[i]>n) x[i]=n;
	}
	root[1]=insert(1,n,x[1],root[0]);ll ans=0;
	for(i=2;i<=n;i++){
		ans+=query(1,n,i,n,root[min(i-1,x[i])]);
//		cout<<i<<ends<<ans<<endl;
		root[i]=insert(1,n,x[i],root[i-1]);
	}
	cout<<ans;
}
