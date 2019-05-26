#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,m,dp[110][110][110],sum[110][110],ans;
char s[110];bool a[110][110];
int getsum(int l,int r,int u,int d){
//	cout<<"		getsum "<<l<<' '<<r<<' '<<u<<' '<<d<<' '<<sum[r][d]-sum[l-1][d]-sum[r][u-1]+sum[l-1][u-1]<<'\n';
	return sum[d][r]-sum[d][l-1]-sum[u-1][r]+sum[u-1][l-1];
}
int main(){
//	freopen("1.in","r",stdin);
	int l,r,u,d,i,j,liml,limr,limu,limd,edx,edy;
	n=read();m=read();
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			if(s[j]=='o') a[i][j+1]=1;
			if(s[j]=='E') edx=i,edy=j+1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
//			cout<<i<<' '<<j<<' '<<sum[i][j]<<'\n';
		}
	}
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			for(l=0;l<=n;l++){
				dp[i][j][l]=-1e9;
			}
		}
	}
	dp[0][0][0]=0;
//	cout<<"start "<<edx<<' '<<edy<<'\n';
	for(l=0;l<m;l++){
		if(edy-l<=0) break;
		for(r=0;r<m;r++){
			if(edy+r>m) break;
			liml=max(edy-l,1+r);
			limr=min(edy+r,m-l);
			if(liml>limr) continue;
			for(u=0;u<n;u++){
				if(edx-u<=0) break;
				for(d=0;d<n;d++){
					if(edx+d>n) break;
					limu=max(edx-u,1+d);
					limd=min(edx+d,n-u);
					if(limu>limd) continue;
//					cout<<l<<' '<<r<<' '<<u<<' '<<d<<' '<<dp[r][u][d]<<'\n';
//					if(dp[r][u][d]==-1) continue;
					ans=max(ans,dp[r][u][d]);
					if(edy+r+1<=m-l){
//						cout<<"	type 1 "<<l<<' '<<r+1<<' '<<u<<' '<<d<<'\n';
						dp[r+1][u][d]=max(dp[r+1][u][d],dp[r][u][d]+getsum(edy+r+1,edy+r+1,limu,limd));
					}
					if(edx-u-1>=1+d){
//						cout<<"	type 2 "<<l<<' '<<r<<' '<<u+1<<' '<<d<<'\n';
						dp[r][u+1][d]=max(dp[r][u+1][d],dp[r][u][d]+getsum(liml,limr,edx-u-1,edx-u-1));
					} 
					if(edx+d+1<=n-u){
//						cout<<"	type 3 "<<l<<' '<<r<<' '<<u<<' '<<d+1<<'\n';
						dp[r][u][d+1]=max(dp[r][u][d+1],dp[r][u][d]+getsum(liml,limr,edx+d+1,edx+d+1));
					} 
					if(edy-l-1>=1+r){
//						cout<<"	type 4 "<<l+1<<' '<<r<<' '<<u<<' '<<d<<'\n';
						dp[r][u][d]=max(dp[r][u][d],dp[r][u][d]+getsum(edy-l-1,edy-l-1,limu,limd));
					}
				}
			}
		}
	}
	cout<<ans;
}
