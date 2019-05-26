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
ll calc(ll l,ll r){
	return (l+r)*(r-l+1)/2;
}
int main(){
	ll n,h;n=read();h=read();
	if(h>=3e9||((h*(h+1)/2)>n)){
		ll l=0,r=h,mid;
		while(l<r){
			mid=(l+r)>>1;mid++;
//			cout<<l<<ends<<r<<ends<<mid<<ends<<mid*(mid+1)<<ends<<2*n<<ends<<(mid*(mid+1)>2*n)<<endl;
			if(mid>3e9||(mid*(mid+1)>2*n)) r=mid-1;
			else l=mid;
		}
		cout<<l+((n-(l*(l+1)/2))>0);
		return 0;
	}
	ll l=0,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;mid++;
//		cout<<l<<ends<<r<<ends<<mid<<ends<<calc(h,mid)+calc(1,mid-1)<<ends<<n<<endl;
		if(mid>=3e9||(calc(h,mid)+calc(1,mid-1)>n)) r=mid-1;
		else l=mid;
	}
	cout<<l-h+l+((n-(calc(h,l)+calc(1,l-1)))+l-1)/l;
//	cout<<((n-(calc(h,l)+calc(1,l-1)))+l-1)<<ends<<((n-(calc(h,l)+calc(1,l-1)))+l-1)/l<<endl;
}
