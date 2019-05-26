#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000007
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll inv[100010];
ll n,k;
void init(){
	int i;inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
}ll ans;
int main(){
	n=read();k=read();
	init();
	ans=inv[n];
	for(int i=1;i<k;i++){
		ans=(1ll-ans+MOD)*inv[n-i-1]%MOD;
	}
	if(k) ans=(1ll-ans+MOD)*inv[1]%MOD;
	printf("%lld\n",ans);
}

