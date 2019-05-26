#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000007
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
ll dp[2010][2010],p[2010],sum[2010][2010];
int main(){
	ll n=read(),k=read();ll i,j;
	p[0]=1;
	for(i=1;i<=n;i++) p[i]=p[i-1]*2%MOD;
	for(i=2;i<=n;i++) dp[1][i]=1,sum[1][i]=n-i+1; 
	for(i=2;i<k;i++){
		for(j=n-i+1;j>=2;j--){
			dp[i][j]=(dp[i-1][j]+sum[i-1][j+1])%MOD;
		}
		for(j=n-i+1;j>=2;j--) sum[i][j]=(sum[i][j+1]+dp[i][j])%MOD;
	}
	ll ans=0;
	for(i=2;i<=n-k+2;i++) ans+=dp[k-1][i],ans%=MOD;
	if(k==1) ans=1;
	if(k==n) printf("%lld\n",ans);
	else printf("%lld\n",ans*p[n-k-1]%MOD);
//	cout<<n<<' '<<k<<' '<<ans<<' '<<n-k-1<<' '<<p[n-k-1]<<'\n';
}

