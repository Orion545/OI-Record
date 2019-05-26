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
ll pri[1000010],cntp,a[10000010],b[10000010],f[10000010],sum[10000010];bool vis[10000010];
void init(){
	ll i,j,k,len=10000000,tmp;
	a[1]=b[1]=1;f[1]=0;
	for(i=2;i<=len;i++){
		if(!vis[i]){
			pri[++cntp]=i;
			a[i]=1;b[i]=i;
			f[i]=1;
		}
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(i%pri[j]==0){
				a[k]=a[i]+1;
				b[k]=b[i]*pri[j];
				tmp=i/b[i];
				if(tmp==1) f[k]=1;
				else f[k]=((a[k]==a[tmp])?-f[tmp]:0);
				break;
			}
			a[k]=1;b[k]=pri[j];
			f[k]=((a[i]==1)?-f[i]:0);
		}
	}
	for(i=2;i<=len;i++) sum[i]=sum[i-1]+f[i];
}
int main(){
	init();
	ll T=read(),n,m,i,j,ans;
	while(T--){
		n=read();m=read();ans=0;
		if(n>m) swap(n,m);
		for(i=1;i<=n;i=j+1){
			j=min(n/(n/i),m/(m/i));
			ans+=(n/i)*(m/i)*(sum[j]-sum[i-1]);
		}
		printf("%lld\n",ans);
	}
}
