#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
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
ll n,m,o,f[1010],g1[1010],g2[1010];
int main(){
	n=read();m=read();o=read();
	ll i,j,k;
	f[0]=1;
	for(i=1;i<=n;i++){
		if(i%m==0) f[i]=f[i-1]+f[i/m];
		else f[i]=f[i-1];
//		cout<<i<<' '<<f[i]<<' '<<(i%m)<<'\n';
	}
	memcpy(g2,f,sizeof(f));
	for(k=1;k<o;k++){
		memset(g1,0,sizeof(g1));
		for(i=0;i<=n;i++){
			for(j=0;j<=i;j++) g1[i]=(g1[i]+g2[j]*f[i-j])%MOD;
		}
		swap(g1,g2);
	}
	ll sum=0;
	for(i=0;i<=n;i++) sum=(sum+g2[i])%MOD;
	cout<<sum<<'\n';
}
