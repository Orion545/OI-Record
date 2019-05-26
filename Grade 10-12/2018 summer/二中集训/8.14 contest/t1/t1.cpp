#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<vector>
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
int n,m;
int dp[310][310][310];
int x[310],l[310],r[310];
vector<int>q[310];
bool check(int i,int r,int g,int b){
	int tmp;
//	cout<<"	check "<<i<<' '<<r<<' '<<g<<' '<<b<<'\n';
	for(int j=0;j<q[i].size();j++){
		tmp=(l[q[i][j]]<=r)+(l[q[i][j]]<=g)+(l[q[i][j]]<=b);
		if(tmp!=x[q[i][j]]) return 0;
	}
//	cout<<"	pass!\n";
	return 1;
}
void add(int &x,int y){
	x+=y;
	if(x>=MOD) x-=MOD;
} 
int main(){
	n=read();m=read();int i,j,k,lim;
	for(i=1;i<=m;i++){
		l[i]=read();r[i]=read();x[i]=read();
		q[r[i]].push_back(i);
	}
	dp[0][0][0]=1;
	int ans=0;
//	垃圾填表法，刷表法万岁(ノ￣▽￣)
//	for(lim=1;lim<=n;lim++){
//		cout<<"begin "<<lim<<'\n';
//		//red max
//		i=lim;
//		for(j=0;j<lim;j++){
//			for(k=0;k<lim;k++){
//				if((j&&j==k)||(!check(lim,i,j,k))) continue;
//				dp[i][j][k]=dp[i-1][j][k];
//				if(j) dp[i][j][k]+=dp[i][j-1][k];
//				if(k) dp[i][j][k]+=dp[i][j][k-1];
//				dp[i][j][k]%=MOD;
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
//			}
//		}
//		//green max
//		j=lim;
//		for(i=0;i<lim;i++){
//			for(k=0;k<lim;k++){
//				if((i&&i==k)||(!check(lim,i,j,k))) continue;
//				dp[i][j][k]=dp[i][j-1][k];
//				if(i) dp[i][j][k]+=dp[i-1][j][k];
//				if(k) dp[i][j][k]+=dp[i][j][k-1];
//				dp[i][j][k]%=MOD;
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
//			}
//		}
//		//blue max
//		k=lim;
//		for(i=0;i<lim;i++){
//			for(j=0;j<lim;j++){
//				if((j&&j==i)||(!check(lim,i,j,k))) continue;
//				dp[i][j][k]=dp[i][j][k-1];
//				if(i) dp[i][j][k]+=dp[i-1][j][k];
//				if(j) dp[i][j][k]+=dp[i][j-1][k];
//				dp[i][j][k]%=MOD;
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
//			}
//		}
//	}
//	for(i=0;i<n;i++){
//		for(j=0;j<n;j++){
//			ans=(ans+dp[n][i][j]+dp[i][n][j]+dp[i][j][n])%MOD;
//		}
//	}
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=n;k++){
				lim=max(i,max(j,k));
				if(!dp[i][j][k]||!check(lim,i,j,k)){
					dp[i][j][k]=0;continue;
				}
				if(lim==n){
					add(ans,dp[i][j][k]);continue;
				}
//				dp[lim+1][j][k]=(dp[lim+1][j][k]+dp[i][j][k])%MOD;
				add(dp[lim+1][j][k],dp[i][j][k]);
//				dp[i][lim+1][k]=(dp[i][lim+1][k]+dp[i][j][k])%MOD;
				add(dp[i][lim+1][k],dp[i][j][k]);
//				dp[i][j][lim+1]=(dp[i][j][lim+1]+dp[i][j][k])%MOD;
				add(dp[i][j][lim+1],dp[i][j][k]);
			}
		}
	}
	printf("%d\n",ans);
}
