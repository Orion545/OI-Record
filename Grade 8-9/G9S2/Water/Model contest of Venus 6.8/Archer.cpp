#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,damage,times,money,repair;
int dp[30][110],vis[30][110];
int main(){
	freopen("Archer.in","r",stdin);
	freopen("Archer.out","w",stdout);
	n=read();damage=read();times=read();money=read();repair=read();
	int i,j,flag,limit;
	vis[0][100]=1;
	for(i=1;i<=n;i++){
		flag=((i-1)%times==0)*damage;
		limit=min(100,100-flag+repair);
		for(j=0;j<=limit;j++){
			dp[i][j]=-1;
			if(vis[i-1][j+flag]) 
		 	    dp[i][j]=max(dp[i-1][j+flag]+j*money,dp[i][j]);
			if(vis[i-1][max(0,j+flag-repair)]) 
			    dp[i][j]=max(dp[i-1][max(0,j+flag-repair)],dp[i][j]);
			if(~dp[i][j]) vis[i][j]=1;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	int ans=0;
	for(i=0;i<=100;i++) ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
}

