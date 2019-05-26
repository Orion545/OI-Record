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
int n,k,m,p[1010];
ll inv[40010],dp[2][40010][12],now=0;
int main()
{
	n=read();m=read();k=n-1;
	k=n-k+1;
	for(int i=1;i<=n;i++) p[i]=read();
	inv[0]=inv[1]=1;
	for(int i=2;i<=m;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=1;i<=k;i++) dp[now][0][i]=-1;
	for(int i=1;i<=n;i++,now^=1)
		for(int j=0;j<=m;j++){
			for(int x=1;x<=k;x++){
				dp[now^1][j][x]=dp[now][j][x];
				if (j>=p[i]) 
					dp[now^1][j][x]=(dp[now^1][j][x]+dp[now][j-p[i]][x-1]-dp[now][j-p[i]][x]+MOD)%MOD;
			}
		}
	ll ans=0;
	for (int i=1;i<=m;i++) ans=(ans+dp[now][i][k]*m%MOD*inv[i]%MOD+MOD)%MOD;
	printf("%lld",ans);
}
