#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 998244353
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
ll qpow(ll a,ll b){
	ll re=1;while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll h[1010];
ll dp[2][502][502];
void add(ll &x,ll y){
	x+=y;
	if(x>=MOD) x-=MOD;
}
int main(){
	ll n=read(),k=read(),i,j,l,ans=0,pre=0,cur=1;
	dp[cur][1][1]=2;
	for(i=1;i<n;i++){
		swap(cur,pre);
		memset(dp[cur],0,sizeof(dp[cur]));
		for(j=1;j<=i;j++){
			for(l=1;l<=j;l++){
				add(dp[cur][max(j,l+1)][l+1],dp[pre][j][l]);
				add(dp[cur][j][1],dp[pre][j][l]);
			}
		}
	}
	for(i=1;i<=n;i++){
			for(l=1;l<=i;l++){
				add(h[i],dp[cur][i][l]);
			}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i*j<k) (ans+=h[i]*h[j]%MOD)%=MOD; 
		}
	}
	cout<<ans*qpow(2,MOD-2)%MOD;
}
