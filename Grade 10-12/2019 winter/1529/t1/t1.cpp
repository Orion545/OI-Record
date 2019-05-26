#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
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
int n,a[100010],dp[100010][2],pre[100010][2];
vector<int>ans[2];
int main(){
	int T=read(),i,type;
	while(T--){
		n=read();type=2;
		ans[0].clear();ans[1].clear();
		for(i=1;i<=n;i++) a[i]=read();
		dp[1][0]=n+1;
		dp[1][1]=0;
		for(i=2;i<=n;i++){
			dp[i][0]=0;
			dp[i][1]=n+1;
			if(a[i]>a[i-1]) dp[i][0]=dp[i-1][0],pre[i][0]=0;
			if(a[i]<a[i-1]) dp[i][1]=dp[i-1][1],pre[i][1]=0;
			if(a[i]>dp[i-1][1]&&a[i-1]>dp[i][0]) dp[i][0]=a[i-1],pre[i][0]=1;
			if(a[i]<dp[i-1][0]&&a[i-1]<dp[i][1]) dp[i][1]=a[i-1],pre[i][1]=1;
		}
		if(dp[n][0]>0) type=0;
		else if(dp[n][1]<=n) type=1;
		if(type==2){puts("NO");continue;}
		for(i=n;i>=1;i--) ans[type].push_back(a[i]),type^=pre[i][type];
		puts("YES");
		printf("%d",(int)ans[0].size());
		for(i=ans[0].size()-1;i>=0;i--) printf(" %d",ans[0][i]);
		printf("\n%d",(int)ans[1].size());
		for(i=ans[1].size()-1;i>=0;i--) printf(" %d",ans[1][i]);
		puts("");
	}
}
