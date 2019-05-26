#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'||ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll MOD=1e9+7;
ll n,m,fail[100010],flag[100010],dp[100010],sum1[100010],sum2[100010];char a[100010],b[100010];
int main(){
	scanf("%s",a);scanf("%s",b);ll i,j,ans=0;
	n=strlen(a);m=strlen(b);
	j=0;fail[0]=fail[1]=0;
	for(i=1;i<m;i++){
		while(j&&b[i]!=b[j]) j=fail[j];
		j+=(b[i]==b[j]);fail[i+1]=j;
	}
	j=0;
	for(i=0;i<n;i++){
		while(j&&a[i]!=b[j]) j=fail[j];
		j+=(a[i]==b[j]);
		if(j==m) flag[i]=1;
	}
	for(i=0;i<n;i++){
		if(flag[i]) dp[i+1]=(i-m+2)+sum2[i+1-m];
		else dp[i+1]=dp[i];
		dp[i+1]%=MOD;ans=(ans+dp[i+1])%MOD;
		sum1[i+1]=(sum1[i]+dp[i+1])%MOD;
		sum2[i+1]=(sum2[i]+sum1[i+1])%MOD;
	}
	printf("%lld\n",ans);
}
