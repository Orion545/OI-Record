#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
char cch;
inline int rd(){
	int x=0,fl=1;
	cch=getchar();
	while(cch<'0'||cch>'9'){
		if(cch=='-') fl=-1;
		cch=getchar();
	}
	while(cch>='0'&&cch<='9') x=(x<<1)+(x<<3)+cch-'0',cch=getchar();
	return x*fl;
}
const int mod=1e9+7,N=1e6+3;
int dp[N][40],bin[10];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=rd(),m=rd();int mm=m-1;
	int ed=(1<<n)-1,nd=n-1,msk;
	bin[0]=1;rep(i,1,nd) bin[i]=bin[i-1]<<1;
	rep(i,0,ed) dp[1][i]=1;
	rep(i,1,mm){
		rep(j,0,ed){cout<<j<<endl;
			msk=bin[nd];
			rep(k,1,nd) if(j&bin[k]) msk|=bin[k-1];
			/**/if(i>1){
				rep(k,0,ed) if((k|msk)==msk) cout<<k<<' '<<dp[i][j]<<endl,dp[i+1][k]=(dp[i+1][k]+dp[i][j]-(1<<n-2))%mod; cout<<endl;
			}/**/
			else rep(k,0,ed) if((k|msk)==msk) cout<<k<<' '<<dp[i][j]<<endl,dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod; cout<<endl;
		}
	}
	int ans=0;
	rep(j,0,ed) ans=(ans+dp[m][j])%mod;
	printf("%d",ans);
}
