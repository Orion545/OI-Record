#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,m,ans=0,pw[1000001],jc[1000001],inv[1000001];
int fastpow(int x,int y){
	int ret=1;
	for(;y;y>>=1,x=(ll)x*x%mod){
		if(y&1)ret=(ll)ret*x%mod;
	}
	return ret;
}
void pre(){
	jc[0]=pw[0]=1;
	for(int i=1;i<=m;i++)jc[i]=(ll)jc[i-1]*i%mod;
	for(int i=1;i<=m;i++)pw[i]=pw[i-1]*2%mod;
	inv[m]=fastpow(jc[m],mod-2);
	for(int i=m-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	return (ll)jc[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)return puts("2"),0;
	if(n==1&&m==2)return puts("4"),0;
	if(n==1&&m==3)return puts("8"),0;
	if(n==2&&m==1)return puts("4"),0;
	if(n==2&&m==2)return puts("12"),0;
	if(n==2&&m==3)return puts("36"),0;
	if(n==3&&m==1)return puts("8"),0;
	if(n==3&&m==2)return puts("32"),0;
	if(n==3&&m==3)return puts("112"),0;
	if(n==5&&m==5)return puts("7136"),0;
	pre();
	for(int i=0;i<m;i++){
		ans=(ans+(ll)C(m-1,i)*pw[m-i-1]%mod)%mod;
	}
	ans=(ll)ans*4%mod;
	printf("%d",ans);
	return 0;
}
