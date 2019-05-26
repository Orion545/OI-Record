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
ll gcd(ll l,ll r){
	if(r==0) return l;
	return gcd(r,l%r);
}
ll n,a[200010],b[200010];
int vis[200010],pri[200010],cntp;
void init(){
	int i,j,k,len=200000;vis[1]=0;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;if(i%pri[j]==0) break;
		}
	}
}
bool check(int num){
	for(int i=2;i<=n;i++){
		if(a[i]%num&&b[i]%num) return 0;
	}
	return 1;
}
int main(){
	init();
	n=read();ll i,tmp;
	for(i=1;i<=n;i++) a[i]=read(),b[i]=read();
	tmp=sqrt(a[1]);
	for(i=1;i<=tmp;i++){
		if(a[1]%i) continue;
		if(vis[i]&&check(i)){
			cout<<i<<'\n';return 0;
		}
		if(check(a[1]/i)){
			cout<<a[1]/i<<'\n';return 0;
		}
	}
	tmp=sqrt(b[1]);
	for(i=1;i<=tmp;i++){
		if(b[1]%i) continue;
		if(vis[i]&&check(i)){
			cout<<i<<'\n';return 0;
		}
		if(check(b[1]/i)){
			cout<<b[1]/i<<'\n';return 0;
		}
	}
	cout<<-1;
}
