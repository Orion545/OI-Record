#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
#define ll long long
using namespace std;
int n,m,p;
ll c[510][510];
//ll power[1010][1010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	int i,j,k;ll tmp;
	c[0][0]=1;
	for(i=1;i<=400;i++)
		for(j=0;j<=i;j++){
			c[i][j]=c[i-1][j];
			if(j>0) (c[i][j]+=c[i-1][j-1])%=MOD;
		}
//	for(i=1;i<=500;i++){
//		power[i][0]=1;
//		for(j=1;j<=1000;j++)
//			power[i][j]=power[i][j-1]*i%MOD;
//	}
	ll ans=0;
//	for(i=0;i<=n;i++){
//		for(j=0;j<=m;j++){
//			for(k=0;k<=p;k++){
//				(ans+=c[n][i]*c[m][j]%MOD*c[p][k]%MOD*power[k+1][i*j]%MOD*(((n+m+p-i-j-k)&1)?-1:1))%=MOD;
//			}
//		}
//	}
	for(i=0;i<=n;i++){
		for(k=0;k<=p;k++){
			tmp=c[n][i]*c[p][k]%MOD;
			j=qpow((1-qpow(k+1,i)+MOD)%MOD,m);
			tmp=tmp*j%MOD;
			if((n+m+p-i-k)&1) tmp=-tmp;
			ans=(ans+tmp+MOD)%MOD;
//			cout<<i<<' '<<k<<' '<<tmp<<'\n';
		}
	}
	printf("%lld\n",(ans+MOD)%MOD);
}

