#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,r[5010],c[5010],dp[5010][5010];
int main(){
	n=read();m=read();int i,j;
	n++;m++;
	for(i=1;i<=n;i++) r[i]=read();
	for(i=1;i<=m;i++) c[i]=read();
	dp[1][1]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			dp[i][j]=1e15;
			if(j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]+r[i]);
			if(i>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+c[j]);
		}
	}
	printf("%lld\n",dp[n][m]);
}
