#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 1000000007
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
int dp[3010][3010][2];
int main(){
	int n=read(),m=read(),i,j,k;
	dp[0][0][1]=1;
	for(i=1;i<=n;i++) dp[0][i][0]=1;
	for(i=0;i<m;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=1;k++){
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
				if(j==1){
					dp[i+1][j-1][1]=(dp[i+1][j-1][1]+dp[i][j][k])%MOD;
					dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][k])%MOD;
				}
				else if(j){
					dp[i+1][j-1][k]=(dp[i+1][j-1][k]+dp[i][j][k])%MOD;
					dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%MOD;
				}
//				if(j>0){
//					dp[i+1][j-1][k|(j==1)]=(dp[i+1][j-1][k|(j==1)]+dp[i][j][k])%MOD;
//					dp[i+1][j][k|(j==1)]=(dp[i+1][j][k|(j==1)]+dp[i][j][k])%MOD;
//				}
				if(j<n){
					dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k])%MOD;
					dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%MOD;
				}
			}
		}
	}
	ll ans=0;
	for(i=0;i<=n;i++) ans=(ans+dp[m][i][1])%MOD;
	printf("%lld\n",ans);
}
