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
ll n;
int main(){
	n=read();int cnt=0,ans=0,flag=0;ll x=n;
	while(x){
		if(x%10!=9) flag=1;
		cnt+=flag;
		ans+=(x%10);
		x/=10;
//		cout<<ans<<'\n';
	}
	cout<<ans+max(0,(cnt-1)*9);
}
