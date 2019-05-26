#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define MOD 1000000007
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n;
ll dp[2000010],sum[2000010];
void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
	n=read();
	int i;
	dp[1]=1;
	for(i=1;i<=n;i++){
		if(i>=3) add(dp[i],sum[i-3]);
		add(dp[i],dp[i-1]);
		(sum[i]=sum[i-1]+dp[i])%=MOD;
	}
	ll ans=0;
	for(i=1;i<n;i++) add(ans,dp[i]*(n-1)%MOD*(n-1)%MOD);
	for(i=1;i<n-1;i++) add(ans,dp[i]*(i+1)%MOD);
	add(ans,(dp[n]*n+dp[n-1]*(n-1))%MOD);
	cout<<ans<<'\n';
}
