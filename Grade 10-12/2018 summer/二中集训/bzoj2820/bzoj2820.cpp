#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
ll vis[10000010],g[10000010],pri[1000010],cntp,mu[10000010];
void init(){
	int i,j;ll k;mu[1]=1;g[1]=0;
	for(i=2;i<=10000000;i++){
		if(!vis[i]) pri[++cntp]=i,mu[i]=-1,g[i]=1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>10000000) break;
			vis[k]=1;
			if(i%pri[j]==0){mu[k]=0;g[k]=mu[i];break;}
			mu[k]=-mu[i];g[k]=mu[i]-g[i];
		}
	}
	for(i=1;i<=10000000;i++) g[i]+=g[i-1];
} 
int main(){
	init();ll ans;int T=read(),i,j,n,m;
	while(T--){
		n=read();m=read();ans=0;
		if(n>m) swap(n,m);
		for(i=1;i<=n;i=j+1){
			j=min(n/(n/i),m/(m/i));
			ans+=(g[j]-g[i-1])*(n/i)*(m/i);
		}
		printf("%lld\n",ans);
	}
}

