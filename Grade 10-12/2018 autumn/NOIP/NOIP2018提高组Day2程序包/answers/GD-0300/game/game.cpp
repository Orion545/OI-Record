#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define ll long long
using namespace std;
int n,m;
ll dp[1000005][8];
ll dp2[8][256];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=3){
		for(int S=0;S<1<<n;++S)dp[0][S]=1;
		for(int i=1;i<m;++i)for(int S=0;S<1<<n;++S){
			for(int ss=0;ss<1<<n;++ss)if((S&((1<<(n-1))|(ss>>1)))==S)dp[i][S]=(dp[i][S]+dp[i-1][ss])%mod;
		}
		ll ans=0;
		for(int S=0;S<1<<n;++S)ans=(ans+dp[m-1][S])%mod;
		printf("%lld\n",ans);
	}else{
		for(int S=0;S<1<<n;++S)dp2[0][S]=1;
		for(int i=1;i<m;++i)for(int S=0;S<1<<n;++S){
			for(int ss=0;ss<1<<n;++ss)if((S&((1<<(n-1))|(ss>>1)))==S)dp2[i][S]=(dp2[i][S]+dp2[i-1][ss])%mod;
		}
		ll ans=0;
		for(int S=0;S<1<<n;++S)ans=(ans+dp2[m-1][S])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
