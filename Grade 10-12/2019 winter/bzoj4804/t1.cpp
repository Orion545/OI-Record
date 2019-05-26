#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int pri[1000010],cntp;ll f[10000010],sum[10000010];bool vis[10000010];
void init(){
	int i,j,k,len=10000000;f[1]=sum[1]=1;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,f[i]=i-2;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0){
				if(i/pri[j]%pri[j]==0) f[k]=f[i]*pri[j];
				else f[k]=f[i/pri[j]]*(pri[j]-1)*(pri[j]-1);
				break;
			}
			f[k]=f[i]*f[pri[j]];
		}
		sum[i]=(f[i]+sum[i-1]);
	}
}
int main(){
	init();int n,i,j,tmp,T=read();ll ans=0;
	while(T--){
		n=read();ans=0;
		for(i=1;i<=n;i=j+1){
			tmp=n/i;j=n/tmp;
			ans+=1ll*tmp*tmp*(sum[j]-sum[i-1]);
		}
		printf("%lld\n",ans);
	}
}
