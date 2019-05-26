#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 924844033
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
int n,k;
ll dp[4010][2010][2],border[4010],f[2010],fac[2010];
int main(){
	n=read();k=read();int i,j,re=n%k;ll tmp=0,ans=0;
	fac[0]=fac[1]=1;
	for(i=2;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
	for(i=1;i<=re;i++){
		tmp+=(n/k+1);border[tmp]=1;
		tmp+=(n/k+1);border[tmp]=1;
	}
	for(i=re+1;i<=k;i++){
		tmp+=n/k;border[tmp]=1;
		tmp+=n/k;border[tmp]=1;
	}
	dp[1][0][0]=1;
	for(i=2;i<=(n<<1);i++){
		for(j=0;j<=n;j++){
			dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%MOD;
			if(!border[i-1]) dp[i][j][1]=dp[i-1][j-1][0];
		}
	}
	for(i=0;i<=n;i++) f[i]=(dp[n<<1][i][0]+dp[n<<1][i][1])%MOD;
	tmp=1;
	for(i=0;i<=n;i++){
		ans+=tmp*f[i]*fac[n-i]%MOD;ans=(ans+MOD)%MOD;
		tmp=-tmp;
	}
	printf("%lld\n",ans);
}

