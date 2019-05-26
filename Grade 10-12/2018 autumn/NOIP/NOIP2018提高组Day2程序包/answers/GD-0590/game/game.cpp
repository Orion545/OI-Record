#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[2][65];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	bool p;
	scanf("%d%d",&n,&m);
	for(int i=0;i<(1<<n);i++)dp[1][i]=1,dp[2][i]=0;
	for(int i=2;i<=m;i++){
		for(int k=0;k<(1<<n);k++){
			for(int j=0;j<(1<<n);j++){
				p=true;
				for(int t=0;t<n;t++){
					if(((1<<t)&(j<<1)) && !((1<<t)&k)){
						p=false;
						break;
					}
				}
				if(p)dp[2][k]=(long long)(dp[1][j]+dp[2][k])%1000000007;
			}
		}
		for(int j=0;j<(1<<n);j++){
			dp[1][j]=dp[2][j];
			dp[2][j]=0;
		}
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++)ans=(long long)(ans+dp[1][i])%1000000007;
	printf("%d",ans);
	return 0;
}
