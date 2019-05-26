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
ll MOD=998244353;
ll n,m,q,a[1000010];
int main(){
	n=read();m=read();q=read();ll i,j,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		for(j=1;j<=(n/t1);j++) a[j*t1]=(a[j*t1]+j*t2%MOD)%MOD;
	}
	for(i=1;i<=q;i++){
		t1=read();ll ans=0;
		for(j=1;j<=(n/t1);j++) ans=(ans+j*a[j*t1]%MOD)%MOD;
		printf("%lld\n",ans);
	}
}
