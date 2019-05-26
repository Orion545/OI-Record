#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define dec DEEP_DARK_FANTASY
#define add VAN_YOU_SEE
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
ll add[100010],dec[100010],n,m,a[100010];
void addition(ll l,ll r,ll val){
//	cout<<"addition "<<l<<' '<<r<<' '<<val<<'\n';
	add[l]+=val;
	add[r+1]-=val;
}
void decrease(ll l,ll r,ll val){
//	cout<<"decrease "<<l<<' '<<r<<' '<<val<<'\n';
	dec[l]+=val;
	dec[r+1]-=val;
}
int main(){
	n=read();m=read();ll i,l,r;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<n;i++){
		l=a[i];r=a[i+1];
		if(l==r) continue;
		if(l<r){
			addition(1,l,r-l);
			addition(r+1,m,r-l);
			
			addition(l+1,r,r+1);
			decrease(l+1,r,1);
		}
		else{
			addition(r+1,l,r+m-l);
			
			addition(1,r,r+1);
			decrease(1,r,1);
			
			addition(l+1,m,r+m+1);
			decrease(l+1,m,1);
		}
	}
	ll ans=1e15;
	for(i=1;i<=m;i++){
		add[i]+=add[i-1];
		dec[i]+=dec[i-1];
//		if(i==54400) cout<<i<<' '<<add[i]<<' '<<dec[i]<<'\n';
		ans=min(ans,add[i]-dec[i]*i);
	}
	cout<<ans<<'\n';
}

