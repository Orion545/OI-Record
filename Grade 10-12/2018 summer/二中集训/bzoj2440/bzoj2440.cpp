#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
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
ll mu[100010],pri[100010],cntp,vis[100010];
void init(){
	ll i,j,k,len=100000;mu[1]=1;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,mu[i]=-1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0){mu[k]=0;break;}
			mu[k]=-mu[i];
		}
	}
} 
ll cntsqr(ll lim){
	ll i,len=sqrt(lim);ll re=0;
	for(i=1;i<=len;i++) re+=mu[i]*(lim/(i*i));
//	cout<<"cntsqr "<<lim<<' '<<re<<'\n';
	return re;
}
int main(){
	int T=read();ll n,l,r,mid;
	init();
	while(T--){
		n=read();
		l=1;r=10000000000;
		while(l<r){
			mid=(l+r)>>1;
			if(cntsqr(mid)>=n) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
}

