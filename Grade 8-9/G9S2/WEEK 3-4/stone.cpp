#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
#define ll long long
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
int dp[2010][2010],s[2010][2010],pre[2010],n;
int main(){
	int i,j,k,l,tmp,ans=inf;
	n=read();
	for(i=1;i<=n;i++) 
		dp[i][i]=read(),pre[i]=pre[i-1]+dp[i][i],s[i][i]=i;
	for(i=n+1;i<=(n<<1);i++) 
		dp[i][i]=dp[i-n][i-n],pre[i]=pre[i-1]+dp[i][i],s[i][i]=i;
	memset(dp,0,sizeof(dp));
	for(l=2;l<=n;l++){
		for(i=1;i<=(n<<1)-l+1;i++){
			j=i+l-1;dp[i][j]=inf;
			for(k=s[i][j-1];k<=s[i+1][j];k++){
				tmp=dp[i][k]+dp[k+1][j]+pre[j]-pre[i-1];
				if(tmp<dp[i][j]){
					dp[i][j]=tmp;s[i][j]=k;
				}
			}
		}
	}
	for(i=1;i<=n;i++) ans=min(ans,dp[i][i+n-1]);
	printf("%d",ans);
} 
