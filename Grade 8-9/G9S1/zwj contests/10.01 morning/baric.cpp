#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define inf 0x7fffffff/2
using namespace std;
int n,m,a[110];
int dp[110][110]; 
//dp[i][j]: prefix 1-i,chosen j
int pre[110],suf[110],sum[110][110];
int abs(int k){
	if(k>=0) return k;
	else return -k;
}
int main(){
	freopen("baric.in","r",stdin);
	freopen("baric.out","w",stdout);
	int i,j,k,tmp1,tmp2,t,l;
	scanf("%d%d",&n,&m);
	int ans=m,anss=n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i][1]=0;
	} 
	for(i=1;i<=n-2;i++){
		for(j=i+2;j<=n;j++){
			for(k=i+1;k<j;k++){
				sum[i][j]+=abs((a[k]<<1)-a[i]-a[j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++) pre[i]+=abs(a[i]-a[j])<<1;
		dp[i][1]=pre[i];
		for(j=n;j>i;j--) suf[i]+=abs(a[i]-a[j])<<1;
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=i;j++){
			dp[i][j]=inf/2;
			for(k=1;k<i;k++) dp[i][j]=min(dp[i][j],dp[k][j-1]+sum[k][i]);
			if(dp[i][j]+suf[i]<m){
				if(j<ans) ans=j,anss=dp[i][j]+suf[i];
				else if(j==ans&&dp[i][j]+suf[i]<anss) anss=dp[i][j]+suf[i];
			}
		}
	}
	printf("%d %d",ans,anss);
} 
